%28.11.2016, Michael Meindl, Berechnung der Fundamental- und
%Übertragungsmatrix des offenen Regelkreises

clear; close all;

%Systemvalues
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

a1 = (m_g*g*l_C)/(I_KO+m_r*l_M^2);
a2 = -C_phi/(I_KO+m_r*l_M^2);
a3 = C_psi/(I_KO+m_r*l_M^2);
a4 = (-I_GO*C_psi)/(I_RM*(I_KO+m_r*l_M^2));

b1 = -1/(I_KO+m_r*l_M^2);
b2 = I_GO/(I_RM*(I_KO+m_r*l_M^2));

A = [0, 1, 0; a1, a2, a3; -a1, -a2, a4];
B = [0;b1;b2];
C = [1, 0, 0; 0, 0, 1];
D = [0; 0];

%Laplacetransformierte der Fundamentalmatrix und Übertragungsmatrix als sym
syms s;
sFMat  = inv(s*eye(3)-A);
sG = C*sFMat*B;

%Laplacetransformierte der Übertragungsmatrix als tf
[nom,den] = ss2tf(A,B,C,D);
tfG = [tf(nom(1,:),den);tf(nom(2,:),den)];
