close all;
n  = 1000;
fa = 100;
dt = 1/fa;
t  = 0:dt:(n-1)*dt;

x  = 5*sin(2*pi*t);

plot(t, x);

spec = fftshift(fft(x));
spec = abs(spec)/n;

df = fa/n;
f = -fa/2:df:fa/2-df;
figure;
stem(f, spec); grid