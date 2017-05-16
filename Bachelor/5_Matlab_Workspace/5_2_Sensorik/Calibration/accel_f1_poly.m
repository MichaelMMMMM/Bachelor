%Put together the imag sensors
st_1 = [s1(:,2)'; s1(:,1)'; s3(:,1)'];
st_2 = [s2(:,2)'; s2(:,1)'; s4(:,1)'];
st_3 = [s5(:,1)'; s3(:,2)'; s5(:,2)'];
st_4 = [s6(:,1)'; s4(:,2)'; s6(:,2)'];

g      = 9.81;
t_phi1 = [zeros(1,7); sind(0:15:90); cosd(0:15:90)]*(-g);
t_phi2 = [cosd(0:15:90); zeros(1,7); sind(0:15:90)]*(-g);
t_phi3 = [sind(0:15:90); cosd(0:15:90); zeros(1,7)]*(-g);

t = [t_phi1, t_phi2, t_phi3];

st_1_f1_poly = cell(3,1);
st_2_f1_poly = cell(3,1);
st_3_f1_poly = cell(3,1);
st_4_f1_poly = cell(3,1);

for n = 1:3
    st_1_f1_poly{n} = fit(st_1(n,:)', t(n,:)', 'poly1');
    st_2_f1_poly{n} = fit(st_2(n,:)', t(n,:)', 'poly1');
    st_3_f1_poly{n} = fit(st_3(n,:)', t(n,:)', 'poly1');
    st_4_f1_poly{n} = fit(st_4(n,:)', t(n,:)', 'poly1');
end

csvwrite('config/at1_f1_x_poly.csv', [st_1_f1_poly{1}.p1, st_1_f1_poly{1}.p2]);
csvwrite('config/at1_f1_y_poly.csv', [st_1_f1_poly{2}.p1, st_1_f1_poly{2}.p2]);
csvwrite('config/at1_f1_z_poly.csv', [st_1_f1_poly{3}.p1, st_1_f1_poly{3}.p2]);
csvwrite('config/at2_f1_x_poly.csv', [st_1_f1_poly{1}.p1, st_1_f1_poly{1}.p2]);
csvwrite('config/at2_f1_y_poly.csv', [st_1_f1_poly{2}.p1, st_1_f1_poly{2}.p2]);
csvwrite('config/at2_f1_z_poly.csv', [st_1_f1_poly{3}.p1, st_1_f1_poly{3}.p2]);
csvwrite('config/at3_f1_x_poly.csv', [st_1_f1_poly{1}.p1, st_1_f1_poly{1}.p2]);
csvwrite('config/at3_f1_y_poly.csv', [st_1_f1_poly{2}.p1, st_1_f1_poly{2}.p2]);
csvwrite('config/at3_f1_z_poly.csv', [st_1_f1_poly{3}.p1, st_1_f1_poly{3}.p2]);
csvwrite('config/at4_f1_x_poly.csv', [st_1_f1_poly{1}.p1, st_1_f1_poly{1}.p2]);
csvwrite('config/at4_f1_y_poly.csv', [st_1_f1_poly{2}.p1, st_1_f1_poly{2}.p2]);
csvwrite('config/at4_f1_z_poly.csv', [st_1_f1_poly{3}.p1, st_1_f1_poly{3}.p2]);
