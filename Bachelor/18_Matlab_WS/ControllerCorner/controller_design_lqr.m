ParameterInit;

[KSSd, T_K] = minreal(SSd);
T_K         = inv(T_K);     %Matlab things

T_max = 0.1;
R = eye(3)*T_max^(-2);
xMax = [0; degtorad(5); degtorad(5); degtorad(10)*ones(3,1); 500*ones(3,1)]*5;
xMax = [eye(7), zeros(7,2)]/T_K*xMax;
Q_max = diag(xMax)^(-2);
K_unlimited = dlqr(KSSd.A, KSSd.B, Q_max, R) * [eye(7), zeros(7,2)]/T_K;
K_limited   = dlqr(KSSd.A, KSSd.B, Q_max,R) * [eye(7), zeros(7,2)]/T_K;
K_fixed     = K_limited;
K_fixed(:,3) = K_fixed(:,3)*1.8;
K_fixed(1,4) = K_fixed(1,4)*2;
K_fixed(2,5) = K_fixed(2,5)*2;
K_fixed(3,6) = K_fixed(3,6)*2;


qDiag = [1;1;1;1;1;1;1];
KKd = dlqr(KSSd.A, KSSd.B, diag(qDiag)*7e-4, R);
Kd  = KKd * [eye(7), zeros(7,2)]/T_K;
% Kd(:,3) = Kd(:,3) * 2;
% Kd(1,4) = Kd(1,4) * 2;
% Kd(2,5) = Kd(2,5) * 2;
% Kd(3,6) = Kd(3,6) * 2;
KKTest = [KKd, ones(3,1)*0.5];

csvwrite('config/Corner_Kd.csv', Kd);

%Open loop system
A = SSd.A; B = SSd.B; C = [zeros(8,1),eye(8)];
A_K = T_K\A*T_K; B_K = T_K\B; C_K = C*T_K;
%[V, J] = jordan(A);
load('system_data/V_J_opensys.mat');

%Closed loop system
Ag = A-B*Kd; Bg = B; Cg = C; Dg = zeros(8,3);
SSg = ss(Ag, Bg, Cg, Dg, Ta);
[KSSg, T_Kg] = minreal(SSg);
T_Kg = inv(T_Kg); %Matlab things
Ag_K = T_Kg\Ag*T_Kg; Bg_K = T_Kg\Bg;
