Ta     = 0.02; g = 9.81;
m      = 1.532; m_R    = 0.155; r_1    = [0.5;7.5;7.5]*1e-2;
r_2    = [7.5;0.5;7.5]*1e-2; r_3    = [7.5;7.5;0.5]*1e-2;
l_C    = 0.066; c      = [l_C;l_C;l_C]; C_psi  = 3.1176e-5;

I_R1M1 = [3.358e-4, 0, 0; 0, 1.961e-4, 0; 0, 0, 1.681e-4];
I_R2M2 = [1.691e-4, 0, 0; 0, 3.358e-4, 0; 0, 0, 1.961e-4];
I_R3M3 = [1.961e-4, 0, 0; 0, 1.691e-4, 0; 0, 0, 3.358e-4];

I_GHO  = [1.520e-2, -5.201e-3, 5.375e-3; 
          -5.201e-3, 1.52e-2, 5.225e-3;
          5.375e-3, 5.225e-3, 1.542e-2];
I_KO   = I_GHO + m_R*(eye(3)*dot(r_1,r_1)-r_1*r_1') ...
               + m_R*(eye(3)*dot(r_2,r_2)-r_2*r_2') ...
               + m_R*(eye(3)*dot(r_3,r_3)-r_3*r_3');
           
I_K    = I_KO+[I_R2M2(1,1)+I_R3M3(1,1), 0, 0;
               0, I_R1M1(2,2)+I_R3M3(2,2), 0;
               0, 0, I_R1M1(3,3)+I_R2M2(3,3)];
           
I_R    = [I_R1M1(1,1), 0, 0; 0, I_R2M2(2,2), 0; 0, 0, I_R3M3(3,3)];

I_K_inv = inv(I_K);
I_R_inv = inv(I_R);


           
phi_10 = 0;
phi_20 = -2*atan(sqrt(2)-sqrt(3));
phi_30 = -pi/4;

dPhiMat = [cos(phi_30)/cos(phi_20), -sin(phi_30)/cos(phi_20), 0;
           sin(phi_30), cos(phi_30), 0; 
           -sin(phi_20)*cos(phi_30)/cos(phi_20), sin(phi_20)*sin(phi_30)/cos(phi_20), 1];
dGPhi2  = [cos(phi_20)-sin(phi_20)*sin(phi_30); ...
           -cos(phi_20)-sin(phi_20)*cos(phi_30);...
           sin(phi_20)*cos(phi_30)+sin(phi_20)*sin(phi_30)];
dGPhi3  = [cos(phi_20)*cos(phi_30);
           -cos(phi_30)*sin(phi_30);
           cos(phi_20)*sin(phi_30)-cos(phi_20)*cos(phi_30)];
dGMat   = -m*l_C*g*[zeros(3,1), dGPhi2, dGPhi3];
           
    
       
A = [zeros(3,3), dPhiMat, zeros(3,3);
     I_K_inv*dGMat, -C_psi*I_K_inv, C_psi*I_K_inv;
     zeros(3,3), C_psi*I_R_inv, -C_psi*I_R_inv];
B = [zeros(3,3); -I_K_inv; I_R_inv];
C = [zeros(8,1), eye(8)];
D = zeros(8,3);

SSc = ss(A, B, C, D);
SSd = c2d(SSc, Ta, 'zoh');