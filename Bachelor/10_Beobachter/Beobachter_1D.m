%1.3.2017, Michael Meindl, Entwurf Beobachter für 1D-Modell

l_M   = 0.084;
l_AC  = 0.087;
m_r   = 0.09;
m_k   = 0.221;
m_g   = m_r + m_k;
l_C   = (l_M*m_r+l_AC*m_k)/m_g;
I_KO  = 2.8e-3;
I_RM  = 1.1683e-4;
I_GO  = I_KO+I_RM+m_r*l_M^2;
C_phi = 6.2e-3;
C_psi = 3.1176e-5;
g     = 9.81;

I_G   = I_KO+m_r*l_M^2;
I_R   = I_RM;
m = m_g;

A = [0, 1, 0; (m*g*l_C)/I_G, (-C_phi-C_psi)/I_G, C_psi/I_G; 0, C_psi/I_R, -C_psi/I_R];
B = [0; -1/I_G; 1/I_R];
C = [0, 1, 0]; D = [0];

mySS = ss(A, B, C, D);
[Ab, Bb, Cb, T, K] = obsvf(A, B, C);
l = sym('l', [3 1], 'real');

Q = [(degtorad(10))^(-2), 0, 0; 0, degtorad(30)^(-2), 0; 0, 0, 100^(-2)];
R = 0.7^(-2);
k = lqr(A, B, Q, R); 
eig_max_cl = min(real(eig(A-B*k)));

%RNF
Ss = ctrb(mySS);
s_T_R = [0, 0, 1]*inv(Ss);
T_R   = inv([s_T_R; s_T_R*A; s_T_R*A^2]);

A_R = T_R\A*T_R;
B_R = T_R\B;
C_R = C*T_R;
D_R = D;

%BNF
Sb = obsv(mySS);
s_B = Sb\[0;0;1];
T_B = [s_B, A*s_B, A^2*s_B];

A_B = T_B\A*T_B;
B_B = T_B\B;
C_B = C*T_B;
D_B = D;

%Beobachter
ew_soll = eig_max_cl*3;
ew_sym  = sym('ew');
cPol_B  = (ew_sym-ew_soll)^3;

a_B_soll = [1.65e+9, 4.19e+6, 3555];
a_B_ist  = -(A_B(:,3))';

L = (a_B_soll - a_B_ist)';