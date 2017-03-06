%Kalman-Test

n = 1000;
x = ones(n,1);
v = randn(n,1);

y = x+v;

P = 0.0001;

K   = zeros(n,1);
x_K = zeros(n,1);
P_K = zeros(n,1);
R_
x_K(1) = 3;
P_K(1) = P;

for k = 1:n-1
    K(k)     = P_K(k)/(P_K(k)+R);
    x_K(k+1) = x(k) + K(k)*(y(k)-x(k));
    P_K(k+1) = (1-K(k))*P_K(k);
end

close all;
plot(x_K); grid;

figure; plot(K); grid; title('K-Gain');
figure; plot(P_K); grid; title('Kovarianzmatrix P');