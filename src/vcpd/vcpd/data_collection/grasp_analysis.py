from .sim.utils import basic_rot_mat
from .sim.objects import RigidObject, PandaGripper, Rizon4sGripper # TODO: Change this
from scipy.spatial.transform import Rotation
import argparse
import pybullet as p
import numpy as np
import trimesh
import time
import shutil
import json
import os
import rclpy
import rclpy.node

COLLISION_ANGLE_EPSILON = 0.01

def main():

    rclpy.init()
    this_node = rclpy.node.Node('grasp_analysis')

    mesh_path_param_name = 'mesh_path'
    config_file_param_name = 'config'
    output_path_param_name = 'output_path'
    gui_param_name = 'gui'
    verbose_param_name = 'verbose'

    this_node.declare_parameter(mesh_path_param_name, '~/meshes')
    this_node.declare_parameter(config_file_param_name, 'config/config.json')
    this_node.declare_parameter(output_path_param_name, '~/meshes_output')
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
    
    
    mode = p.GUI if gui else p.DIRECT
    physics_id = p.connect(mode)
    p.configureDebugVisualizer(p.COV_ENABLE_GUI, 0)
    p.resetDebugVisualizerCamera(cameraDistance=0.57, cameraYaw=0, cameraPitch=-70, cameraTargetPosition=[0, 0, 0])
    p.setGravity(0, 0, -9.8)
    
    with open(config_file, 'r') as config_file:
        cfg = json.load(config_file)
    
    rg = Rizon4sGripper('/home/artyom/Robotic_Depowdering/src/vcpd/assets')
    obj_list = os.listdir(os.path.join(mesh_path))
    np.random.shuffle(obj_list)
    
    for obj_name in obj_list:
        print("Calculating grasps for:",obj_name)

        obj_path = os.path.join(mesh_path, obj_name, obj_name+'.obj')
        mesh = trimesh.load(obj_path)
        vis_params = {'shapeType': p.GEOM_MESH, 'fileName': obj_path, 'meshScale': [1]*3}
        col_params = {'shapeType': p.GEOM_MESH, 'fileName': obj_path, 'meshScale': [1]*3}
        body_params = {'baseMass': 0, 'basePosition': [0, 0, 0], 'baseOrientation': [0, 0, 0, 1]}
        obj = RigidObject(obj_name, vis_params=vis_params, col_params=col_params, body_params=body_params)
        
        mean_edge_distance = np.mean(np.linalg.norm(mesh.vertices[mesh.edges[:, 0]] - mesh.vertices[mesh.edges[:, 1]], axis=1))
        num_vertices = mesh.vertices.shape[0]
        # vertex index, direction, intersect face index, intersect vertex, center, antipodal raw, mean, min
        grasp_info = {'vertex_ids': [],
                      'x_directions': [],
                      'y_directions': [],
                      'z_directions': [],
                      'centers': [],
                      'widths': [],
                      'quaternions': []}
        
        for i in range(num_vertices):
            vertex, normal = mesh.vertices[i], mesh.vertex_normals[i]
            direction = np.mean(mesh.face_normals[mesh.vertex_faces[i]], axis=0)
            direction = direction / np.linalg.norm(direction)
            normal = normal / np.linalg.norm(normal)
            pa, pb = vertex + normal * 0.2, vertex - normal * 0.2
            
            # line_id = p.addUserDebugLine(pa, pb,
                                        #  lineColorRGB=[0, 0, 1], lineWidth=0.1, lifeTime=0, physicsClientId=physics_id)
            pa, pb = vertex + direction * 0.2, vertex - direction * 0.2
            # line2 = p.addUserDebugLine(pa, pb,
                                    #    lineColorRGB=[0, 1, 0], lineWidth=0.1, lifeTime=0, physicsClientId=physics_id)
            
            vij = mesh.vertices - vertex.reshape(1, 3)  # vectors from i to j
            dist = np.linalg.norm(
                vij - np.sum(vij * normal.reshape(1, 3), axis=1, keepdims=True) * normal.reshape(1, 3), axis=1)
            
            dist[i] = 1e10
            dist[np.dot(mesh.vertex_normals, normal) >= 0] = 1e10
            
            flag = dist <= 2 * mean_edge_distance
            vertex_faces = mesh.vertex_faces[flag]
            vertex_ids = mesh.faces[vertex_faces]
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
                            if np.arccos(np.dot(rot_mat[0:3, 2], np.array([0,0,-1]))) > np.deg2rad(60 + COLLISION_ANGLE_EPSILON):
                                if verbose: print("Grasping at an infeasible orientation, skipping")
                                continue
                            if widths[j] < cfg['gripper']['min_width'] or widths[j] > cfg['gripper']['max_width']:
                                if verbose: print("Infeasible grasp width, skipping")
                                continue
                            lx = p.addUserDebugLine(lineFromXYZ=centers[j], lineToXYZ=centers[j] + rot_mat[0:3, 0], lineColorRGB=[1, 0,1], lifeTime=0)
                            ly = p.addUserDebugLine(lineFromXYZ=centers[j], lineToXYZ=centers[j] + rot_mat[0:3, 1], lineColorRGB=[0, 1,1], lifeTime=0)
                            lz = p.addUserDebugLine(lineFromXYZ=centers[j], lineToXYZ=centers[j] + rot_mat[0:3, 2], lineColorRGB=[1, 1,0], lifeTime=0)
                            # TODO: Place fingers twice, once for approach then for closing.
                            # For now we can assume that during approach the fingers are not too wide to drastically change the gripper geometry
                            # and now cause collisions


                            can_place_fingers = rg.place_fingers(widths[j], centers[j], rot_mat[0:3, 0], rot_mat[0:3, 1], rot_mat[0:3, 2], quat[angle_idx])
                            # rg.set_pose(pos, quat[angle_idx])
                            # rg.set_gripper_width(widths[j] + 0.02) # Why the + 0.02?

                            p.removeUserDebugItem(lx)
                            p.removeUserDebugItem(ly)
                            p.removeUserDebugItem(lz)
                            
                            if (not rg.is_collided([])) and can_place_fingers:
                                if verbose: print("==No Collision, adding to grasp info vector==")
                                feasibles[j] = 1
                                grasp_info['vertex_ids'].append(i)
                                grasp_info['x_directions'].append(rot_mat[0:3, 0])
                                grasp_info['y_directions'].append(rot_mat[0:3, 1])
                                grasp_info['z_directions'].append(rot_mat[0:3, 2])
                                grasp_info['centers'].append(centers[j])
                                grasp_info['widths'].append(widths[j])
                                grasp_info['quaternions'].append(quat[angle_idx])

                        quats[j] = quat[0]

        num_pairs = len(grasp_info['vertex_ids'])
        print('# grasp poses: {}'.format(num_pairs))
        if num_pairs > 0:
            print('First feasible grasp pose is at: ', grasp_info['centers'][0])

        if num_pairs == 0:
            print('No graspable pair found, {} will be removed.'.format(obj_name))
            shutil.rmtree(os.path.join(mesh_path, obj_name))
            continue
        with open(os.path.join(output_path, '{}_info.json'.format(obj_name)), 'w') as f:
            d = {'num_pairs': int(num_pairs),
                 'keys': list(grasp_info.keys())}
            json.dump(d, f, indent=4)
        for k, v in grasp_info.items():
            np.save(os.path.join(output_path, '{}_{}.npy'.format(obj_name, k)), v)
        p.removeBody(obj.obj_id)
        del obj


if __name__ == '__main__':
    main()

