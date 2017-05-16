%Michael Meindl, 18.02.2017, Justierung mittels Projektionsmatrix und
%kleinster Fehlerquadrate

close all;

a_x  = cell(6,1);
a_y  = cell(6,1);
a_z  = cell(6,1);

A    = cell(6,1);
B_x  = cell(6,1);
B_y  = cell(6,1);
B_z  = cell(6,1);

w_x = cell(6,1);
w_y = cell(6,1);
w_z = cell(6,1);

S   = cell(6,1);
o_S = cell(6,1);

t_x = k1_target; t_y = k2_target; t_z = k3_target;

z_lookup = [3, 4, 5, 6, 1, 2];

for k = 1:6
    a_x{k} = a_x_mean(k,:);
    a_y{k} = a_y_mean(k,:);
    a_z{k} = a_x_mean(z_lookup(k), :);

    A{k} = [ dot(a_x{k}, a_x{k}), dot(a_x{k}, a_y{k}), dot(a_x{k}, a_x{k}), sum(a_x{k});
             dot(a_x{k}, a_y{k}), dot(a_y{k}, a_y{k}), dot(a_z{k}, a_y{k}), sum(a_y{k});
             dot(a_x{k}, a_z{k}), dot(a_y{k}, a_z{k}), dot(a_z{k}, a_z{k}), sum(a_z{k});
             sum(a_x{k}),         sum(a_y{k}),         sum(a_z{k}),         length(a_x{k})];
         
    B_x{k} = [dot(t_x, a_x{k}); dot(t_x, a_y{k}); dot(t_x, a_z{k}); sum(t_x)];
    B_y{k} = [dot(t_y, a_x{k}); dot(t_y, a_y{k}); dot(t_y, a_z{k}); sum(t_y)];
    B_z{k} = [dot(t_z, a_x{k}); dot(t_z, a_y{k}); dot(t_z, a_z{k}); sum(t_z)];
    
    w_x{k} = A{k}\B_x{k};
    w_y{k} = A{k}\B_y{k};
    w_z{k} = A{k}\B_z{k};
    
    S{k}   = [w_x{k}(1:3)'; w_y{k}(1:3)'; w_z{k}(1:3)'];
    o_S{k} = [w_x{k}(4); w_y{k}(4); w_z{k}(4)];
    
    a_corr = S{k}*[a_x{k};a_y{k};a_z{k}] + o_S{k};
    
    figure; plot([a_corr(1,:)',t_x']); grid;
    title(strcat('k1 Sensor', num2str(k))); legend('Korrigiert', 'Soll');
    figure; plot([a_corr(2,:)', t_y']); grid;
    title(strcat('k2 Sensor', num2str(k))); legend('Korrigiert', 'Soll');
    figure; plot([a_corr(3,:)', t_z']); grid;
    title(strcat('k3 Sensor', num2str(k))); legend('Korrigiert', 'Soll');

    file_name = strcat('calib_data/sensor', num2str(k), '_calib_data.csv');
    csvwrite(file_name, [S{k}, o_S{k}]);
end

