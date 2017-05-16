%18.03.2017, Michael Meindl, Bestimmung der Gewichtungsmatrizen zur
%Elimination der Beschleunigugnen auf die g-Schätzung

%CalibrationFunctions;
close all;

r_s1 = [10.9; 12.2; 14.5];
r_s2 = [4.1;  12.2; 14.5];
r_s3 = [14.5; 10.9; 12.2];
r_s4 = [14.5; 4.1;  12.2];
r_s5 = [12.2; 14.5; 10.9];
r_s6 = [12.2; 14.5; 4.1 ];

b = sym('b', [4 1], 'real');

b_x4 = 0.5;
b_x_sym = solve(b(1)*r_s1 + b(2)*r_s2 + b(3)*r_s5 + b_x4*r_s6 == zeros(3,1));
b_x = [double(b_x_sym.b1); double(b_x_sym.b2); double(b_x_sym.b3); b_x4];

b_y4 = 0.5;
b_y_sym = solve(b(1)*r_s1 + b(2)*r_s2 + b(3)*r_s3 + b_y4*r_s4 == zeros(3,1));
b_y = [double(b_y_sym.b1); double(b_y_sym.b2); double(b_y_sym.b3); b_y4];

b_z4 = 0.5;
b_z_sym = solve(b(1)*r_s3 + b(2)*r_s4 + b(3)*r_s5 + b_z4*r_s6 == zeros(3,1));
b_z = [double(b_z_sym.b1); double(b_z_sym.b2); double(b_z_sym.b3); b_z4];

B_S1 = diag([b_x(1), b_y(1), b_z(1)]);
B_S2 = diag([b_x(2), b_y(2), b_z(2)]);
B_S3 = diag([b_x(3), b_y(3), b_z(3)]);
B_S4 = diag([b_x(4), b_y(4), b_z(4)]);