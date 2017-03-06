%27.02.2017, Michael Meindl, Berechnung des NL-Modells für 3D

close all;

Ta = 0.02;

m      = 1.532;
m_R    = 0.155;
r_1    = [0.5;7.5;7.5]*1e-2;
r_2    = [7.5;0.5;7.5]*1e-2;
r_3    = [7.5;7.5;0.5]*1e-2;
l_C    = 0.066;
c      = [l_C;l_C;l_C]; 
C_psi  = 3.1176e-5;

I_R1M1 = [3.358e-4, 0, 0; 0, 1.961e-4, 0; 0, 0, 1.681e-4];
I_R2M2 = [1.691e-4, 0, 0; 0, 3.358e-4, 0; 0, 0, 1.961e-4];
I_R3M3 = [1.961e-4, 0, 0; 0, 1.691e-4, 0; 0, 0, 3.358e-4];

I_GHO  = [1.520e-2, -5.201e-3, 5.375e-3; 
          -5.201e-3, 1.52e-2, 5.225e-3;
          5.375e-3, 5.225e-3, 1.542e-2];
I_KO   = I_GHO + m_R*(eye(3)*dot(r_1,r_1)-r_1*r_1') ...
               + m_R*(eye(3)*dot(r_2,r_2)-r_2*r_2') ...
               + m_R*(eye(3)*dot(r_3,r_3)-r_3*r_3');
           
I_K    = I_KO+[I_R2M2(1,1)+I_R3M3(1,1), 0, 0;
               0, I_R1M1(2,2)+I_R3M3(2,2), 0;
               0, 0, I_R1M1(3,3)+I_R2M2(3,3)];
I_R    = [I_R1M1(1,1), 0, 0; 0, I_R2M2(2,2), 0; 0, 0, I_R3M3(3,3)];

I_K_inv = inv(I_K);
I_R_inv = inv(I_R);

K = [ 0.0361, 1.0652, -1.1013, -0.6746, 0.3836, 0.1820, -0.0015, -0.0001, -0.0001;
      -1.0521, -0.0211, 1.0731, 0.3345,-0.6323, 0.1809, -0.0008, -0.0009, -0.0002;
      0.6308, -0.6214, -0.0094, 0.1351, 0.2078,-0.2110, 0.0004, 0.0013, 0.0009];

phi    = sym('phi', [3 1], 'real');
A_P_B = [1, 0, 0; 0, cos(phi(1)), sin(phi(1)); 0, -sin(phi(1)), cos(phi(1))];
B_P_C = [cos(phi(2)), 0, -sin(phi(2)); 0, 1, 0; sin(phi(2)), 0, cos(phi(2))];
C_P_K = [cos(phi(3)), sin(phi(3)), 0; -sin(phi(3)), cos(phi(3)), 0; 0, 0, 1];

A_P_K = C_P_K*(B_P_C*A_P_B);
K_P_A = A_P_K';

phi_30_0 = degtorad(-7:1:7);
it       = length(phi_30_0);
x_g      = cell(it, 1);
x_ur     = cell(it, 1);
x_uk     = cell(it, 1);
u        = cell(it, 1);
u_c      = cell(it, 1);
t_x      = cell(it, 1);
t_u      = cell(it, 1);

stop_time = 3;
filter_select = 1;
dead_time = 0.001;
T_comp = 2;

phi_10 = 0;
phi_20 = -2*atan(sqrt(2)-sqrt(3));
phi_30 = -pi/4;

NL_3D_Model_u_unlimited;
NL_3D_Model_u_limited;
NL_3D_Model_u_limited_x_offset;
NL_3D_Model_u_limited_x_noise;