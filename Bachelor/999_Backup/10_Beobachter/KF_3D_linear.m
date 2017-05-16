
Beobachter_3D_diskret;

Ta = 0.02;

x_0 = [ [-6.3118;-4.9313;-5.6638]+9.81/sqrt(3);zeros(6,1) ];

A = minSYS.A;
B = minSYS.B;
C = minSYS.C;
D = minSYS.D;

%Import Data to calculate R
[tk, uk1, uk2, uk3] = import_uk_data('uk_data_measurement_noise.csv');
[tr, ur1, ur2, ur3] = import_ur_data('ur_data_measurement_noise.csv');

uk1 = uk1 - mean(uk1);
uk2 = uk2 - mean(uk2);
uk3 = uk3 - mean(uk3);
ur1 = ur1 - mean(ur1);
ur2 = ur2 - mean(ur2);
ur3 = ur3 - mean(ur3);

y = [uk1, uk2, uk3, ur1, ur2, ur3];
R = cov(y);

%Import Data to calculate Q
[tk, uk1, uk2, uk3] = import_uk_data('uk_data_process_noise.csv');
[tr, ur1, ur2, ur3] = import_ur_data('ur_data_process_noise.csv');

x   = [zeros(3,length(uk1)); uk1'; uk2'; uk3'; uk1'; uk2'; uk3'];
x_K = zeros(7, length(uk1));

for k = 1:length(uk1)
   x_K(:,k) = T_red*T_K*x(:,k); 
end

Q = cov(x_K');
Q = Q./100000;

G = [zeros(3,9); zeros(3,3), eye(3), zeros(3,3); zeros(3,6), eye(3)];

GK = T_K*G;
GK = GK(1:7,1:7);

Ld = lqed(A, GK, C, Q, R, 0.02);

csvwrite('3D_config/A_mat.csv', Ad);
csvwrite('3D_config/B_mat.csv', Bd);
csvwrite('3D_config/C_mat.csv', Cd);
csvwrite('3D_config/K_mat.csv', Kd);
csvwrite('3D_config/L_mat.csv', Ld);