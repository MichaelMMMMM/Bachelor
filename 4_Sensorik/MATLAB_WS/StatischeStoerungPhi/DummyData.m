%Script to create dummy data, which can be used to test the software

close all;
dt = 0.02;
N  = 4096;

t   = 0:dt:(N-1)*dt;
phi = 15+10*rand(1,N);

plot(t, phi); grid;

rxx = xcorr(phi, 'biased');
t_rxx = (-N+1)*dt:dt:(N-1)*dt;

figure; plot(t_rxx, rxx); grid; 
xlabel('Zeitverschiebung in s'); ylabel('Autokorrelation');

Sxx = dt*fftshift(fft(rxx));
omega = -pi+pi/N:pi/N:pi-pi/N;

figure;
stem(omega, abs(Sxx)); grid;
xlabel('Normierte Frequenz'); ylabel('Sxx');

figure;
fa = 1/dt;
df = fa/length(Sxx);
f  = -fa/2:df:fa/2-df;
stem(f, abs(Sxx)); grid;
xlabel('Frequenz'); ylabel('Sxx');

%Signalleistung
P_S = sum(abs(Sxx(4092:4100)));
P_R = sum(abs(Sxx))-P_S;

SN = P_S/P_R