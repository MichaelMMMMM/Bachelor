%22.11.16, Michael Meindl, Berechnung Fundamentalmatrix und
%Übertragungsmatrix des offenen Regelkreises

clear; close all;

syms a1 a2 a3 a4 b1 b2 s t;

A = [0 1 0; a1 a2 a3; -a1 -a2 a4]; B = [0; b1; b2]; C = [1 0 0; 0 0 1]; D = 0;

FMat = inv(s*eye(3)-A);

G        = C*FMat*B+D;
%G        = C*(s*eye(3)-A)*B+D;
G_phi    = simplify(G(1));
G_psi__d = simplify(G(2));

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

a_subs = [(m_g*g*l_C)/(I_KO+m_r*l_M^2), (-C_phi)/(I_KO+m_r*l_M^2), ...
          (C_psi)/(I_KO+m_r*l_M^2), (-I_GO*C_psi)/(I_RM*(I_KO+m_r*l_M^2))];
b_subs = [(-1)/(I_KO+m_r*l_M^2), (I_GO)/(I_RM*(I_KO+m_r*l_M^2))];
      
%Setup nominator and denomiantor of the transfer functions for the partial
%expansion
nom_phi = [b_subs(1) -a_subs(3)*b_subs(2)+a_subs(4)*b_subs(1)];
den_phi = [1, (-a_subs(2)-a_subs(4)),...
           (a_subs(2)*a_subs(3)+a_subs(2)*a_subs(4)-a_subs(1)),...
           (a_subs(1)*a_subs(3)+a_subs(1)*a_subs(4))];
       
nom_psi = -[-b_subs(2), ...
            (a_subs(2)*b_subs(1)+a_subs(2)*b_subs(2)),...
            (a_subs(1)*b_subs(1)+a_subs(1)*b_subs(2))];
den_psi = den_phi;

[r_phi, p_phi, k_phi] = residue(nom_phi, den_phi);
[r_psi, p_psi, k_psi] = residue(nom_psi, den_psi);

G_phi = 0;
G_psi = 0;

for k = 1:length(r_phi)
    G_phi = G_phi + r_phi(k)/(s-p_phi(k));
    G_psi = G_psi + r_psi(k)/(s-p_psi(k));
end

FMat = subs(FMat, [a1 a2 a3 a4], a_subs);
