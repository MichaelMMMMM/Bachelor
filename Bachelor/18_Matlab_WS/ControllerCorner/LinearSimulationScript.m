%25.04.2017, Michael Meindl
%Simulation des linearen Modells bei unbeschränkten Stellgrößen
%Bei dem Reglerentwurf werden die Stellgrößen nicht beachtet

%Initialise the parameters required for the simulation
SimulinkInit;

Kd = K_unlimited;

%-----------------------------------------%
%first Simulation
%-----------------------------------------%
x0 = [0; 0.11; 0.08; zeros(6,1)];

stop_time = 10;
sim('LIN_Corner.slx');

t_x = x_sim.time;
phi = x_sim.signals.values(:,1:3);
uK  = x_sim.signals.values(:,4:6);
uR  = x_sim.signals.values(:,7:9);
t_u = u_sim.time;
tm  = u_sim.signals.values;

emlFigure();
plot(t_x, phi); grid;
emlTitle('Verlauf von $\overline{\varphi}$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$\overline{\varphi}_i$ in Radiant');
emlLegend({'$\varphi_1$', '$\varphi_2$', '$\varphi_3$'});
print('plots/lin_sim1_phi.eps', '-depsc');

emlFigure();
plot(t_x, uK); grid;
emlTitle('Verlauf von $u_K$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ki}$ in Radiant pro Sekunde');
emlLegend({'$u_{K1}$', '$u_{K2}$', '$u_{K3}$'}, 'ne');
print('plots/lin_sim1_uk.eps', '-depsc');

emlFigure();
plot(t_x, uR); grid;
emlTitle('Verlauf von $u_R$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ri}$ in Radiant pro Sekunde');
emlLegend({'$u_{R1}$', '$u_{R2}$', '$u_{R3}$'}, 'se');
print('plots/lin_sim1_ur.eps', '-depsc');

emlFigure();
plot(t_u, tm); grid;
emlTitle('Verlauf von $T_M$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_{Mi}$ in Newtonmeter');
emlLegend({'$T_{M1}$', '$T_{M2}$', '$T_{M3}$'}, 'se');
print('plots/lin_sim1_tm.eps', '-depsc');

%---------------------------------------------%
% Second Simulation
%---------------------------------------------%
x0 = [0; 0.11; 0.08; 0; 1; -2; 3; -16; 0];
sim('LIN_Corner.slx');

t_x = x_sim.time;
phi = x_sim.signals.values(:,1:3);
uK  = x_sim.signals.values(:,4:6);
uR  = x_sim.signals.values(:,7:9);
t_u = u_sim.time;
tm  = u_sim.signals.values;

emlFigure();
plot(t_x, phi); grid;
emlTitle('Verlauf von $\overline{\varphi}$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$\overline{\varphi}_i$ in Radiant');
emlLegend({'$\varphi_1$', '$\varphi_2$', '$\varphi_3$'}, 'sw');
print('plots/lin_sim2_phi.eps', '-depsc');

emlFigure();
plot(t_x, uK); grid;
emlTitle('Verlauf von $u_K$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ki}$ in Radiant pro Sekunde');
emlLegend({'$u_{K1}$', '$u_{K2}$', '$u_{K3}$'}, 'ne');
print('plots/lin_sim2_uk.eps', '-depsc');

emlFigure();
plot(t_x, uR); grid;
emlTitle('Verlauf von $u_R$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ri}$ in Radiant pro Sekunde');
emlLegend({'$u_{R1}$', '$u_{R2}$', '$u_{R3}$'}, 'se');
print('plots/lin_sim2_ur.eps', '-depsc');

emlFigure();
plot(t_u, tm); grid;
emlTitle('Verlauf von $T_M$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_{Mi}$ in Newtonmeter');
emlLegend({'$T_{M1}$', '$T_{M2}$', '$T_{M3}$'}, 'se');
print('plots/lin_sim2_tm.eps', '-depsc');
