%12.11.2016, Michael Meindl, Bestimmung des Phi-Offset

close all;

load('accel_polynoms');
load('phioffset');

a_S1_y = feval(x1_polynom, sensordata_phi_offset.mX1__dd);
a_S2_y = feval(x2_polynom, sensordata_phi_offset.mX2__dd);
a_S1_x = feval(y1_polynom, sensordata_phi_offset.mY1__dd);
a_S2_x = feval(y2_polynom, sensordata_phi_offset.mY2__dd);

l1 = 0.14;
l2 = 0.061;
g  = 9.81;

y_9  = a_S1_x - l1/l2*a_S2_x;
y_10 = a_S1_y - l1/l2*a_S2_y;
y_11 = y_10./y_9;

phi_9  = acosd(y_9 /(-g*(1-l1/l2)));
phi_10 = asind(y_10 /(g*(1-l1/l2)));
phi_11 = -atand(y_11);

t = sensordata_phi_offset.mTime;

phi_offset = mean(phi_11(1:7000));

fa  = 50;
Ta  = 1/fa;
phi = phi_11;
n   = length(phi);
PHI = fftshift(fft(phi));
df  = fa/n;
f   = -fa/2+df/2:df:fa/2-df/2;
figure; stem(f, abs(PHI)); grid;
xlabel('Frequenz [Hz]'); ylabel('|DFT|'); 
title('DFT-Phi-Accel bei Konstant-Signal');
print('plots/dft_phi_a_constsig', '-depsc');

phi_o = phi-mean(phi);
PHI = fftshift(fft(phi_o));
figure; stem(f, abs(PHI)); grid;
xlabel('Frequenz [Hz]'); ylabel('|DFT|');
title('DFT-Phi-Accel  bei Nullsignal');
print('plots/dft_phi_a_zerosig', '-depsc');

rxx = xcorr(phi_o, 'unbiased');
n   = length(rxx);
Sxx = fftshift(fft(rxx));
df  = fa/n;
f   = -fa/2+df/2:df:fa/2-df/2;
figure; stem(f, abs(Sxx)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{XX}|');
title('Leistungsdichtespektrum von Phi-Accel bei Nullsignal');
print('plots/lds_phi_a_zerosig', '-depsc');

load('gyro_calibration');

p1_phi__d  = -0.0076;
p2_phi1__d = -mean(sensordata.mPhi1__d);
p2_phi2__d = -mean(sensordata.mPhi2__d);

phi1__d    = degtorad(p1_phi__d*(sensordata_phi_offset.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_phi_offset.mPhi2__d+p2_phi2__d));

phi__d     = (phi1__d+phi2__d)/2;

phi_g = ones(size(phi__d))*degtorad(mean(phi));
n     = length(phi_g);
for k = 2:n
    phi_g(k) = phi_g(k-1)+(Ta*(phi__d(k)+phi__d(k-1))/2);
end


t = sensordata_phi_offset.mTime(1:7500);
phi_g = phi_g(1:7500);
figure; plot(t, radtodeg(phi_g)); grid;
xlabel('$Zeit [s]$', 'interpreter', 'latex');
ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
title('Phi-Gyro bei Konstantsignal');
print('plots/phi_g_constsig', '-depsc');

PHI_G = fftshift(fft(phi_g));
n = length(phi_g);
df    = fa/n;
f     = -fa/2+df/2:df:fa/2-df/2;
figure; stem(f, abs(PHI_G)); grid;
xlabel('Frequenz [Hz]'); ylabel('|DFT|');
title('DFT-Spektrum von Phi-Gyro bei Konstantsignal');
print('plots/dft_phi_g_constsig', '-depsc');

rxx = xcorr(phi_g);
n = length(rxx);
Sxx = fftshift(fft(rxx));
df = fa/n;
f  = -fa/2+df/2:df:fa/2-df/2;
figure; stem(f, abs(Sxx)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum Phi-Gyro bei Konstantsignal');
print('plots/lds_phi_g_constsig', '-depsc');