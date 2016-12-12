close all;
f = 2;
Ta = 0.001;
T  = 5000;
t  = 0:Ta:T;
x  = sin(2*pi*f*t);
plot(t,x); grid;



figure;
ctime = -T:Ta:T;
autoc = xcorr(x, 'biased');

plot(ctime, autoc); grid;

n = length(t);
K = floor(n/2);
xcsig = autoc;

LDS = fft(xcsig);
LDSc = fftshift(LDS);

n = length(xcsig);

fa = 1/Ta;

df = fa/n;
freq = -fa/2:df:fa/2-df;

stem(freq, abs(LDSc)/n*fa); grid