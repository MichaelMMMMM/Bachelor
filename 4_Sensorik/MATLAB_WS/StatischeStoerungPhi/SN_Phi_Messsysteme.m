%12.11.2016, Michael Meindl, Berechnung SR fuer die phi-Messsysteme

phi_value = 15;     %Nutzsignal in grad

load('datafiles/accel_polynoms');
load('datafiles/sensordata___phi_15');

a_S1_y = feval(x1_polynom, sensordata___phi_15.mX1__dd);
a_S2_y = feval(x2_polynom, sensordata___phi_15.mX2__dd);
a_S1_x = feval(y1_polynom, sensordata___phi_15.mY1__dd);
a_S2_x = feval(y2_polynom, sensordata___phi_15.mY2__dd);

l1 = 0.14;
l2 = 0.061;
g  = 9.81;

y_9  = a_S1_x - l1/l2*a_S2_x;
y_10 = a_S1_y - l1/l2*a_S2_y;
y_11 = y_10./y_9;

phi_9  = acosd(y_9 /(-g*(1-l1/l2)));
phi_10 = asind(y_10 /(g*(1-l1/l2)));
phi_11 = -atand(y_11);

t = sensordata___phi_15.mTime;

subplot(3,1, 1);
plot(t, phi_9); grid; xlabel('$Zeit [s]$', 'interpreter', 'latex');
ylabel('$\varphi [^\circ]$', 'interpreter', 'latex'); 
title('$\varphi$ aus $y_9$', 'interpreter', 'latex');

subplot(3,1,2);
plot(t, phi_10); grid; xlabel('$Zeit [s]$', 'interpreter', 'latex');
ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
title('$\varphi$ aus $y_{10}$', 'interpreter', 'latex');

subplot(3,1,3);
plot(t, phi_11); grid; xlabel('$Zeit [s]$', 'interpreter', 'latex');
ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
title('$\varphi$ aus $y_{11}$', 'interpreter', 'latex');

noise_9   = phi_9 - mean(phi_9);
sig_9     = phi_9 - noise_9;
noise_10  = phi_10 - mean(phi_10);
sig_10    = phi_10 - noise_10;
noise_11  = phi_11 - mean(phi_11);
sig_11    = phi_11 - noise_11;

sn_9      = snr(sig_9, noise_9);
sn_10     = snr(sig_10, noise_10);
sn_11     = snr(sig_11, noise_11);