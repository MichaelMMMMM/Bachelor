%14.12.16, Michael Meindl, Entwurf des diskreten Reglers

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

contSys = ss(A,B,C,D);
opt     = c2dOptions('Method', 'zoh'); %Halteglied nullter Ordnung fuer diskretisierung
fa      = 50; Ta = 1/fa;
discSys = c2d(contSys, Ta, opt);

Ad = discSys.A;
Bd = discSys.B;
Cd = discSys.C;
Dd = discSys.D;

z = sym('z');
z_i_oRK = pole(discSys);

%Define the max values
Tmax       = 0.071;
phiKmax    = degtorad(7);
phiK_dmax = degtorad(180);
phiR_dmax = degtorad(360*1000);

R = 1/(Tmax^2);
Q = [1/(phiKmax^2) 0 0;0 1/(phiK_dmax^2) 0; 0 0 1/(phiR_dmax^2)];

Fd = dlqr(Ad,Bd,Q,R);
Vd = pinv(Cd/(Bd*Fd-Ad)*Bd);

%ZRD geschlossener Regelkreis
Adg = Ad-Bd*Fd;
Bdg = Bd*Vd;
Cd  = C;
Dd  = [0, 0; 0, 0];

discSys_gRK = ss(Adg, Bdg, Cd, Dd, Ta);
z_i_gRK     = pole(discSys_gRK);

x0 = [degtorad(5); 0; 0];
initial(discSys_gRK, x0);

%Kaskadiertert Regelkreis
%F2 = sym('F2', 'real');
Fvals = -2:0.001:2;
n = length(Fvals);
z_i_cRK_cell = cell(1,n);

z1 = zeros(1,n);
z2 = zeros(1,n);
z3 = zeros(1,n);

for k = 1:n
    F_  = [0, 0; 0,Fvals(k)];
    Adc = Adg+Bdg*F_*Cd;
    Bdc = [0, 0; 0, 0; 0, 0];
    discSys_cRK = ss(Adc, Bdc, Cd, Dd, Ta);
    myPoles = pole(discSys_cRK);
    z1(k) = myPoles(1);
    z2(k) = myPoles(2);
    z3(k) = myPoles(3);
end

subplot(3,1,1);
plot(Fvals, abs(z1)); grid;
subplot(3,1,2);
plot(Fvals, abs(z2)); grid;
subplot(3,1,3);
plot(Fvals, abs(z3)); grid;
