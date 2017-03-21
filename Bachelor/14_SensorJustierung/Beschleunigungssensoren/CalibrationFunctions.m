%18.03.2017, Michael Meindl, Berechnung der Ausgleichsfunktionen zur
%Justierung der Beschleunigungssensoren
%Version 1: f(x), geometrische Fehler werden nicht beachtet
%Version 2: f(x,y,z), geometrische Fehler beachtet
%Anschließend werden beide Versionene verglichen.

close all;

datafiles = {'data/accel_calib_phi1_0.csv', 'data/accel_calib_phi1_15.csv',...
             'data/accel_calib_phi1_30.csv', 'data/accel_calib_phi1_45.csv',...
             'data/accel_calib_phi1_60.csv', 'data/accel_calib_phi1_75.csv',...
             'data/accel_calib_phi1_90.csv', 'data/accel_calib_phi2_0.csv',...
             'data/accel_calib_phi2_15.csv', 'data/accel_calib_phi2_30.csv',...
             'data/accel_calib_phi2_45.csv', 'data/accel_calib_phi2_60.csv',...
             'data/accel_calib_phi2_75.csv', 'data/accel_calib_phi2_90.csv',...
             'data/accel_calib_phi3_0.csv', 'data/accel_calib_phi3_15.csv',...
             'data/accel_calib_phi3_30.csv', 'data/accel_calib_phi3_45.csv',...
             'data/accel_calib_phi3_60.csv', 'data/accel_calib_phi3_75.csv',...
             'data/accel_calib_phi3_90.csv'};
n = length(datafiles);

%Arrays to hold the mean values of the artificial sensors
s1 = zeros(3, n);
s2 = zeros(3, n);
s3 = zeros(3, n);
s4 = zeros(3, n);

%Cellarrays to hold the coefficients used for calibration
Sfit_V1 = cell(1,4);
Sfit_V2 = cell(4,1);

for k = 1:n
    [t1, a_x1, a_y1, a_z1, w_x1, w_y1, w_z1,...
     t2, a_x2, a_y2, a_z2, w_x2, w_y2, w_z2,...
     t3, a_x3, a_y3, a_z3, w_x3, w_y3, w_z3,...
     t4, a_x4, a_y4, a_z4, w_x4, w_y4, w_z4,...
     t5, a_x5, a_y5, a_z5, w_x5, w_y5, w_z5,...
     t6, a_x6, a_y6, a_z6, w_x6, w_y6, w_z6] = importfile(datafiles{k});
 
    s1(:,k) = [mean(a_y1); mean(a_x1); mean(a_x3)];
    s2(:,k) = [mean(a_y2); mean(a_x2); mean(a_x4)];
    s3(:,k) = [mean(a_x5); mean(a_y3); mean(a_y5)];
    s4(:,k) = [mean(a_x6); mean(a_y4); mean(a_y6)];
end

%Determine the target values
phi1 = [0:15:90, zeros(1,14)];
phi2 = [zeros(1,7), 0:15:90, zeros(1,7)];
phi3 = [zeros(1,14), 0:15:90];
phi = [phi1(1:7), phi2(8:14), phi3(15:21)];

g = 9.81;

t1   = g*[zeros(1,7), -cosd(0:15:90), -sind(0:15:90)];
t2   = g*[-sind(0:15:90), zeros(1,7), -cosd(0:15:90)];
t3   = g*[-cosd(0:15:90), -sind(0:15:90), zeros(1,7)];

t = [t1;t2;t3];

%Determine the calibration coefficients V1
for k = 1:3
    fit_s1 = fit(s1(k,:)', t(k,:)', 'poly1');
    fit_s2 = fit(s2(k,:)', t(k,:)', 'poly1');
    fit_s3 = fit(s3(k,:)', t(k,:)', 'poly1');
    fit_s4 = fit(s4(k,:)', t(k,:)', 'poly1');
    
    Sfit_V1{k,1} = [fit_s1.p1, fit_s1.p2];
    Sfit_V1{k,2} = [fit_s2.p1, fit_s2.p2];
    Sfit_V1{k,3} = [fit_s3.p1, fit_s3.p2];
    Sfit_V1{k,4} = [fit_s4.p1, fit_s4.p2];
end

%Determine the calibration coefficients V2
A   = cell(4,1);
B_x = cell(4,1);
B_y = cell(4,1);
B_z = cell(4,1);

s_i = {s1;s2;s3;s4};

for k = 1:4
    x = s_i{k}(1,:);
    y = s_i{k}(2,:);
    z = s_i{k}(3,:);
    A{k} = [ dot(x, x), dot(y, x), dot(z, x), sum(x);...
             dot(x, y), dot(y, y), dot(z, y), sum(y);...
             dot(x, z), dot(y, z), dot(z, z), sum(z);...
             sum(x),    sum(y),    sum(z),    n];
    B_x{k} = [dot(t1, x); dot(t1, y); dot(t1, z); sum(t1)];
    B_y{k} = [dot(t2, x); dot(t2, y); dot(t2, z); sum(t2)];
    B_z{k} = [dot(t3, x); dot(t3, y); dot(t3, z); sum(t3)];
    
    w_x = A{k}\B_x{k};
    w_y = A{k}\B_y{k};
    w_z = A{k}\B_z{k};
    
    Sfit_V2{k} = [w_x';w_y';w_z'];
end

%Evaluate the Data
s1_V1 = [ Sfit_V1{1,1}(1)*s1(1,:)+Sfit_V1{1,1}(2); ...
          Sfit_V1{2,1}(1)*s1(2,:)+Sfit_V1{2,1}(2); ...
          Sfit_V1{3,1}(1)*s1(3,:)+Sfit_V1{3,1}(2)];
s2_V1 = [ Sfit_V1{1,2}(1)*s2(1,:)+Sfit_V1{1,2}(2); ...
          Sfit_V1{2,2}(1)*s2(2,:)+Sfit_V1{2,2}(2); ...
          Sfit_V1{3,2}(1)*s2(3,:)+Sfit_V1{3,2}(2)];
s3_V1 = [ Sfit_V1{1,3}(1)*s3(1,:)+Sfit_V1{1,3}(2); ...
          Sfit_V1{2,3}(1)*s3(2,:)+Sfit_V1{2,3}(2); ...
          Sfit_V1{3,3}(1)*s3(3,:)+Sfit_V1{3,3}(2)];
s4_V1 = [ Sfit_V1{1,4}(1)*s4(1,:)+Sfit_V1{1,4}(2); ...
          Sfit_V1{2,4}(1)*s4(2,:)+Sfit_V1{2,4}(2); ...
          Sfit_V1{3,4}(1)*s4(3,:)+Sfit_V1{3,4}(2)];
      
s1_V2 = Sfit_V2{1}(1:3,1:3)*s1 + Sfit_V2{1}(:,4);
s2_V2 = Sfit_V2{2}(1:3,1:3)*s2 + Sfit_V2{2}(:,4);
s3_V2 = Sfit_V2{3}(1:3,1:3)*s3 + Sfit_V2{3}(:,4);
s4_V2 = Sfit_V2{4}(1:3,1:3)*s4 + Sfit_V2{4}(:,4);

%Calculate the errors
s1_V1_error = s1_V1 - t;
s2_V1_error = s2_V1 - t;
s3_V1_error = s3_V1 - t;
s4_V1_error = s4_V1 - t;
s1_V2_error = s1_V2 - t;
s2_V2_error = s2_V2 - t;
s3_V2_error = s3_V2 - t;
s4_V2_error = s4_V2 - t;

%Plot the results
%Results g_k1
figure;
subplot(2,2,1);
plot([t1', s1_V1(1,:)', s1_V2(1,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 1 g_{k1}');
subplot(2,2,2);
plot([t1', s2_V1(1,:)', s2_V2(1,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 2 g_{k1}');
subplot(2,2,3);
plot([t1', s3_V1(1,:)', s3_V2(1,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 3 g_{k1}');
subplot(2,2,4);
plot([t1', s4_V1(1,:)', s4_V2(1,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 4 g_{k1}');

%Results g_k2
figure;
subplot(2,2,1);
plot([t2', s1_V1(2,:)', s1_V2(2,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 1 g_{k2}');
subplot(2,2,2);
plot([t2', s2_V1(2,:)', s2_V2(2,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 2 g_{k2}');
subplot(2,2,3);
plot([t2', s3_V1(2,:)', s3_V2(2,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 3 g_{k2}');
subplot(2,2,4);
plot([t2', s4_V1(2,:)', s4_V2(2,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 4 g_{k2}');

%Results g_k3
figure;
subplot(2,2,1);
plot([t3', s1_V1(3,:)', s1_V2(3,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 1 g_{k3}');
subplot(2,2,2);
plot([t3', s2_V1(3,:)', s2_V2(3,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 2 g_{k3}');
subplot(2,2,3);
plot([t3', s3_V1(3,:)', s3_V2(3,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 3 g_{k3}');
subplot(2,2,4);
plot([t3', s4_V1(3,:)', s4_V2(3,:)'], '.'); grid;
legend('Sollwert', 'Justierung V1', 'Justierung V2');
title('Sensor 4 g_{k3}');

