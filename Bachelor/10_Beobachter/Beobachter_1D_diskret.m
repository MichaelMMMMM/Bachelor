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
C = [0, 1, 0;0,0,1]; D = [0];
%C = eye(3);

Ta = 0.02;
mySS = ss(A, B, C, D);
mySS = c2d(mySS, Ta);
Q = [(degtorad(5))^(-2), 0, 0; 0, degtorad(30)^(-2), 0; 0, 0, 100^(-2)];
R = 0.07^(-2);
k = lqrd(A, B, Q, R, Ta); 

%Beobachter
Ad = mySS.A; Bd = mySS.B; Cd = mySS.C; D = mySS.D;
% SB = obsv(mySS);
% s_B = SB\[0;0;1];
% T_B = [s_B, Ad*s_B, Ad^2*s_B];
% 
 eig_max = min(abs(eig(Ad-Bd*k)));
% Ad_B = T_B\Ad*T_B; Bd_B = T_B\Bd; Cd_B = Cd*T_B;
% 
% 
% ew_sym = sym('l_sym', 'real');
% cPol_B = (ew_sym - eig_max^2)^3;
% 
% a_B_soll = [-0.0065, 0.104, -0.56];
% a_B_ist  = -(Ad_B(:,3))';

ew_beo = (eig_max^1.5)./[1;1.1;1.2];
Ld = (place(Ad', Cd', ew_beo))';

csvwrite('config/k_mat.csv', k);
csvwrite('config/L_mat.csv', Ld);
csvwrite('config/A_mat.csv', Ad);
csvwrite('config/B_mat.csv', Bd);
csvwrite('config/C_mat.csv', Cd);

y_noise = [0.0001; 0.0005];

R = eye(2)*y_noise(1)/Ta;

x_0 = degtorad([5;0;0]);
x_0_off = zeros(3,1);
P_P_0 = eye(3);

M_0 = zeros(3,3);
y_0 = Cd*x_0;

