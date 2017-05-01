ParameterInit;

x_max = [degtorad(15); degtorad(60); 500*2*pi/60];
Q     = diag(x_max.^(-2));
u_max = 0.11;
R     = diag(u_max.^(-2));

Kd    = dlqr(SSd.A, SSd.B, Q, R);

csvwrite('config/Edge_Kd.csv', Kd);

%Phi-Observer
load_measurements;
R = cov((x2_comp-mean(x2_comp))*1e+3, x3_comp-mean(x3_comp));
Q     = diag([1,1,10000000])*4e-10;
Ld    = (dlqr(SSd.A', SSd.C', Q, R))';

csvwrite('config/Edge_Ad.csv', SSd.A);
csvwrite('config/Edge_Bd.csv', SSd.B);
csvwrite('config/Edge_Cd.csv', SSd.C);
csvwrite('config/Edge_Ld.csv', Ld);

%Filter-Observer
q = [1, 1, 1];
r = [0.01; 1; 1000];
L_full = (dlqr(SSd.A', eye(3), diag(q), diag(r)))';

csvwrite('config/Edge_Afull.csv', SSd.A);
csvwrite('config/Edge_Bfull.csv', SSd.B);
csvwrite('config/Edge_Cfull.csv', eye(3));
csvwrite('config/Edge_Lfull.csv', L_full);