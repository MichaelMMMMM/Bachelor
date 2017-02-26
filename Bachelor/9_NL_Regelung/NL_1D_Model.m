%25.02.2017, Michael Meindl, Berechnung und Analyse des nichtlinearen
%Modells zur Beschreibung der Wuerfelseite

l_M   = 0.084;
l_AC  = 0.087;
m_r   = 0.09;
m_k   = 0.221;
m   = m_r + m_k;
l_C   = (l_M*m_r+l_AC*m_k)/m_g;
I_KO  = 2.8e-3;
I_RM  = 1.1683e-4;
I_GO  = I_KO+I_RM+m_r*l_M^2;
C_psi = 3.1176e-5;
g     = 9.81;

k = [-0.9120, -0.0773, -0.0001];

x_0 = degtorad([3;0;0]);

u_max = 0.07;
