Ta     = 0.02; g = 9.81;
m      = 1.532; m_R    = 0.155; r_1    = [0.5;7.5;7.5]*1e-2;
r_2    = [7.5;0.5;7.5]*1e-2; r_3    = [7.5;7.5;0.5]*1e-2;
l_C    = 0.066; c      = [l_C;l_C;l_C]; C_psi  = 3.1176e-5;

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

dPhiMat = [cos(phi_30)/cos(phi_20), -sin(phi_30)/cos(phi_20), 0;
           sin(phi_30), cos(phi_30), 0; 
           -sin(phi_20)*cos(phi_30)/cos(phi_20), sin(phi_20)*sin(phi_30)/cos(phi_20), 1];
dGPhi2  = [cos(phi_20)-sin(phi_20)*sin(phi_30); ...
           -cos(phi_20)-sin(phi_20)*cos(phi_30);...
           sin(phi_20)*cos(phi_30)+sin(phi_20)*sin(phi_30)];
dGPhi3  = [cos(phi_20)*cos(phi_30);
           -cos(phi_30)*sin(phi_30);
           cos(phi_20)*sin(phi_30)-cos(phi_20)*cos(phi_30)];
dGMat   = -m*l_C*g*[zeros(3,1), dGPhi2, dGPhi3];
           
    
       
A = [zeros(3,3), dPhiMat, zeros(3,3);
     I_K_inv*dGMat, -C_psi*I_K_inv, C_psi*I_K_inv;
     zeros(3,3), C_psi*I_R_inv, -C_psi*I_R_inv];
B = [zeros(3,3); -I_K_inv; I_R_inv];
C = [zeros(3,3), eye(3), zeros(3,3);
     zeros(3,6), eye(3)];
D = zeros(6,3);

SSc = ss(A, B, C, D);
SSd = c2d(SSc, Ta, 'zoh');

[KSSd, T_K] = minreal(SSd);

phi_max   = degtorad(5);
u_K_max = degtorad(5);
u_R_max = degtorad(2000*2*pi/60);
T_max   = 0.011;
x_max = [0; phi_max; phi_max; u_K_max; u_K_max; u_K_max; u_R_max; u_R_max; u_R_max];
xK_max = T_K * x_max;

Q = diag(xK_max(1:7).^(-2));
R = eye(3)*T_max^(-2);

% x_max = [0;1;1;0.05;0.05;0.05;0.0005;0.0005;0.0005];
% xK_max = T_K * x_max;
% Q = diag(xK_max(1:7).^2);

%KKd = dlqr(KSSd.A, KSSd.B, Q*5e-4, R);
KKd = dlqr(KSSd.A, KSSd.B, eye(7)*8e-3, R);
KKd(:, 4:7) = KKd(:, 4:7) * 1.4;
KKd(:,4) = KKd(:,4) * 1.01;
KKd(:,6) = KKd(:,6) * 1.01;
Kd  = KKd * [eye(7), zeros(7,2)]*T_K;
% 
% %Kd tuning
Kd(:,3) = Kd(:,3)*1.5;
Kd(1,4) = Kd(1,4)*1.5;
Kd(2,5) = Kd(2,5)*1.5;
Kd(3,6) = Kd(3,6)*1.5;

csvwrite('config/3D_K_mat.csv', Kd);

Kd_o = Kd + [zeros(3,3), ones(3,3)*0.5/sqrt(3), zeros(3,3)];
     

%Kalman-Filter Design
[t_uk, uk1, uk2, uk3] = load_file('control_uk_data.csv');
[t_ur, ur1, ur2, ur3] = load_file('control_ur_data.csv');

uk1_off = -mean(uk1(10/0.02:end));
uk2_off = -mean(uk2(10/0.02:end));
uk3_off = -mean(uk3(10/0.02:end));
ur1_off = -mean(ur1(10/0.02:end));
ur2_off = -mean(ur2(10/0.02:end));
ur3_off = -mean(ur3(10/0.02:end));

uk1 = uk1(10/0.02:end)+uk1_off;
uk2 = uk2(10/0.02:end)+uk2_off;
uk3 = uk3(10/0.02:end)+uk3_off;
ur1 = ur1(10/0.02:end)+ur1_off;
ur2 = ur2(10/0.02:end)+ur2_off;
ur3 = ur3(10/0.02:end)+ur3_off;

R = cov([uk1 uk2 uk3 ur1 ur2 ur3]);
Ld = dlqe(KSSd.A, zeros(7,7), KSSd.C, eye(7)*1e-3, R);

csvwrite('config/3D_A_mat.csv', KSSd.A);
csvwrite('config/3D_B_mat.csv', KSSd.B);
csvwrite('config/3D_C_mat.csv', KSSd.C);
csvwrite('config/3D_Kk_mat.csv', KKd);
csvwrite('config/3D_L_mat.csv', Ld);
csvwrite('config/3D_T_K_mat.csv', [eye(7), zeros(7,2)]*T_K);

%Simulink-Model setup
phi0 = [phi_10; phi_20+degtorad(-3); phi_30+degtorad(3)];
u_K0 = zeros(3,1);
u_R0 = zeros(3,1);
x_0  = [phi0-[0;phi_20;-phi_30];u_K0;u_R0];
phi_offset = degtorad([0;-2;0]);
u_K_offset = ones(3,1)*0.005;
u_R_offset = [0;0;0];
x_offset = [phi_offset; u_K_offset; u_R_offset];
