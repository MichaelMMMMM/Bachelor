%Michael Meindl, display control measurements

close all;

import_control_g;
import_control_uk;
import_control_ur;
import_control_tm;


figure('Color',[0.8 0.8 0.8]);
plot(t_g, [g1, g2,  g3], '.'); grid;
set(gca,'Color',[0.1 0.1 0.1]);
set(gca,'GridColor', [1 1 1]);
legend({'g_k1', 'g_k2', 'g_k3'}, 'TextColor', 'white');
xlabel('Time [s]'); ylabel('g [m/s^2]');
title('g-Vector');

figure('Color', ones(1,3)*0.8);
plot(t_uk, [uk1, uk2, uk3], '.'); grid;
set(gca,'Color', [0.1 0.1 0.1]);
set(gca, 'GridColor', [1 1 1]);
legend({'uk_k1', 'uk_k2', 'uk_k3'}, 'TextColor', 'white');
xlabel('Time [s]'); ylabel('u_k [rad/s]');
title('u_K-Vector');

figure('Color', [0.8 0.8 0.8]);
plot(t_ur, [ur1, ur2, ur3], '.'); grid;
set(gca, 'Color', [0.1 0.1 0.1]);
set(gca, 'GridColor', [1 1 1]);
legend({'ur_k1', 'ur_k2', 'ur_k3'}, 'TextColor', 'white');
xlabel('Time [s]'); ylabel('u_r [rad/s]');
title('u_R-Vector');

figure('Color', [0.8 0.8 0.8]);
plot(t_tm, [tm1, tm2, tm3], '.'); grid;
set(gca, 'Color', [0.1 0.1 0.1]);
set(gca, 'GridColor', [1 1 1]);
legend({'TM1', 'TM2', 'TM3'}, 'TextColor', 'white');
xlabel('Time [s]'); ylabel('Torque [Nm]');
title('Torque-Vector');