%20.12.2016, Michael Meindl, Modellbildung 3D-Modell

phi    = sym('phi', [3 1], 'real');
psi    = sym('psi', [3 1], 'real');

phi__d = sym('phi__d', [3 1], 'real');
psi__d = sym('psi__d', [3 1], 'real');

A_P_B = [1, 0, 0; 0, cos(phi(1)), sin(phi(1)); 0, -sin(phi(1)), cos(phi(1))];
B_P_C = [cos(phi(2)), 0, -sin(phi(2)); 0, 1, 0; sin(phi(2)), 0, cos(phi(2))];
C_P_K = [cos(phi(3)), sin(phi(3)), 0; -sin(phi(3)), cos(phi(3)), 0; 0, 0, 1];

A_P_K = C_P_K*(B_P_C*A_P_B);
K_P_A = A_P_K';

A_w_K  = C_P_K*(B_P_C*(A_P_B*[phi__d(1);0;0])) + ...
         C_P_K*(B_P_C*[0;phi__d(2);0]) + ...
         C_P_K*[0;0;phi__d(3)];
A_w_R1 = A_w_K+[psi__d(1);0;0];
A_w_R2 = A_w_K+[0;psi__d(2);0];
A_w_R3 = A_w_K+[0;0;psi__d(3)];

K_c_K  = sym('c_K', [3 1], 'real');
G      = sym('G', 'real');

T_KO_G = cross(K_c_K, (C_P_K*(B_P_C*(A_P_B*[-G;0;0]))));

I_KO   = sym('I_KO_', [3 3], 'real');
I_R1M1 = sym('I_R1M1_', [3 3], 'real');
I_R2M2 = sym('I_R2M2_', [3 3], 'real');
I_R3M3 = sym('I_R3M3_', [3 3], 'real');
m_R    = sym('m_R_', [3 1], 'real');
r1     = sym('r1_', [3 1], 'real');
r2     = sym('r2_', [3 1], 'real');
r3     = sym('r3_', [3 1], 'real');

u      = sym('u', [6 1], 'real');
u__d   = sym('u__d', [6 1], 'real');

A_w_K  = [u(1); u(2); u(3)];
A_w_R1 = [u(1)+u(4); u(2); u(3)];
A_w_R2 = [u(1); u(2)+u(5); u(3)];
A_w_R3 = [u(1); u(2); u(3)+u(6)];

A_a_K  = [u__d(1); u__d(2); u__d(3)];
A_a_R1 = [u__d(1)+u__d(4); u__d(2); u__d(3)];
A_a_R2 = [u__d(1); u__d(2)+u__d(5); u__d(3)];
A_a_R3 = [u__d(1); u__d(2); u__d(3)+u__d(6)];

A_w_K  = C_P_K*(B_P_C*(A_P_B*[phi__d(1);0;0])) + ...
         C_P_K*(B_P_C*[0;phi__d(2);0]) + ...
         C_P_K*[0;0;phi__d(3)];
     
phi1_0 = 0; phi2_0 = -2*atan(2^(1/2) - 3^(1/2)); phi3_0 = -pi/4;

u1_lin = cos(phi2_0) * phi__d(2) + (-sin(phi2_0)*cos(phi3_0)-cos(phi2_0)*sin(phi3_0))*phi__d(1);
u2_lin = -sin(phi3_0)*phi__d(2)  - (-sin(phi2_0)*sin(phi3_0)+cos(phi2_0)*cos(phi3_0))*phi__d(1);
u3_lin = phi__d(3)+cos(phi2_0)*phi__d(1);

g   = sym('g');
m_G = sym('m_G');
l_c = sym('l_c');

F1_lin  = g*m_G*l_c*(-cos(phi2_0)+sin(phi2_0)*sin(phi3_0)-cos(phi2_0)*cos(phi3_0));
F2_lin  = g*m_G*l_c*(cos(phi2_0)+sin(phi2_0)*cos(phi3_0)+cos(phi2_0)*sin(phi3_0));
F3_lin  = g*m_G*l_c*(-sin(phi2_0)*cos(phi3_0)-cos(phi2_0)*sin(phi3_0)-sin(phi2_0)*sin(phi3_0)+cos(phi2_0)*cos(phi3_0));