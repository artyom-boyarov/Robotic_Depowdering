function S = hat_v(v)
    S = [0, -v(3), v(2); v(3), 0, -v(1); -v(2), v(1), 0];
end

% Springer handbook of robotics technique applied to Berkeley example
syms r;
r = 1;
Rc1 = [0,1,0; 0,0,1; 1,0,0];
Pc1 = [0; -r; 0];
Rc2 = [1,0,0; 0,0,1; 0,-1,0];
Pc2 = [0;r;0];

P1 = [eye(3), zeros(3, 3); hat_v(Pc1), eye(3)];
Rhat1 = blkdiag(Rc1, Rc1);
G_tilda_1 = ((Rhat1)' * (P1)')'

P2 = [eye(3), zeros(3, 3); hat_v(Pc2), eye(3)];
Rhat2 = blkdiag(Rc2, Rc2);
G_tilda_2 = ((Rhat2)' * (P2)')'

% G_tilda is 6x6nc
G_tilda = [G_tilda_1 G_tilda_2]

% Soft finger model for H matrix
H1 = [eye(3), zeros(3); zeros(1, 3), 1, 0, 0];
H2 = H1;
H = blkdiag(H1, H2);

G = (H* (G_tilda)')'


%% Grasp matrix analysis

%% Minimum singular value of G
GGTeig = eig(G*(G'))
sqrt(GGTeig)
