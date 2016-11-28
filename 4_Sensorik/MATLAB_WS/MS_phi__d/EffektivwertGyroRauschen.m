%23.11.2016, Michael Meindl, Effektivwert der Rauschsignale der Gyros bei
%Nullsignal

clear; close all;

load('Messreihe1'); load('gyro_calibration');

p1_phi__d  = -0.0076;
p2_phi1__d = -mean(sensordata_freq_0.mPhi1__d);
p2_phi2__d = -mean(sensordata_freq_0.mPhi2__d);

t   = sensordata_freq_0.mTime;
y_1 = degtorad(p1_phi__d*(sensordata_freq_0.mPhi1__d+p2_phi1__d));
y_2 = degtorad(p1_phi__d*(sensordata_freq_0.mPhi2__d+p2_phi2__d));
y_3 = (y_1+y_2)/2;

plot(t, y_1, t, y_2, t, y_3); grid;
xlabel('$Zeit [s]$', 'interpreter', 'latex');
ylabel('$\dot{\varphi} [\frac{rad}{s}]$', 'interpreter', 'latex');
title('Messwerte der Gyroscopes');
legend('y_1', 'y_2', 'y_3');