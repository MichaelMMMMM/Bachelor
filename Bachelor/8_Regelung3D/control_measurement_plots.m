%Michael Meindl, display control measurements

close all;

import_control_g;
import_control_uk;
import_control_ur;
import_control_tm;

figure;
plot(t_g, g1, t_g, g2, t_g, g3); grid;
legend('g_k1', 'g_k2', 'g_k3');
xlabel('Time [s]'); ylabel('g [m/s^2]');
title('g-Vector');

figure;
plot(t_uk, uk1, t_uk, uk2, t_uk, uk3); grid;
legend('uk_k1', 'uk_k2', 'uk_k3');
xlabel('Time [s]'); ylabel('u_k [rad/s]');
title('u_K-Vector');

figure; 
plot(t_ur, ur1, t_ur, ur2, t_ur, ur3); grid;
legend('ur_k1', 'ur_k2', 'ur_k3');
xlabel('Time [s]'); ylabel('u_r [rad/s]');
title('u_R-Vector');

figure;
plot(t_tm, tm1, t_tm, tm2, t_tm, tm3); grid;
legend('TM1', 'TM2', 'TM3');
xlabel('Time [s]'); ylabel('Torque [Nm]');
title('Torque-Vector');