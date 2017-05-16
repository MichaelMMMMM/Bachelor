function DoppelPendel (phi1Anf , phi2Anf)

if nargin == 2                          % Start mit vorgegebenen Anfangswerten?
   x0 = [phi1Anf ; phi2Anf ; 0 ; 0] ;   % Anfangswerte  [phi1 ; phi2 ; omega1 ; omega2]
else
   x0 = [pi/2 ; 0 ; 0 ; 0] ;            % Default-Anfangswerte
end

% Parameter (global definiert, damit Wertaenderung nur an einer Stelle erforderlich):
global mdm  J1  J2  s1  s2  gdl 
mdm = 1 ; J1 = 1./12 ; J2 = 1./12 ; s1 = .5 ; s2  = .5 ; gdl = 9.81 ; 

tspan = [0 ; 10] ;                       % Zeitintervall

% Integration des Anfangswertproblems:
options = odeset('Mass' , @Massenmatrix , 'MaxStep' , 0.01) ; 
[t xv]  = ode45 (@RechteSeite , tspan , x0 , options) ;

% Grafische Ausgabe von phi1 und phi2, zunaechst "Sortieren der Ergebnisse":
phi1 = xv(:,1) ; 
phi2 = xv(:,2) ;                         % phi1i und phi2i sind Vektoren 

subplot(2,1,1) ; plot (t , phi1) , grid on , title  ('\phi_1(t) (oberes Pendel)')
subplot(2,1,2) ; plot (t , phi2) , grid on , title  ('\phi_2(t) (unteres Pendel)')

% ============================================================
% Funktion, die die "Massenmatrix" des Dgl.-Systems definiert: 
function M = Massenmatrix (t , xv)

global mdm  J1  J2  s1  s2  gdl 

phi1   = xv(1) ;
phi2   = xv(2) ;
omega1 = xv(3) ;
omega2 = xv(4) ;

c = cos(phi1-phi2);
M = [ 1  0      0             0      ; 
      0  1      0             0      ; 
      0  0  s1^2+J1+mdm    mdm*s2*c  ;
      0  0    mdm*s2*c   mdm*s2^2+J2 ] ;

% ============================================================
% Funktion, die die "rechte Seite" des Dgl.-Systems definiert: 
function xvp = RechteSeite (t , xv)

global mdm  J1  J2  s1  s2  gdl 

phi1   = xv(1) ;
phi2   = xv(2) ;
omega1 = xv(3) ;
omega2 = xv(4) ;

s = sin(phi1-phi2);

phi1p   = omega1 ;
phi2p   = omega2 ;
omega1p = -mdm*s2*omega2^2*s - (s1+mdm)*gdl*sin(phi1) ;
omega2p =  mdm*s2*omega1^2*s -   mdm*s2*gdl*sin(phi2) ;

xvp = [phi1p ; phi2p ; omega1p ; omega2p] ; 