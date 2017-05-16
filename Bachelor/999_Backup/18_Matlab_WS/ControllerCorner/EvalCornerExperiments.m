%27.04.2017, Michael Meindl
%Auswertung und Visualisierung der Reglerversuche

%---------------------------------------------------%
% Experiment 2.1                                    %
% Controller-Design:                                %
% qDiag = [1;1;1;1;1;1;1];                          %
% KKd = dlqr(KSSd.A, KSSd.B, diag(qDiag)*7e-4, R);  %
% Kd  = KKd * [eye(7), zeros(7,2)]/T_K;             %
%---------------------------------------------------%
filePath = 'measurements/Exp2_1/';
expFiles = {horzcat(filePath, 'phi.csv'), horzcat(filePath, 'uk.csv'),...
            horzcat(filePath, 'ur.csv'), horzcat(filePath, 'tm.csv')};

[t, phi2, phi3,...
 uk1, uk2, uk3,...
 ur1, ur2, ur3,...
 tm1, tm2, tm3] = plotMeasurementData(expFiles{1}, expFiles{2}, expFiles{3}, expFiles{4}, false);


n_s = 4.24/0.02;
n_e = 29.22/0.02;

emlFigure();
plot(t(n_s:n_e)-t(n_s), [phi2(n_s:n_e), phi3(n_s:n_e)]); grid;
emlTitle('Verlauf von $\overline{\varphi}$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$\overline{\varphi}_i$ in Radiant');
emlLegend({'$\overline{\varphi}_2$', '$\overline{\varphi}_3$'}, 'ne');
print('plots/exp1_phi.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [uk1(n_s:n_e), uk2(n_s:n_e), uk3(n_s:n_e)]); grid;
emlTitle('Verlauf von $u_K$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ki}$ in Radiant pro Sekunde');
emlLegend({'$u_{K1}$', '$u_{K2}$', '$u_{K3}$'}, 'ne');
print('plots/exp1_uk.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [ur1(n_s:n_e), ur2(n_s:n_e), ur3(n_s:n_e)]); grid;
emlTitle('Verlauf von $u_R$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ri}$ in Radiant pro Sekunde');
emlLegend({'$u_{R1}$', '$u_{R2}$', '$u_{R3}$'}, 'ne');
print('plots/exp1_ur.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [tm1(n_s:n_e), tm2(n_s:n_e), tm3(n_s:n_e)]); grid;
emlTitle(' Verlauf von $T_M$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_{Mi}$ in Newtonmeter');
emlLegend({'$T_{M1}$', '$T_{M2}$', '$T_{M3}$'}, 'ne');
print('plots/exp1_tm.eps', '-depsc');

%---------------------------------------------------%
% Experiment 2.2                                    %
% Controller-Design:                                %
% qDiag = [1;1;1;1;1;1;1];                          %
% KKd = dlqr(KSSd.A, KSSd.B, diag(qDiag)*7e-4, R);  %
% Kd  = KKd * [eye(7), zeros(7,2)]/T_K;             %
% Kd(:,3) = Kd(:,3) * 2;                            %
% Kd(1,4) = Kd(1,4) * 2;                            %
% Kd(2,5) = Kd(2,5) * 2;                            %
% Kd(3,6) = Kd(3,6) * 2;                            %
%---------------------------------------------------%
filePath = 'measurements/Exp2_2/';
expFiles = {horzcat(filePath, 'phi.csv'), horzcat(filePath, 'uk.csv'),...
            horzcat(filePath, 'ur.csv'), horzcat(filePath, 'tm.csv')};

[t, phi2, phi3,...
 uk1, uk2, uk3,...
 ur1, ur2, ur3,...
 tm1, tm2, tm3] = plotMeasurementData(expFiles{1}, expFiles{2}, expFiles{3}, expFiles{4}, false);

n_s = round(4.64/0.02);
n_e = 19.62/0.02;

emlFigure();
plot(t(n_s:n_e)-t(n_s), [phi2(n_s:n_e), phi3(n_s:n_e)]); grid;
emlTitle('Verlauf von $\overline{\varphi}$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$\overline{\varphi}_i$ in Radiant');
emlLegend({'$\overline{\varphi}_2$', '$\overline{\varphi}_3s$'}, 'ne');
print('plots/exp2_phi.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [uk1(n_s:n_e), uk2(n_s:n_e), uk3(n_s:n_e)]); grid;
emlTitle('Verlauf von $u_K$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ki}$ in Radiant pro Sekunde');
emlLegend({'$u_{K1}$', '$u_{K2}$', '$u_{K3}$'}, 'ne');
print('plots/exp2_uk.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [ur1(n_s:n_e), ur2(n_s:n_e), ur3(n_s:n_e)]); grid;
emlTitle('Verlauf von $u_R$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ri}$ in Radiant pro Sekunde');
emlLegend({'$u_{R1}$', '$u_{R2}$', '$u_{R3}$'}, 'ne');
print('plots/exp2_ur.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [tm1(n_s:n_e), tm2(n_s:n_e), tm3(n_s:n_e)]); grid;
emlTitle('Verlauf von $T_M$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_{Mi}$ in Newtonmeter');
emlLegend({'$T_{M1}$', '$T_{M2}$', '$T_{M3}$'}, 'ne');
print('plots/exp2_tm.eps', '-depsc');