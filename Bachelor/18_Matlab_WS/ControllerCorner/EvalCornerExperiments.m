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
emlTitle('Versuch 1: Verlauf von $\overline{\varphi}$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$\overline{\varphi}_i$ in Radiant');
emlLegend({'$\overline{\varphi}_1$', '$\overline{\varphi}_2$'}, 'ne');
print('plots/exp1_phi.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [uk1(n_s:n_e), uk2(n_s:n_e), uk3(n_s:n_e)]); grid;
emlTitle('Versuch 1: Verlauf von $u_K$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ki}$ in Radiant pro Sekunde');
emlLegend({'$u_{K1}$', '$u_{K2}$', '$u_{K3}$'}, 'ne');
print('plots/exp1_uk.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [ur1(n_s:n_e), ur2(n_s:n_e), ur3(n_s:n_e)]); grid;
emlTitle('Versuch 1: Verlauf von $u_R$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ri}$ in Radiant pro Sekunde');
emlLegend({'$u_{R1}$', '$u_{R2}$', '$u_{R3}$'}, 'ne');
print('plots/exp1_ur.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [tm1(n_s:n_e), tm2(n_s:n_e), tm3(n_s:n_e)]); grid;
emlTitle('Versuch 1: Verlauf von $T_M$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_{Mi}$ in Newtonmeter');
emlLegend({'$T_{M1}$', '$T_{M2}$', '$T_{M3}$'}, 'ne');
print('plots/exp1_tm.eps', '-depsc');

%Spektral plots
PHI2 = fftshift(fft(xcorr(phi2)));
PHI3 = fftshift(fft(xcorr(phi3)));
UK1  = fftshift(fft(xcorr(uk1)));
UK2  = fftshift(fft(xcorr(uk2)));
UK3  = fftshift(fft(xcorr(uk3)));
UR1  = fftshift(fft(xcorr(ur1)));
UR2  = fftshift(fft(xcorr(ur2)));
UR3  = fftshift(fft(xcorr(ur3)));
TM1  = fftshift(fft(xcorr(tm1)));
TM2  = fftshift(fft(xcorr(tm2)));
TM3  = fftshift(fft(xcorr(tm3)));
n  = length(PHI2);
fa = 50;
df = fa/n;
f  = -fa/2+df/2:df:fa/2-df/2;

emlFigure(); stem(f, abs(PHI2)); grid;
emlTitle('LDS-Spektrum von $\varphi_2$');
emlFigure(); stem(f, abs(PHI3)); grid;
emlTitle('LDS-Spektrum von $\varphi_3$');
emlFigure(); stem(f, abs(UK1)); grid;
emlTitle('LDS-Spektrum von $u_{K1}$');
emlFigure(); stem(f, abs(UK2)); grid;
emlTitle('LDS-Spektrum von $u_{K2}$');
emlFigure(); stem(f, abs(UK3)); grid;
emlTitle('LDS-Spektrum von $u_{K3}$');
emlFigure(); stem(f, abs(UR1)); grid;
emlTitle('LDS-Spektrum von $u_{R1}$');
emlFigure(); stem(f, abs(UR2)); grid;
emlTitle('LDS-Spektrum von $u_{R2}$');
emlFigure(); stem(f, abs(UR3)); grid;
emlTitle('LDS-Spektrum von $u_{R3}$');
emlFigure(); stem(f, abs(TM1)); grid;
emlTitle('LDS-Spektrum von $T_{M1}$');
emlFigure(); stem(f, abs(TM2)); grid;
emlTitle('LDS-Spektrum von $T_{M2}$');
emlFigure(); stem(f, abs(TM3)); grid;
emlTitle('LDS-Spektrum von $T_{M3}$');

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
emlTitle('Versuch 2: Verlauf von $\overline{\varphi}$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$\overline{\varphi}_i$ in Radiant');
emlLegend({'$\overline{\varphi}_1$', '$\overline{\varphi}_2$'}, 'ne');
print('plots/exp2_phi.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [uk1(n_s:n_e), uk2(n_s:n_e), uk3(n_s:n_e)]); grid;
emlTitle('Versuch 2: Verlauf von $u_K$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ki}$ in Radiant pro Sekunde');
emlLegend({'$u_{K1}$', '$u_{K2}$', '$u_{K3}$'}, 'ne');
print('plots/exp2_uk.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [ur1(n_s:n_e), ur2(n_s:n_e), ur3(n_s:n_e)]); grid;
emlTitle('Versuch 2: Verlauf von $u_R$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_{Ri}$ in Radiant pro Sekunde');
emlLegend({'$u_{R1}$', '$u_{R2}$', '$u_{R3}$'}, 'ne');
print('plots/exp2_ur.eps', '-depsc');

emlFigure();
plot(t(n_s:n_e)-t(n_s), [tm1(n_s:n_e), tm2(n_s:n_e), tm3(n_s:n_e)]); grid;
emlTitle('Versuch 2: Verlauf von $T_M$');
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_{Mi}$ in Newtonmeter');
emlLegend({'$T_{M1}$', '$T_{M2}$', '$T_{M3}$'}, 'ne');
print('plots/exp2_tm.eps', '-depsc');