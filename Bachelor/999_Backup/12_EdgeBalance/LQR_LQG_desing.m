%LQR and LQG design for balancing on the edge

Ta     = 0.02;
m      = 1.532; m_R = 0.155; r_1 = [0.5;7.5;7.5]*1e-2; 
r_2 = [7.5;0.5;7.5]*1e-2; r_3    = [7.5;7.5;0.5]*1e-2;
l_C    = 0.066; c = [l_C;l_C;l_C]; C_psi  = 3.1176e-5;
I_R1M1 = [3.358e-4, 0, 0; 0, 1.961e-4, 0; 0, 0, 1.681e-4];
I_R2M2 = [1.691e-4, 0, 0; 0, 3.358e-4, 0; 0, 0, 1.961e-4];
I_R3M3 = [1.961e-4, 0, 0; 0, 1.691e-4, 0; 0, 0, 3.358e-4];
I_GHO  = [1.520e-2, -5.201e-3, 5.375e-3; -5.201e-3, 1.52e-2, 5.225e-3; 5.375e-3, 5.225e-3, 1.542e-2];
I_KO   = I_GHO + m_R*(eye(3)*dot(r_1,r_1)-r_1*r_1') ...
               + m_R*(eye(3)*dot(r_2,r_2)-r_2*r_2') ...
               + m_R*(eye(3)*dot(r_3,r_3)-r_3*r_3');
I_K    = I_KO+[I_R2M2(1,1)+I_R3M3(1,1), 0, 0; 0, I_R1M1(2,2)+I_R3M3(2,2), 0; 0, 0, I_R1M1(3,3)+I_R2M2(3,3)];
I_R    = [I_R1M1(1,1), 0, 0; 0, I_R2M2(2,2), 0; 0, 0, I_R3M3(3,3)];


I_K    = I_K(1,1);
I_R    = I_R(1,1);
g      = 9.81;

A = [0, 1, 0; m*l_C*g*sqrt(2)/I_K, -C_psi/I_K, C_psi/I_K; 0, C_psi/I_R, -C_psi/I_R];
B = [0; -1/I_K; 1/I_R];
C = [0, 1, 0; 0, 0, 1];
D = [0;0];

SSc = ss(A, B, C, D);
SSd = c2d(SSc, Ta);

x_max = [degtorad(10); degtorad(60); 500*2*pi/60];
Q     = diag(x_max.^(-2));
u_max = 0.11;
R     = diag(u_max.^(-2));

Kd    = dlqr(SSd.A, SSd.B, Q, R);
%Kd    = dlqr(SSd.A, SSd.B, eye(3)*1e-5, R);

%Design the stationary Kalman-Filter
[t_uk, uk1, uk2, uk3] = load_file('control_uk_data.csv');
[t_ur, ur1, ur2, ur3] = load_file('control_ur_data.csv');

uk1_off = -mean(uk1(10/0.02:end));
uk2_off = -mean(uk2(10/0.02:end));
uk3_off = -mean(uk3(10/0.02:end));

uk2 = uk2(10/0.02:end)+uk2_off;

ur1_off = -mean(ur1(10/0.02:end));
ur2_off = -mean(ur2(10/0.02:end));
ur3_off = -mean(ur3(10/0.02:end));

ur2 = ur2(10/0.02:end)+ur2_off;

R = cov(uk2, ur2);

Ld = dlqe(SSd.A, zeros(3,3), SSd.C, eye(3)*1e-6, R);

csvwrite('config/1D_K_mat.csv', Kd);
csvwrite('config/1D_L_mat.csv', Ld);
csvwrite('config/1D_A_mat.csv', SSd.A);
csvwrite('config/1D_B_mat.csv', SSd.B);
csvwrite('config/1D_C_mat.csv', SSd.C);


