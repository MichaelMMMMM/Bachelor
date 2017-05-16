w1_x = mean(s1(:,4));
w1_y = mean(s1(:,5));
w1_z = mean(s1(:,6));

w2_x = mean(s2(:,4));
w2_y = mean(s2(:,5));
w2_z = mean(s2(:,6));

w3_x = mean(s3(:,4));
w3_y = mean(s3(:,5));
w3_z = mean(s3(:,6));

w4_x = mean(s4(:,4));
w4_y = mean(s4(:,5));
w4_z = mean(s4(:,6));

w5_x = mean(s5(:,4));
w5_y = mean(s5(:,5));
w5_z = mean(s5(:,6));

w6_x = mean(s6(:,4));
w6_y = mean(s6(:,5));
w6_z = mean(s6(:,6));

p1   = -degtorad(1/131);

csvwrite('config/w1_f1_x_poly.csv', p1, -w1_x/p1);
csvwrite('config/w1_f1_y_poly.csv', p1, -w1_y/p1);
csvwrite('config/w1_f1_z_poly.csv', p1, -w1_z/p1);
csvwrite('config/w2_f1_x_poly.csv', p1, -w2_x/p1);
csvwrite('config/w2_f1_y_poly.csv', p1, -w2_y/p1);
csvwrite('config/w2_f1_z_poly.csv', p1, -w2_z/p1);
csvwrite('config/w3_f1_x_poly.csv', p1, -w3_x/p1);
csvwrite('config/w3_f1_y_poly.csv', p1, -w3_y/p1);
csvwrite('config/w3_f1_z_poly.csv', p1, -w3_z/p1);
csvwrite('config/w4_f1_x_poly.csv', p1, -w4_x/p1);
csvwrite('config/w4_f1_y_poly.csv', p1, -w4_y/p1);
csvwrite('config/w4_f1_z_poly.csv', p1, -w4_z/p1);
csvwrite('config/w5_f1_x_poly.csv', p1, -w5_x/p1);
csvwrite('config/w5_f1_y_poly.csv', p1, -w5_y/p1);
csvwrite('config/w5_f1_z_poly.csv', p1, -w5_z/p1);
csvwrite('config/w6_f1_x_poly.csv', p1, -w6_x/p1);
csvwrite('config/w6_f1_y_poly.csv', p1, -w6_y/p1);
csvwrite('config/w6_f1_z_poly.csv', p1, -w6_z/p1);