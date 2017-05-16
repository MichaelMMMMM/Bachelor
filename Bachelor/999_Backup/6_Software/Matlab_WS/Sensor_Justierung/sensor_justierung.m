%15.02.2017, Michael Meindl, Berechnung der Ausgleichspolynome zur
%Sensorjustierung
close all;


datafiles = {'data/sensor_calib_data_phi2_0.csv', ...
             'data/sensor_calib_data_phi2_15.csv',...
             'data/sensor_calib_data_phi2_30.csv',...
             'data/sensor_calib_data_phi2_45.csv',...
             'data/sensor_calib_data_phi2_60.csv',...
             'data/sensor_calib_data_phi2_75.csv',...
             'data/sensor_calib_data_phi2_90.csv',...
             'data/sensor_calib_data_phi3_0.csv',...
             'data/sensor_calib_data_phi3_-15.csv',...
             'data/sensor_calib_data_phi3_-30.csv',...
             'data/sensor_calib_data_phi3_-45.csv',...
             'data/sensor_calib_data_phi3_-60.csv',...
             'data/sensor_calib_data_phi3_-75.csv',...
             'data/sensor_calib_data_phi3_-90.csv'};
   
a_x_mean  = zeros(6, 14);
a_y_mean  = zeros(6, 14);
a_z_mean  = zeros(6, 14);

for n = 1:length(datafiles)
    [t1, a_x1, a_y1, a_z1, w_x1, w_y1, w_z1, ...
     t2, a_x2, a_y2, a_z2, w_x2, w_y2, w_z2, ...
     t3, a_x3, a_y3, a_z3, w_x3, w_y3, w_z3, ...
     t4, a_x4, a_y4, a_z4, w_x4, w_y4, w_z4, ...
     t5, a_x5, a_y5, a_z5, w_x5, w_y5, w_z5, ...
     t6, a_x6, a_y6, a_z6, w_x6, w_y6, w_z6] = import_data_file(datafiles{n});
    a_x_vals = {a_x1, a_x2, a_x3, a_x4, a_x5, a_x6};
    a_y_vals = {a_y1, a_y2, a_y3, a_y4, a_y5, a_y6};
    a_z_vals = {a_z1, a_z2, a_z3, a_z4, a_z5, a_z6};
 
    for k = 1:6
        a_x_mean(k, n) = mean(a_x_vals{k});
        a_y_mean(k, n) = mean(a_y_vals{k});
        a_z_mean(k, n) = mean(a_z_vals{k});
    end
end

phi1 = zeros(14, 1);
phi2 = degtorad([0; 15; 30; 45; 60; 75; 90; 0; 0; 0; 0; 0; 0; 0]);
phi3 = degtorad([zeros(7, 1); 0; -15; -30; -45; -60; -75; -90]);

phi_sym = sym('phi', [3 1], 'real');

A_P_B = [1, 0, 0; 0, cos(phi_sym(1)), sin(phi_sym(1)); 0, -sin(phi_sym(1)), cos(phi_sym(1))];
B_P_C = [cos(phi_sym(2)), 0, -sin(phi_sym(2)); 0, 1, 0; sin(phi_sym(2)), 0, cos(phi_sym(2))];
C_P_K = [cos(phi_sym(3)), sin(phi_sym(3)), 0; -sin(phi_sym(3)), cos(phi_sym(3)), 0; 0, 0, 1];

A_P_C = C_P_K*(B_P_C*A_P_B);

g_target = zeros(3, 14);
for n = 1:14
    g_target(:,n) = double(subs(A_P_C, phi_sym, [phi1(n); phi2(n); phi3(n)]))*[-9.81;0;0]; 
end

k1_target = g_target(1,:);
k2_target = g_target(2,:);
k3_target = g_target(3,:);

%Sensor1&2, y==k1, x==k2, Sensor3&4, x==k3, y==k2, Sensor5&6 x==k1, y==k3
x1_poly = fit(a_x_mean(1,:)', k2_target', 'poly1');
y1_poly = fit(a_y_mean(1,:)', k1_target', 'poly1');
x2_poly = fit(a_x_mean(2,:)', k2_target', 'poly1');
y2_poly = fit(a_y_mean(2,:)', k1_target', 'poly1');
x3_poly = fit(a_x_mean(3,:)', k3_target', 'poly1');
y3_poly = fit(a_y_mean(3,:)', k2_target', 'poly1');
x4_poly = fit(a_x_mean(4,:)', k3_target', 'poly1');
y4_poly = fit(a_y_mean(4,:)', k2_target', 'poly1');
x5_poly = fit(a_x_mean(5,:)', k1_target', 'poly1');
y5_poly = fit(a_y_mean(5,:)', k3_target', 'poly1');
x6_poly = fit(a_x_mean(6,:)', k1_target', 'poly1');
y6_poly = fit(a_y_mean(6,:)', k3_target', 'poly1');

x_polynoms = {x1_poly, x2_poly, x3_poly, x4_poly, x5_poly, x6_poly};
y_polynoms = {y1_poly, y2_poly, y3_poly, y4_poly, y5_poly, y6_poly};

w_p1 = degtorad(500)/2^16;
w_mean = [mean(w_x1), mean(w_x2), mean(w_x3),...
          mean(w_x4), mean(w_x5), mean(w_x6);...
          mean(w_y1), mean(w_y2), mean(w_y3),...
          mean(w_y4), mean(w_y5), mean(w_y6);...
          mean(w_z1), mean(w_z2), mean(w_z3),...
          mean(w_z4), mean(w_z5), mean(w_z6)];

w_p2   = -w_mean*w_p1;


B_x = cell(6,1);
B_y = cell(6,1);
A   = cell(6,1);

for k = 1:6
    A{k} = [sum(a_x_mean(k,:).^2), sum(a_x_mean(k,:).*a_y_mean(k,:)), sum(-a_x_mean(k,:));...
            sum(a_x_mean(k,:).*a_y_mean(k,:)), sum(a_y_mean(k,:).^2), sum(-a_y_mean(k,:));...
            sum(a_x_mean(k,:)), sum(a_y_mean(k,:)), -length(a_x_mean(k,:))];
end

B_x{1} = [sum(k2_target.*a_x_mean(1,:));sum(k2_target.*a_y_mean(1,:));sum(k2_target)];
B_x{2} = [sum(k2_target.*a_x_mean(2,:));sum(k2_target.*a_y_mean(2,:));sum(k2_target)];
B_x{3} = [sum(k3_target.*a_x_mean(3,:));sum(k3_target.*a_y_mean(3,:));sum(k3_target)];
B_x{4} = [sum(k3_target.*a_x_mean(4,:));sum(k3_target.*a_y_mean(4,:));sum(k3_target)];
B_x{5} = [sum(k1_target.*a_x_mean(5,:));sum(k1_target.*a_y_mean(5,:));sum(k1_target)];
B_x{6} = [sum(k1_target.*a_x_mean(6,:));sum(k1_target.*a_y_mean(6,:));sum(k1_target)];

B_y{1} = [sum(k1_target.*a_x_mean(1,:));sum(k1_target.*a_y_mean(1,:));sum(k1_target)];
B_y{2} = [sum(k1_target.*a_x_mean(2,:));sum(k1_target.*a_y_mean(2,:));sum(k1_target)];
B_y{3} = [sum(k2_target.*a_x_mean(3,:));sum(k2_target.*a_y_mean(3,:));sum(k2_target)];
B_y{4} = [sum(k2_target.*a_x_mean(4,:));sum(k2_target.*a_y_mean(4,:));sum(k2_target)];
B_y{5} = [sum(k3_target.*a_x_mean(5,:));sum(k3_target.*a_y_mean(5,:));sum(k3_target)];
B_y{6} = [sum(k3_target.*a_x_mean(6,:));sum(k3_target.*a_y_mean(6,:));sum(k3_target)];

w_x = zeros(3,6);
w_y = zeros(3,6);

for k = 1:6
    w_x(:,k) = A{k}\B_x{k};
    w_y(:,k) = A{k}\B_y{k};
end

x_target = [k2_target; k2_target; k3_target; k3_target; k1_target; k1_target];
y_target = [k1_target; k1_target; k2_target; k2_target; k3_target; k3_target];

x_pol1   = zeros(6, 14);
y_pol1   = zeros(6, 14);

x_proj   = zeros(6, 14);
y_proj   = zeros(6, 14);

for k = 1:6
    x_poly(k,:) = feval(x_polynoms{k}, a_x_mean(k,:));
    y_poly(k,:) = feval(y_polynoms{k}, a_y_mean(k,:));
    x_proj(k,:) = w_x(1)*a_x_mean(k,:)+w_x(2)*a_y_mean(k,:)-w_x(3);
    y_proj(k,:) = w_y(1)*a_x_mean(k,:)+w_y(2)*a_y_mean(k,:)-w_y(3);
    
    figure;
    plot([x_target(k,:)',x_poly(k,:)', x_proj(k,:)']); grid;
    legend('Target', 'poly1', 'proj');
    title(strcat('X', num2str(k)));
    
    figure;
    plot([y_target(k,:)',y_poly(k,:)', y_proj(k,:)']); grid;
    legend('Target', 'poly1', 'proj');
    title(strcat('Y', num2str(k)));
end
