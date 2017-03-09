
Beobachter_3D_diskret;

x_0 = [ [-6.3118;-4.9313;-5.6638]+9.81/sqrt(3);zeros(6,1) ];


Ad_K = minSYSd.A;
Bd_K = minSYSd.B;
Cd_K = minSYSd.C;

M_0 = eye(3)*1e-5;
P_0 = eye(7)*1e-10;

alpha_M = 0.3;

Ld_K = dlqe(Ad_K, zeros(7),Cd_K, zeros(7), eye(3));