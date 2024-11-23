#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# sudo apt install python3-petsc4py python3-dolfinx
"""
Created on Tue Nov  5 15:34:12 2024

@author: alexmbcm
"""


# Meshing libraries
import pygalmesh
import meshio


# Fenicsx FEA libraries
from petsc4py import PETSc
from mpi4py import MPI
import ufl
from dolfinx import mesh, fem, default_scalar_type, io
from dolfinx.fem.petsc import assemble_matrix, assemble_vector, apply_lifting, set_bc #,create_vector
import basix


# Timing
import time


# Common libraries
import numpy as np


np.set_printoptions(formatter={'float': lambda x: format(x, '6.3E')})





## LOAD STL AND MAKE VOLUMETRIC MESH
###############################################################################

# Check initial stl mesh
stl_mesh = meshio.read("Rounded_U.stl")
print(stl_mesh)
print('\n')



# Get new resampled surface mesh and its volume mesh
t0 = time.time()
pygalmesh_vol_mesh = pygalmesh.generate_volume_mesh_from_surface_mesh(
    "Rounded_U.stl",
    min_facet_angle=25.0,
    max_radius_surface_delaunay_ball=0.002,
    max_facet_distance=0.0004,
    max_circumradius_edge_ratio=1.2,
    verbose=False,
)
t1 = time.time()

print(pygalmesh_vol_mesh)
print('\n')






## MAKE FEA MESH AND EXPORT SURFACE MESH
###############################################################################

# Import nodes and connectivity matrix into Fenics domain and mesh objects
points = pygalmesh_vol_mesh.points
cells  = pygalmesh_vol_mesh.cells[1].data

finiteElement = basix.ufl.element("Lagrange", "tetrahedron", 1, shape=(3, ))

domain = mesh.create_mesh(MPI.COMM_WORLD, cells, points, finiteElement)


# Export mesh
# Find facets on boundary
fdim = domain.topology.dim - 1
domain.topology.create_connectivity(fdim, fdim+1)
free_end_facets = mesh.exterior_facet_indices(domain.topology)

# Connectivity between nodes and boundary facets
free_end_connectivity = mesh.entities_to_geometry(domain, fdim, free_end_facets)

# Get only unique nodes
free_end_nodes = np.unique(free_end_connectivity.reshape(-1))

# Extract coordinates of nodes associated with the surface facets
free_end_coords = domain.geometry.x[free_end_nodes]


# Change connectivity numbering to match order from 0 of extracted nodes
connectivity_copy = np.copy(free_end_connectivity)

for n in np.arange(free_end_nodes.size):
    free_end_connectivity[connectivity_copy == free_end_nodes[n]] = n


meshio.write_points_cells("fenics_surf_mesh.obj", free_end_coords, {'triangle': free_end_connectivity})






## GRASPING CODE TO PICK FACETS AND NODES IN SURFACE MESH SHOULD GO HERE
###############################################################################





## FENICS SIMULATIONS BASED ON ARRAYS WITH NODES AND CORRESPONDING FACETS FROM GRASPING CODE
###############################################################################

grasp_facet_nums = np.array([234, 2386, 352, 2044, 923, 2078])

grasp_node_nums  = np.array([50, 200, 200, 400, 500, 1050])

grasp_node_normals = np.array([[ 1.0, 0.0, 0.0],
                               [ 0.0, 1.0, 0.0],
                               [ 0.0, 1.0, 0.0],
                               [-0.08343754, 0.99600488, -0.03182245],
                               [-1.0, 0.0, 0.0],
                               [ 0.0, 1.0, 0.0]])


# Change facet and node numbering back to Fenics numbering
grasp_facet_nums = free_end_facets[grasp_facet_nums]
grasp_node_nums  = free_end_nodes[grasp_node_nums]


# Check node numbering is correct 
print(domain.geometry.x[grasp_node_nums])
print('\n')



E  = 3.5e9
nu = 0.35

lambda_ = E * nu / ((1.0 + nu) * (1 - 2.0*nu))
mu      = 0.5 * E / (1.0 + nu)




V = fem.functionspace(domain, ("Lagrange", 1, (domain.geometry.dim, )))

fdim = domain.topology.dim - 1

u_D = np.array([0, 0, 0], dtype=default_scalar_type)

T = fem.Constant(domain, default_scalar_type((0, 0, 0)))

ds = ufl.Measure("ds", domain=domain)


def epsilon(u):
    return ufl.sym(ufl.grad(u)) # Equivalent to 0.5*(ufl.nabla_grad(u) + ufl.nabla_grad(u).T)

def sigma(u):
    return lambda_ * ufl.nabla_div(u) * ufl.Identity(len(u)) + 2 * mu * epsilon(u)


u = ufl.TrialFunction(V)
v = ufl.TestFunction(V)
a = ufl.inner(sigma(u), epsilon(v)) * ufl.dx

L = ufl.dot(T, v) * ds


## Solution setup

a_compiled = fem.form(a)
L_compiled = fem.form(L)


# Create solution function
uh = fem.Function(V)


# Solver
solver = PETSc.KSP().create(domain.comm)
solver.setType(PETSc.KSP.Type.PREONLY)
solver.getPC().setType(PETSc.PC.Type.LU)



# Store maximum displacements here
max_displacement = np.empty(grasp_facet_nums.size)

t2 = time.time()
for n in np.arange(grasp_facet_nums.size):
    boundary_facets = np.array([grasp_facet_nums[n]])
    
    bc = fem.dirichletbc(u_D, fem.locate_dofs_topological(V, fdim, boundary_facets), V)
    
    # Assemble system, applying boundary conditions
    A = assemble_matrix(a_compiled, bcs=[bc])
    A.assemble()
    
    b = assemble_vector(L_compiled)
    apply_lifting(b, [a_compiled], bcs=[[bc]])
    b.ghostUpdate(addv=PETSc.InsertMode.ADD, mode=PETSc.ScatterMode.REVERSE)
    set_bc(b, [bc])
    
    global_node = grasp_node_nums[n]
    b.setValue(3*global_node,   -grasp_node_normals[n,0])
    b.setValue(3*global_node+1, -grasp_node_normals[n,1])
    b.setValue(3*global_node+2, -grasp_node_normals[n,2])
    
  
    
    # Solver
    solver.setOperators(A)
    
    
    # Compute solution
    solver.solve(b, uh.x.petsc_vec)
    
    
    #Store max displacement from solution
    max_displacement[n] = np.max(np.linalg.norm(np.reshape(uh.x.array, (-1,3)), axis=1))

   
    
    with io.XDMFFile(domain.comm, "deformation" + str(n) + ".xdmf", "w") as xdmf:
        xdmf.write_mesh(domain)
        uh.name = "Deformation"
        xdmf.write_function(uh)

t3 = time.time()

print(max_displacement)
print('\n')

print("Remeshing time:", t1-t0, "seconds\n")
print("Total FEA time:", t3-t2, "seconds")














