%18.04.2017, Michael Meindl, Calculate B-Values to eliminate the
%acceleration impact on the sensors.

r_s1 = [10.9; 12.2; 14.5];
r_s2 = [4.1;  12.2; 14.5];
r_s3 = [14.5; 10.9; 12.2];
r_s4 = [14.5; 4.1;  12.2];
r_s5 = [12.2; 14.5; 10.9];
r_s6 = [12.2; 14.5; 4.1 ];

b1 = sym('b1_', [3 1], 'real');
bx_vals = struct2array(solve([r_s1, r_s2, r_s5, r_s6]*[b1;1] == 0));

b2 = sym('b2_', [3 1], 'real');
by_vals = struct2array(solve([r_s1, r_s2, r_s3, r_s4]*[b2;1] == 0));

b3 = sym('b3_', [3 1], 'real');
bz_vals = struct2array(solve([r_s3, r_s4, r_s5, r_s6]*[b3;1] == 0));

csvwrite('config/accel_compensation_bx.csv', [double(bx_vals), 1]);
csvwrite('config/accel_compensation_by.csv', [double(by_vals), 1]);
csvwrite('config/accel_compensation_bz.csv', [double(bz_vals), 1]);