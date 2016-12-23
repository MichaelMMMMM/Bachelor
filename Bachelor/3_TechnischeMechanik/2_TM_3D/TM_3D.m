%20.12.2016, Michael Meindl, Modellbildung 3D-Modell

phi    = sym('phi', [3 1], 'real');
psi    = sym('psi', [3 1], 'real');

phi__d = sym('phi__d', [3 1], 'real');
psi__d = sym('psi__d', [3 1], 'real');

A_P_B = [1, 0, 0; 0, cos(phi(1)), sin(phi(1)); 0, -sin(phi(1)), cos(phi(1))];
B_P_C = [cos(phi(2)), 0, -sin(phi(2)); 0, 1, 0; sin(phi(2)), 0, cos(phi(2))];
C_P_K = [cos(phi(3)), sin(phi(3)), 0; -sin(phi(3)), cos(phi(3)), 0; 0, 0, 1];

A_w_K  = C_P_K*(B_P_C*(A_P_B*[phi__d(1);0;0])) + ...
         C_P_K*(B_P_C*[0;phi__d(2);0]) + ...
         C_P_K*[0;0;phi__d(3)];
A_w_R1 = A_w_K+[psi__d(1);0;0];
A_w_R2 = A_w_K+[0;psi__d(2);0];
A_w_R3 = A_w_K+[0;0;psi__d(3)];

K_c_K  = sym('c_K', [3 1], 'real');
G      = sym('G', 'real');

T_KO_G = cross(K_c_K, (C_P_K*(B_P_C*(A_P_B*[-G;0;0]))));