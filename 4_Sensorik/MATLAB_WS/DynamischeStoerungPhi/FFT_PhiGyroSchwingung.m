%13.11.2016, Michael Meindl, Schwingungsanalyse über Integration der Gyros

close all;

load('datafiles/gyro_calibration');
load('datafiles/messwerte_sinusanregung');

p1_phi__d  = -0.0076;
p2_phi1__d = -mean(sensordata.mPhi1__d);
p2_phi2__d = -mean(sensordata.mPhi2__d);

phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_5_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_5_amp_0__05.mPhi2__d+p2_phi2__d));

phi__d     = (phi1__d+phi2__d)/2;

t = sensordata_sin_freq_5_amp_0__05.mTime;
n = length(t);
phi = zeros(size(t));
Ta  = 0.02;
fa  = 1/Ta;

for k=2:n
    dPhi   = (phi__d(k-1)+phi__d(k))/2*Ta;
    phi(k) = phi(k-1)+dPhi;
end

figure; plot(t, radtodeg(phi)); grid; xlabel('$Zeit [s]$', 'interpreter', 'latex');
ylabel('$\varphi [^\circ]$', 'interpreter', 'latex'); title('phi aus Gyros');

phi = phi(floor(19.82/Ta):floor(160.04/Ta));
n   = length(phi);
PHI = fftshift(fft(phi));
df  = fa/n;
f   = -fa/2+df/2:df:fa/2-df/2;
figure; stem(f, abs(PHI)); grid; xlabel('Frequenz [Hz]'); ylabel('|DFT|');

rxx = xcorr(phi, 'unbiased');
dT  = -n*Ta+Ta:Ta:n*Ta-Ta;
figure; plot(dT, rxx); grid; xlabel('$\Delta T [s]$', 'interpreter', 'latex');
ylabel('$r_{xx}$', 'interpreter', 'latex');

Sxx = fftshift(fft(rxx));
df  = fa/length(rxx);
f   = -fa/2+df/2:df:fa/2-df/2;
figure; stem(f, abs(Sxx)); grid; xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');