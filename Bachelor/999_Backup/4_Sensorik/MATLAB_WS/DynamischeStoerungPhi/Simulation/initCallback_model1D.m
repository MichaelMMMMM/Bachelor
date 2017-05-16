%Michael Meindl, 8.8.2016
%Skript zur Initialisierung des Modell "model_1D.slx", setzt die Werte von
%konstanten Systemgrößen und Anfangswerte der Zustandsgrößen

%Konstante Parameter
C_phi       = 6.2e-3;
C_psi       = 3.1176e-5;
l_AB        = 0.084;
l_AC        = 0.087;
m_K         = 0.221;
m_R         = 0.09;
I_KO        = 2.8e-3;
I_RM        = 1.1683e-4;
I_GO        = I_KO + I_RM + m_R * l_AB^2;
g           = 9.81;
T_M_e       = 5.5e-4;
T_M_m       = 12.4e-3;

%Anfangswerte der Zustandsgrößen
phi_off     = -degtorad(6.7768);
phi_0       = degtorad(6.7768);
phi__d_0    = 0;
phi__dd_0   = 0;
psi_0       = 0;
psi__d_0    = 0;
psi__dd_0   = 0;
