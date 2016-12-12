%29.11.2016, Michael Meindl, Zustandsrückführung nach LQR

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

%Define the max values
Tmax       = 0.071;
phiKmax    = degtorad(7);
phiK_dmax = degtorad(180);
phiR_dmax = degtorad(360*1000);

R = 1/(Tmax^2);
Q = [1/(phiKmax^2) 0 0;0 1/(phiK_dmax^2) 0; 0 0 1/(phiR_dmax^2)];

%Berechnung der Filtermatrix F
F = lqr(A,B,Q,R);
%Matrizen der ZRD des geschlossenen Regelkreises
Ag = A-B*F;
Cg = C;
Dg = [0,0;0,0];
%Pole des geschlossenen Regelkreises
syms s;
sP = vpa(det(s*eye(3)-Ag),3);
polesGRK = vpa(solve(sP==0),3);
%Vorfilter des geschlossenen Regelkreises
V = pinv(C/(B*F-A)*B);
Bg = B*V;

%Fundamentalmatrix im Bildbereich des geschlossenen Regelkreises
sFMat = inv(s*eye(3)-A+B*(-F));
sG    = Cg*sFMat*Bg;
ssZRD = ss(Ag,Bg,Cg,Dg);

%Simulation und Plot der homogenen Lösung
x0     = [degtorad(5);0;0];
[y,t]  = initial(ssZRD, x0);
t      = t';
phi    = (y(:,1))';
psi__d = (y(:,2))';

figure; plot(t(1:2000), radtodeg(phi(1:2000))); grid; xlabel('Zeit [s]', 'interpreter', 'latex');
ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
title('Verlauf von $\varphi$ bei  $\varphi_0=5^\circ$', 'interpreter', 'latex');
%print('plots/x0_phi', '-depsc');

figure; plot(t, radtodeg(psi__d)); grid; xlabel('Zeit [s]', 'interpreter', 'latex');
ylabel('$\dot{\psi} [^\circ/s]$', 'interpreter', 'latex');
title('Verlauf von $\dot{\psi}$ bei $\varphi_0=5^\circ$', 'interpreter', 'latex');
%print ('plots/x0_psi__d', '-depsc');

%Kaskadierter Regelkreis
F1 = sym('F1', 'real');
F2 = sym('F2', 'real');
F_  = [0, 0; F1, F2];

Ac = Ag+Bg*F_*Cg;
P  = det(s*eye(3)-Ac);
myPoles = solve(P==0);
FMatc = inv(s*eye(3)-Ac);
yFMatc = collect(C*FMatc);


p1 = myPoles(1);
p2 = myPoles(2);
p3 = myPoles(3);

F1vals = -50:1:50;
F2vals = (F1vals)';

 p1Vals = vpa(subs(p1, F1, F1vals),3);
 p1Vals = vpa(subs(p1Vals, F2, F2vals),3);
 p2Vals = vpa(subs(p2, F1, F1vals),3);
 p2Vals = vpa(subs(p2Vals, F2, F2vals),3);
 p3Vals = vpa(subs(p3, F1, F1vals),3);
 p3Vals = vpa(subs(p3Vals, F2, F2vals),3);
 
 [X,Y] = meshgrid(F1vals);
 figure; mesh(X,Y,double(real(p1Vals))); title('Pol 1 Verlauf');
 xlabel('F1'); ylabel('F2'); zlabel('Realteil Pol 1');
 figure; mesh(X,Y,double(real(p2Vals))); title('Pol 2 Verlauf');
 xlabel('F1'); ylabel('F2'); zlabel('Realteil Pol 2');
 figure; mesh(X,Y,double(real(p3Vals))); title('Pol 3 Verlauf');
 xlabel('F1'); ylabel('F2'); zlabel('Realteil Pol 3');


F_ = [0,0;0,-17];
Ac = Ag+Bg*F_*Cg;
Bc = [0,0;0,0;0,0];
Cc = Cg;
Dc = Dg;


ssRKc = ss(Ac,Bc,Cc,Dc);
%Simulation und Plot der homogenen Lösung
x0     = [degtorad(5);0;0];
[y,t]  = initial(ssRKc, x0);
t      = t';
phi    = (y(:,1))';
psi__d = (y(:,2))';

figure; plot(t, radtodeg(phi)); grid; xlabel('Zeit [s]', 'interpreter', 'latex');
ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
title('Verlauf von $\varphi$ bei  $\varphi_0=5^\circ$', 'interpreter', 'latex');
print('plots/x0_phi_kaskadiert', '-depsc');

figure; plot(t, radtodeg(psi__d)); grid; xlabel('Zeit [s]', 'interpreter', 'latex');
ylabel('$\dot{\psi} [^\circ/s]$', 'interpreter', 'latex');
title('Verlauf von $\dot{\psi}$ bei $\varphi_0=5^\circ$', 'interpreter', 'latex');
print ('plots/x0_psi__d_kaskadiert', '-depsc');