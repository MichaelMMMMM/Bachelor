%25.02.2017, Michael Meindl, Berechnung und Analyse des nichtlinearen
%Modells zur Beschreibung der Wuerfelseite

close all;

l_M   = 0.084;
l_AC  = 0.087;
m_r   = 0.09;
m_k   = 0.221;
m   = m_r + m_k;
l_C   = (l_M*m_r+l_AC*m_k)/m;
I_KO  = 2.8e-3;
I_RM  = 1.1683e-4;
I_GO  = I_KO+I_RM+m_r*l_M^2;
C_psi = 3.1176e-5;
g     = 9.81;

k = [-0.9120, -0.0773, -0.0001];

u_max = 0.035;
phi0 = degtorad(-10:1:10);
n    = length(phi0);

stop_time = 1;

x_offset = zeros(3,1);
x_noise  = zeros(3,1);

NL_1D_Model_u_unlimited;
NL_1D_Model_u_limited;
NL_1D_Model_u_limited_offset;
NL_1D_Model_u_limited_noise;
