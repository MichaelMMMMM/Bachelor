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
           
phi_10 = 0;
phi_20 = -2*atan(sqrt(2)-sqrt(3));
phi_30 = -pi/4;

g      = 9.81;
g_LA   = [0, g*sin(phi_20), g*cos(phi_20)*sin(phi_30);
          -g*sin(phi_20), 0, g*cos(phi_20)*cos(phi_30);
          -g*cos(phi_20)*sin(phi_30), -g*cos(phi_20)*cos(phi_30), 0];
G_LA   = [0, -m*l_C, m*l_C; m*l_C, 0, -m*l_C; -m*l_C, m*l_C, 0];

A = [zeros(3,3), g_LA, zeros(3,3); 
     I_K\G_LA, -C_psi*I_K_inv, C_psi*I_K_inv;
     zeros(3,3), C_psi*I_R_inv, -C_psi*I_R_inv];
B = [zeros(3,3); -I_K_inv; I_R_inv];

C = [zeros(3,3),eye(3), zeros(3,3);
     zeros(3,6), eye(3)];
D = zeros(6,3);

%Create the state-space model
mySS = ss(A, B, C, D);
[minSYS, T_K] = minreal(mySS);
minSYSd = c2d(minSYS, 0.02);
Ad = minSYSd.A; Bd = minSYSd.B; Cd = minSYSd.C;
T_red = [eye(7), zeros(7,2)];

%Design the discrete controller using LQR
g_max   = 1;
u_K_max = degtorad(180);
u_R_max = degtorad(4000/60*300);
T_max   = 0.13;
x_max   = [g_max; g_max; g_max; u_K_max; u_K_max; u_K_max; u_R_max; u_R_max; u_R_max];
x_max   = T_K*x_max;

Q       = diag(x_max(1:7).^(-2));
R       = eye(3)*(T_max^(-2));
K       = lqr(minSYS, Q, R);
Kd      = lqrd(minSYS.A, minSYS.B, Q, R, 0.02);

Ad_C    = Ad-Bd*Kd;
max_eig_cl = min(real(eig(Ad_C)));


%Calculate the discrete observer
ew_disc = abs(eig(Ad_C));
ew_disc_max = min(ew_disc);
ew_beo = (ew_disc_max^2)./[1:0.5:4];

Ld = (place(Ad', Cd', ew_beo))';
