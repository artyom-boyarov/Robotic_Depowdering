import numpy as np
import scipy.linalg

def hat(v: np.ndarray):
    return np.array([[0, -v[2], v[1]], [v[2], 0, -v[0]], [-v[1], v[0], 0]])

# Returns grasp matrix G
def get_G(com,  contact1rot, contact1pos, contact2rot, contact2pos):
    P1 = np.zeros((6, 6))
    P1[0:3, 0:3] = np.eye(3)
    P1[3:6, 0:3] = hat(contact1pos - com)
    P1[3:6, 3:6] = np.eye(3)

    Rhat1 = scipy.linalg.block_diag(contact1rot, contact1rot)
    G_tilda_1 = ((Rhat1.T) @ (P1.T)).T

    P2 = np.zeros((6, 6))
    P2[0:3, 0:3] = np.eye(3)
    P2[3:6, 0:3] = hat(contact2pos - com)
    P2[3:6, 3:6] = np.eye(3)

    Rhat2 = scipy.linalg.block_diag(contact2rot, contact2rot)
    G_tilda_2 = ((Rhat2.T) @ (P2.T)).T

    G_tilda = np.hstack((G_tilda_1, G_tilda_2))

    # Soft finger model for H matrix
    H1 = np.zeros((4, 6))
    H1[0:3, 0:3] = np.eye(3)
    H1[3, 3] = 1

    H2 = H1

    H = scipy.linalg.block_diag(H1, H2)

    G = (H @ (G_tilda.T)).T
    return G

    


# Finds minimum singular value of grasp matrix G
# The larger this is the less like the grasp to fall into a  singular configuration
def min_singular_value_G(com, contact1rot, contact1pos, contact2rot, contact2pos):
    G = get_G(com, contact1rot, contact1pos, contact2rot, contact2pos)
    singular_values = scipy.linalg.svdvals(G @ (G.T))
    return np.min(singular_values)

# Finds volume of ellipsoid in wrench space
# The larger the value the better the grasp
def vol_ellipsoid_in_wrench(com, contact1rot, contact1pos, contact2rot, contact2pos):
    G = get_G(com, contact1rot, contact1pos, contact2rot, contact2pos)
    return np.sqrt(scipy.linalg.det(G @ (G.T)))


if __name__ == "__main__":
    min_sing_val = min_singular_value_G(
        np.array([0,0,0]), 
        np.array([[0,1,0], [0,0,1], [1,0,0]]),
        np.array([0,-2,0]).T,
        np.array([[1,0,0], [0,0,-1], [0,1,0]]),
        np.array([0,2,0]).T
    )