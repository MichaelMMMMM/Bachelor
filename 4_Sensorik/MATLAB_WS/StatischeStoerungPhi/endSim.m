%End Simulation

close all;


t   = phi_sig.Time;
phi = phi_sig.Data;

figure;
plot(t, phi); grid; xlabel('Zeit'); ylabel('Phi');


figure;
rxx = xcorr(phi, 'biased');
rt  = -T:Ta:T;
plot(rt, rxx); grid; xlabel('Zeitdistanz'); ylabel('Autokorrelation');

figure;
Sxx = fftshift(fft(rxx));
n   = length(Sxx);
dw  = 2*pi/n;
w   = -pi+dw/2:dw:pi-dw/2;
stem(w, abs(Sxx)); grid; xlabel('Normierte Frequenz'); ylabel('|Sxx|');

n = phi-15;
sn = snr(phi,n)


