%01.05.2017, Michael Meindl
%Auswertung der Experimente beim Balancieren auf einer Kante

%-------------------------------------------------------------------------%
%Experiment 1, Komplementär-Filter + LQR ohne Offset-Korrektur            %
%-------------------------------------------------------------------------%
[t1, x1, tbd1, tbd2] = importX1('measurements/Experiment1/edge_x1.csv');
[t2, x2, tbd1, tbd2] = importX2('measurements/Experiment1/edge_x2.csv');
[t3, x3, tbd1, tbd2] = importX3('measurements/Experiment1/edge_x3.csv');
[t4, u, tbd1, tbd2]  = importU('measurements/Experiment1/edge_u.csv');

na = 6/0.02;
ne = 10/0.02 - 1;
t = t1(na:ne)-t1(na);
emlFigure();
plot(t, x1(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$\varphi$ in Radiant');
emlTitle('Verlauf von $x_1$ bzw. $\varphi$');
print('plots/edge_exp1_phi.eps', '-depsc');

emlFigure();
plot(t, x2(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_K$ in Radiant pro Sekunde');
emlTitle('Verlauf von $x_2$ bzw. $u_K$');
print('plots/edge_exp1_uk.eps', '-depsc');

emlFigure();
plot(t, x3(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_R$ in Radiant pro Sekunde');
emlTitle('Verlauf von $x_3$ bzw. $u_R$');
print('plots/edge_exp1_ur.eps', '-depsc');

emlFigure();
plot(t, u(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_M$ in Newtonmeter');
emlTitle('Verlauf von $u$ bzw. $T_M$');
print('plots/edge_exp1_tm.eps', '-depsc');

%-------------------------------------------------------------------------%
%Experiment 2, Komplementär-Filter + LQR mit Offset-Korrektur             %
%-------------------------------------------------------------------------%
[t1, x1, tbd1, tbd2] = importX1('measurements/Experiment2/edge_x1.csv');
[t2, x2, tbd1, tbd2] = importX2('measurements/Experiment2/edge_x2.csv');
[t3, x3, tbd1, tbd2] = importX3('measurements/Experiment2/edge_x3.csv');
[t4, u, tbd1, tbd2]  = importU('measurements/Experiment2/edge_u.csv');

na = 12/0.02;
ne = 21/0.02 -2;
t = t1(na:ne);
emlFigure();
plot(t, x1(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$\varphi$ in Radiant');
emlTitle('Verlauf von $x_1$ bzw. $\varphi$');
print('plots/edge_exp2_phi.eps', '-depsc');

emlFigure();
plot(t, x2(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_K$ in Radiant pro Sekunde');
emlTitle('Verlauf von $x_2$ bzw. $u_K$');
print('plots/edge_exp2_uk.eps', '-depsc');

emlFigure();
plot(t, x3(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_R$ in Radiant pro Sekunde');
emlTitle('Verlauf von $x_3$ bzw. $u_R$');
print('plots/edge_exp2_ur.eps', '-depsc');

emlFigure();
plot(t, u(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_M$ in Newtonmeter');
emlTitle('Verlauf von $u$ bzw. $T_M$');
print('plots/edge_exp2_tm.eps', '-depsc');

%-------------------------------------------------------------------------%
%Experiment 3, Phi-Beobachter + LQR                                       %
%-------------------------------------------------------------------------%
[t1, tbd1, x1, tbd2] = importX1('measurements/Experiment3/edge_x1.csv');
[t2, tbd1, x2, tbd2] = importX2('measurements/Experiment3/edge_x2.csv');
[t3, tbd1, x3, tbd2] = importX3('measurements/Experiment3/edge_x3.csv');
[t4, tbd1, u, tbd2]  = importU('measurements/Experiment3/edge_u.csv');

na = 6/0.02;
ne = 18/0.02 - 1;
t = t1(na:ne) - t1(na);
emlFigure();
plot(t, x1(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$\varphi$ in Radiant');
emlTitle('Verlauf von $x_1$ bzw. $\varphi$');
print('plots/edge_exp3_phi.eps', '-depsc');

emlFigure();
plot(t, x2(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_K$ in Radiant pro Sekunde');
emlTitle('Verlauf von $x_2$ bzw. $u_K$');
print('plots/edge_exp3_uk.eps', '-depsc');

emlFigure();
plot(t, x3(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$u_R$ in Radiant pro Sekunde');
emlTitle('Verlauf von $x_3$ bzw. $u_R$');
print('plots/edge_exp3_ur.eps', '-depsc');

emlFigure();
plot(t, u(na:ne)); grid;
emlXLabel('Zeit in Sekunden');
emlYLabel('$T_M$ in Newtonmeter');
emlTitle('Verlauf von $u$ bzw. $T_M$');
print('plots/edge_exp3_tm.eps', '-depsc');