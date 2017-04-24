ParameterInit;

x_max = [degtorad(15); degtorad(60); 500*2*pi/60];
Q     = diag(x_max.^(-2));
u_max = 0.11;
R     = diag(u_max.^(-2));

Kd    = dlqr(SSd.A, SSd.B, Q, R);

csvwrite('config/Edge_Kd.csv', Kd);

%Phi-Observer
load_measurements;
R = cov(x2_comp-mean(x2_comp), x3_comp-mean(x3_comp));
Q     = diag([100,1,10000000])*4e-10;
Ld    = (dlqr(SSd.A', SSd.C', Q, R))';

csvwrite('config/Edge_Ad.csv', SSd.A);
csvwrite('config/Edge_Bd.csv', SSd.B);
csvwrite('config/Edge_Cd.csv', SSd.C);
csvwrite('config/Edge_Ld.csv', Ld);

%Offset-Observer
Ko = [Kd, Kd];
Ao = [SSd.A, zeros(3,3); zeros(3,3), eye(3)];
Bo = [SSd.B; zeros(3,1)];
Co = [eye(3), eye(3)];
Do = [zeros(3,1)];
SSo = ss(Ao, Bo, Co, Do, 0.02);

Ago = Ao-Bo*Ko;

tmp = [(x1_comp-mean(x1_comp))'; (x2_comp-mean(x2_comp))'; (x3_comp-mean(x3_comp))'];
R   = cov(tmp');
Q   = diag([1, 1, 1, 1, 1, 1]);

Lo  = dlqr(Ao', Co', Q, R)';

csvwrite('config/Edge_Ao.csv', Ao);
csvwrite('config/Edge_Bo.csv', Bo);
csvwrite('config/Edge_Co.csv', Co);
csvwrite('config/Edge_Lo.csv', Lo);