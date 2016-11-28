%23.11.16, Michael Meindl, Pendel-Berechnung

m = 1;
l = 3;
g = 9.81;
k = 0.5;

A = [0 1; (-g/l) (-k/(m*l^2))];
B = [0; 1/(m*l^2)];
C = [1 0];
D = 0;

[n,d] = ss2tf(A,B,C,D);
G_tf = tf(n,d);
G_ss = ss(A,B,C,D);