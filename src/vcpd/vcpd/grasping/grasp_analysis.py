from .sim.utils import basic_rot_mat
from .sim.objects import RigidObject, Rizon4sGripper
from scipy.spatial.transform import Rotation
import pybullet as p
import numpy as np
import trimesh
import shutil
import json
import os
import rclpy
import rclpy.node
from robotic_depowdering_interfaces.srv import VCPDGrasp
from geometry_msgs.msg import Point, Vector3
from . import grasp_evaluation as grasp_eval
from . import fenics_grasp_calc as fea
from ament_index_python.packages import get_package_share_directory
from .constants import ROBOTIC_DEPOWDERING_TMP_DIR, COLLISION_ANGLE_EPSILON
import pyvista
import time

DISPLACEMENT_THRESHOLD = 0.00001
def numpy_arr_to_vec3(vec: np.ndarray) -> Vector3:
    output_vec = Vector3()
    output_vec.x = vec[0]
    output_vec.y = vec[1]
    output_vec.z = vec[2]
    return output_vec


def numpy_arr_to_point(vec: np.ndarray) -> Point:
    output_point = Point()
    output_point.x = vec[0]
    output_point.y = vec[1]
    output_point.z = vec[2]
    return output_point
    

def find_grasp(gui: bool, verbose: bool, obj_name: str, mesh_path: str) -> VCPDGrasp.Response:
    t_start = time.time()
    
    mode = p.GUI if gui else p.DIRECT
    physics_id = p.connect(mode)
    p.configureDebugVisualizer(p.COV_ENABLE_GUI, 0, rgbBackground=[1,1,1])
    p.resetDebugVisualizerCamera(cameraDistance=0.57, cameraYaw=0, cameraPitch=-70, cameraTargetPosition=[0, 0, 0])
    p.setGravity(0, 0, -9.8)

    fea_tester = fea.FEAGraspTester()
    
    vcpd_package_share_dir = get_package_share_directory('vcpd')
    robotic_depowdering_package_share_dir = get_package_share_directory('robotic_depowdering')

    LOGGER_NAME = 'grasp_analysis'

    with open(os.path.join(vcpd_package_share_dir, 'cfg', 'config.json'), 'r') as config_file:
        cfg = json.load(config_file)
    
    floor_obj_path = os.path.join(vcpd_package_share_dir, 'assets', 'Floor.obj')
    floor_id = p.createMultiBody(
        baseCollisionShapeIndex=p.createCollisionShape(
            shapeType=p.GEOM_MESH, 
            fileName=floor_obj_path,
            meshScale=[100]*3
        ),
        baseVisualShapeIndex=p.createVisualShape(shapeType=p.GEOM_MESH, 
            fileName=floor_obj_path,
            meshScale=[100]*3
        ),
        baseMass = 0,
        basePosition = [0,0,0],
        baseOrientation = [0,0,0,1]
    )
    p.changeVisualShape(floor_id, -1, rgbaColor=[0.9, 0.9, 0.9, 1])
    
    x_axis = p.addUserDebugLine(lineFromXYZ=[0,0,0], lineToXYZ=[0.2,0,0], lineColorRGB=[1, 0,0], lifeTime=0, lineWidth=4.0)
    y_axis = p.addUserDebugLine(lineFromXYZ=[0,0,0], lineToXYZ=[0,0.2,0], lineColorRGB=[1, 1,0], lifeTime=0, lineWidth=4.0)
    z_axis = p.addUserDebugLine(lineFromXYZ=[0,0,0], lineToXYZ=[0,0,0.2], lineColorRGB=[0, 1,0], lifeTime=0, lineWidth=4.0)
    
    fea_tester.re_mesh_object(obj_name, robotic_depowdering_package_share_dir + "/test_parts/",
                              robotic_depowdering_package_share_dir + "/remeshed_test_parts/")

    # TODO: When we get the updated flexiv library, get this to point to the
    # meshes in robotic_depowdering
    rg = Rizon4sGripper(os.path.join(vcpd_package_share_dir, 'assets'))
    
    rclpy.node.get_logger(LOGGER_NAME).info("Calculating grasps for: %s " % (obj_name))


    obj_path = os.path.join(robotic_depowdering_package_share_dir, "remeshed_test_parts", obj_name+'.fenics_surf_mesh.obj')

    mesh = pyvista.read(obj_path)
    mesh.compute_normals(inplace=True, auto_orient_normals=True)
    mesh.save(obj_path)

    mesh = trimesh.load(obj_path)
    # mesh.rezero()
    np.savetxt("round_U_surface_normals.csv", mesh.vertex_normals, delimiter=',')
    vis_params = {'shapeType': p.GEOM_MESH, 'fileName': obj_path, 'meshScale': [1]*3}
    col_params = {'shapeType': p.GEOM_MESH, 'fileName': obj_path, 'meshScale': [1]*3}
    body_params = {'baseMass': 1, 'basePosition': [0, 0, 0], 'baseOrientation': [0, 0, 0, 1]}
    obj = RigidObject(obj_name, vis_params=vis_params, col_params=col_params, body_params=body_params, color=[1.0, 1.0, 0.0, 1.0])


    obj_center_of_mass = np.array(mesh.center_mass)
    OBJ_DENSITY = 1
    obj_mass = mesh.convex_hull.volume * OBJ_DENSITY

    rclpy.node.get_logger(LOGGER_NAME).info('%s has center of mass at <%f, %f, %f>' %
                                                (obj_name,
                                                obj_center_of_mass[0],
                                                obj_center_of_mass[1],
                                                obj_center_of_mass[2]))
    
    mean_edge_distance = np.mean(np.linalg.norm(mesh.vertices[mesh.edges[:, 0]] - mesh.vertices[mesh.edges[:, 1]], axis=1))
    num_vertices = mesh.vertices.shape[0]

    grasp_info = {'vertex_ids': [],
                    'x_directions': [],
                    'y_directions': [],
                    'z_directions': [],
                    'centers': [],
                    'base_pos': [],
                    'widths': [],
                    'quaternions': [],
                    'minimum_force': [],
                    'dist_to_com': [],
                    'displacement': []}
    rclpy.node.get_logger(LOGGER_NAME).info('%s has %d vertices in the mesh' % (obj_name, num_vertices))
    prev_vertex = mesh.vertices[0]
    for i in range(0, num_vertices, 20):
        vertex, normal = mesh.vertices[i], mesh.vertex_normals[i]
        # print("Norm: ",np.linalg.norm(vertex - prev_vertex))
        # if np.linalg.norm(vertex - prev_vertex) < 0.015: continue # Skip vertices too close
        prev_vertex = vertex
        direction = np.mean(mesh.face_normals[mesh.vertex_faces[i]], axis=0)
        direction = direction / np.linalg.norm(direction)
        normal = normal / np.linalg.norm(normal)

        vij = mesh.vertices - vertex.reshape(1, 3)  # vectors from i to j
        dist = np.linalg.norm(
            vij - np.sum(vij * normal.reshape(1, 3), axis=1, keepdims=True) * normal.reshape(1, 3), axis=1)
        
        dist[i] = 1e10
        dist[np.dot(mesh.vertex_normals, normal) >= 0] = 1e10
        
        flag = dist <= 2 * mean_edge_distance
        vertex_faces = mesh.vertex_faces[flag]
        # print("Vertex faces", vertex_faces)
        vertex_ids = mesh.faces[vertex_faces]
        # print("Vertex ids", vertex_ids)
        # visualize vertices
        # spheres = []
        # p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 0)
        # for vertex_idx in vertex_ids.reshape(-1):
        #     spheres.append(p.createMultiBody(0, p.createCollisionShape(p.GEOM_SPHERE, 0.001),
        #                                      p.createVisualShape(p.GEOM_SPHERE, 0.001),
        #                                      basePosition=mesh.vertices[vertex_idx]))
        # p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 0)
        # [p.removeBody(sphere_id) for sphere_id in spheres]
        # p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 1)
        # shape of vertex_coords: num_candidates * max_adjacent_faces * num_vertices_per_triangle * num_coords
        vertex_coords = mesh.vertices[vertex_ids]  # triangle vertices
        # https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
        
        p0, p1, p2 = [np.squeeze(arr, axis=2) for arr in np.split(vertex_coords, 3, axis=2)]
        la = vertex.reshape(1, 1, 3)
        lab = normal.reshape(1, 1, 3)
        p01 = p1 - p0
        p02 = p2 - p0
        
        denominator = np.sum(-lab * np.cross(p01, p02), axis=2)
        denominator[denominator == 0] = 1e-7
        
        t = np.sum(np.cross(p01, -p02) * (la - p0), axis=2) / denominator
        u = np.sum(np.cross(p02, -lab) * (la - p0), axis=2) / denominator
        v = np.sum(np.cross(-lab, p01) * (la - p0), axis=2) / denominator
        
        intersects = la - lab * np.expand_dims(t, axis=-1)
        intersect_flag = (u >= 0) * (u <= 1) * (v >= 0) * (v <= 1) * ((u + v) >= 0) * ((u + v) <= 1)
        
        if np.any(intersect_flag):
            selected_faces, selected_ids = np.unique(vertex_faces[intersect_flag], return_index=True)
            selected_intersects = intersects[intersect_flag][selected_ids]
            selected_ids = np.unique(np.sum(selected_intersects*1e4, axis=1).astype(int), return_index=True)[1]
            
            selected_faces, selected_intersects = selected_faces[selected_ids], selected_intersects[selected_ids]
            num_intersects = selected_intersects.shape[0]
            widths = np.linalg.norm((vertex.reshape(1, 3) - selected_intersects), axis=1)
            # width_flag = widths < max_width
            # selected_faces = selected_faces[width_flag]
            # selected_intersects = selected_intersects[width_flag]
            # widths = widths[width_flag]
            centers = (vertex.reshape(1, 3) + selected_intersects) / 2
            face_normals = mesh.face_normals[selected_faces]
            face_vertex_normals = mesh.vertex_normals[mesh.faces[selected_faces]]
            cos1s = np.abs(np.sum(face_vertex_normals * normal.reshape(1, 1, 3), axis=-1))
            vertex_face_ids = mesh.vertex_faces[i][mesh.vertex_faces[i] != -1]
            vertex_face_normals = mesh.face_normals[vertex_face_ids]
            cos2s = np.abs(np.dot(vertex_face_normals, normal))
            mean_cos1, min_cos1 = np.mean(cos1s, axis=1), np.min(cos1s, axis=1)
            mean_cos2, min_cos2 = np.mean(cos2s), np.min(cos2s)
            mean_score, min_score = mean_cos1 * mean_cos2, min_cos1 * min_cos2
            raw = np.abs(np.dot(face_normals, normal))
            # print('original antipodal score: {}'.format(raw))
            # print('mean cos1: {} | mean cos2: {} | mean antipodal score: {}'.format(mean_cos1, mean_cos2, mean_score))
            # print('min cos1: {} | min cos2: {} | min antipodal score: {}'.format(min_cos1, min_cos2, min_score))
            # vertex index, direction, intersect face index, intersect vertex, center, antipodal raw, mean, min
            curr_idx = np.array([i] * num_intersects)
            directions = np.stack([normal] * num_intersects, axis=0)
            cols = np.ones((num_intersects, cfg['num_angle']))
            quats = np.zeros((num_intersects, 4))
            quats[..., -1] = 1
            feasibles = np.zeros((num_intersects, cfg['num_angle']))
            for j in range(num_intersects):
                if min_score[j] >= cfg['th_min']:
                    y = directions[j]
                    mat, _, _ = np.linalg.svd(y.reshape(3, 1))
                    x = mat[:, 1]
                    z = np.cross(x, y)
                    base = np.stack([x, y, z], axis=1)
                    angles = np.arange(cfg['num_angle']) / cfg['num_angle'] * np.pi * 2
                    delta_rots = basic_rot_mat(angles, axis='y')
                    rots = np.matmul(base.reshape((1, 3, 3)), delta_rots)
                    quat = Rotation.from_matrix(rots).as_quat()
                    if np.sum(np.sum(np.abs(quat), axis=1) == 0) > 0:
                        print(1)
                        pass
                    for angle_idx in range(cfg['num_angle']):
                        rot_mat = Rotation.from_quat(quat[angle_idx]).as_matrix()
                        # X = purple
                        # Y = cyan
                        # Z = yellow
                        if np.arccos(np.clip(np.dot(rot_mat[0:3, 2], np.array([0,0,-1])), -1, 1)) > np.deg2rad(60 + COLLISION_ANGLE_EPSILON):
                            if verbose: rclpy.node.get_logger(LOGGER_NAME).info("Grasping at an infeasible orientation, skipping")
                            continue
                        if widths[j] < cfg['gripper']['min_width'] or widths[j] > cfg['gripper']['max_width']:
                            if verbose: rclpy.node.get_logger(LOGGER_NAME).info("Infeasible grasp width, skipping")
                            continue
                        lx = p.addUserDebugLine(lineFromXYZ=centers[j], lineToXYZ=centers[j] + rot_mat[0:3, 0], lineColorRGB=[1, 0,1], lifeTime=0)
                        ly = p.addUserDebugLine(lineFromXYZ=centers[j], lineToXYZ=centers[j] + rot_mat[0:3, 1], lineColorRGB=[0, 1,1], lifeTime=0)
                        lz = p.addUserDebugLine(lineFromXYZ=centers[j], lineToXYZ=centers[j] + rot_mat[0:3, 2], lineColorRGB=[1, 1,0], lifeTime=0)

                        grasp_geometry = rg.place_fingers(widths[j], centers[j], rot_mat[0:3, 0], rot_mat[0:3, 1], rot_mat[0:3, 2], quat[angle_idx])
                        
                        grasp_geometry.com = obj_center_of_mass                        
                        p.removeUserDebugItem(lx)
                        p.removeUserDebugItem(ly)
                        p.removeUserDebugItem(lz)

                        

                        if not grasp_geometry.found: continue
                        is_force_closure = grasp_eval.is_force_closure(grasp_geometry)
                        displacement = fea_tester.find_grasp_displacement(np.array([selected_faces[j]]), np.array([i]), np.array([mesh.vertex_normals[i]]) )
                            
                        if (not rg.is_collided([])) and \
                            grasp_geometry.found and is_force_closure and displacement < DISPLACEMENT_THRESHOLD:
                            if verbose: rclpy.node.get_logger(LOGGER_NAME).info("==No Collision, can place fingers, and is force closure: adding to grasp info vector==")
                            feasibles[j] = 1

                            # print("Vertex no.:", i)
                            # print("Vertex:", vertex)
                            # print("Vertex normal:", mesh.vertex_normals[i])
                            # print("Face no.: ",selected_faces[j])
                            # print("Width:", widths[j])
                            # x = input()
                            grasp_info['vertex_ids'].append(i)
                            grasp_info['x_directions'].append(rot_mat[0:3, 0])
                            grasp_info['y_directions'].append(rot_mat[0:3, 1])
                            grasp_info['z_directions'].append(rot_mat[0:3, 2])
                            grasp_info['base_pos'].append(grasp_geometry.base_pos)
                            grasp_info['centers'].append(centers[j])
                            grasp_info['widths'].append(widths[j])
                            grasp_info['quaternions'].append(quat[angle_idx])
                            # Friction coefficient can be between 0.05 to 0.75
                            # Object mass of 100g
                            grasp_info['minimum_force'].append(grasp_eval.get_minimum_force_friction(rot_mat[0:3, 1], 0.75, obj_mass))
                            grasp_info['dist_to_com'].append(np.linalg.norm(centers[j] - obj_center_of_mass))

                            grasp_info['displacement'].append(displacement)
                            # print(displacement[0])

                    quats[j] = quat[0]

    num_pairs = len(grasp_info['vertex_ids'])
    rclpy.node.get_logger(LOGGER_NAME).info('Found %d grasp poses for %s' % (num_pairs, obj_name))

    del obj

    grasp = VCPDGrasp.Response()
    if num_pairs == 0:
        rclpy.node.get_logger(LOGGER_NAME).error('No graspable pair found for %s will be removed.' % (obj_name))
        grasp.found_grasp = False
        shutil.rmtree(os.path.join(mesh_path, obj_name))
        return grasp

    # print('Safest by displacement')
    # safest_grasp = np.argmin(grasp_info['displacement'])
    # grasp.found_grasp = True
    # grasp.axis = numpy_arr_to_vec3(grasp_info['x_directions'][safest_grasp])
    # grasp.binormal = numpy_arr_to_vec3(grasp_info['y_directions'][safest_grasp])
    # grasp.approach = numpy_arr_to_vec3(grasp_info['z_directions'][safest_grasp])
    # grasp.position = numpy_arr_to_point(grasp_info['base_pos'][safest_grasp])
    # grasp.width = grasp_info['widths'][safest_grasp]
    # grasp.force = (grasp_info['minimum_force'][safest_grasp]) * 1.2 # 20% leniency

    # rclpy.node.get_logger(LOGGER_NAME).info("Returning grasp for %s with base position at <%f, %f, %f> and width %f" %
    #     (obj_name, grasp.position.x, grasp.position.y, grasp.position.z, grasp.width))
    
    # rg.place_fingers(
    #     grasp_info['widths'][safest_grasp], 
    #     grasp_info['centers'][safest_grasp], 
    #     grasp_info['x_directions'][safest_grasp], 
    #     grasp_info['y_directions'][safest_grasp], 
    #     grasp_info['z_directions'][safest_grasp], 
    #     grasp_info['quaternions'][safest_grasp]
    # )

    # x = input()
    # Do threshold + COM
    print('Safest by distance to COM')
    safest_grasp = np.argmin(grasp_info['dist_to_com'])
    grasp.found_grasp = True
    grasp.axis = numpy_arr_to_vec3(grasp_info['x_directions'][safest_grasp])
    grasp.binormal = numpy_arr_to_vec3(grasp_info['y_directions'][safest_grasp])
    grasp.approach = numpy_arr_to_vec3(grasp_info['z_directions'][safest_grasp])
    grasp.position = numpy_arr_to_point(grasp_info['base_pos'][safest_grasp])
    grasp.width = grasp_info['widths'][safest_grasp]
    grasp.force = (grasp_info['minimum_force'][safest_grasp]) * 1.2 # 20% leniency

    rclpy.node.get_logger(LOGGER_NAME).info("Returning grasp for %s with base position at <%f, %f, %f> and width %f" %
        (obj_name, grasp.position.x, grasp.position.y, grasp.position.z, grasp.width))
    
    rg.place_fingers(
        grasp_info['widths'][safest_grasp], 
        grasp_info['centers'][safest_grasp], 
        grasp_info['x_directions'][safest_grasp], 
        grasp_info['y_directions'][safest_grasp], 
        grasp_info['z_directions'][safest_grasp], 
        grasp_info['quaternions'][safest_grasp]
    )
    t_end = time.time()
    total_time = t_end - t_start
    rclpy.node.get_logger(LOGGER_NAME).info('Time taken to generate %d grasps: %f' % (num_pairs, total_time))
    rclpy.node.get_logger(LOGGER_NAME).info('Time taken per grasp: %f' % (total_time /  num_pairs))

    return grasp

def main():

    rclpy.init()
    this_node = rclpy.node.Node('grasp_analysis')

    mesh_path_param_name = 'mesh_path'
    config_file_param_name = 'config'
    output_path_param_name = 'output_path'
    gui_param_name = 'gui'
    verbose_param_name = 'verbose'

    vcpd_package_share_directory = get_package_share_directory('vcpd')

    this_node.declare_parameter(mesh_path_param_name, ROBOTIC_DEPOWDERING_TMP_DIR + 'meshes_output')
    this_node.declare_parameter(config_file_param_name, vcpd_package_share_directory + '/cfg/config.json')
    this_node.declare_parameter(output_path_param_name, ROBOTIC_DEPOWDERING_TMP_DIR + 'meshes_grasp_output')
    this_node.declare_parameter(gui_param_name, False)
    this_node.declare_parameter(verbose_param_name, False)

    mesh_path = this_node.get_parameter(mesh_path_param_name).get_parameter_value().string_value
    config_file = this_node.get_parameter(config_file_param_name).get_parameter_value().string_value
    output_path = this_node.get_parameter(output_path_param_name).get_parameter_value().string_value
    gui = this_node.get_parameter(gui_param_name).get_parameter_value().bool_value
    verbose = this_node.get_parameter(verbose_param_name).get_parameter_value().bool_value

    if not os.path.exists(mesh_path):
        os.makedirs(mesh_path)
    if not os.path.exists(output_path):
        os.makedirs(output_path)
    
    
    


if __name__ == '__main__':
    main()

