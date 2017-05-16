%-------------------------------------------------------------------------%
% 03.01.2017, Michael Meindl                                              %
% Script to design the controller and observer for balancing on the edge. %
%-------------------------------------------------------------------------%
ParameterInit;

% Controller-Design
x_max = [degtorad(15); degtorad(60); 500*2*pi/60];
Q     = diag(x_max.^(-2));
u_max = 0.11;
R     = diag(u_max.^(-2));
Kd    = dlqr(SSd.A, SSd.B, Q, R);
csvwrite('config/Edge_Kd.csv', Kd);

% Phi-Observer-Design
R     = eye(2);
Q     = diag([1,1,10000000])*4e-10;
Ld    = (dlqr(SSd.A', SSd.C', Q, R))';

csvwrite('config/Edge_Ad.csv', SSd.A);
csvwrite('config/Edge_Bd.csv', SSd.B);
csvwrite('config/Edge_Cd.csv', SSd.C);
csvwrite('config/Edge_Ld.csv', Ld);
