ParameterInit;
controller_design_lqr;

A = SSc.A;
B = SSc.B;
C = SSc.C;

x0   = [0; 0.01; 0; 0; 0; 0; 0; 0; 0];
phi0 = x0(1:3) + [0; phi_20; phi_30]; u_K0 = x0(4:6); u_R0 = x0(7:9);
x_offset = [0; 0.02; 0.0; 0; 0; 0; 0; 0; 0];
x_noise  = zeros(9,1)*1e-6;

CS_LQR         = 1;
CS_CompLQR     = 2;
control_system = CS_CompLQR;

accelTilt   = [0; 0; 0];
gyroTilt    = [0; 0; 0];
AccelError  = double(subs(A_P_K, phi, degtorad(accelTilt)));
GyroError   = double(subs(A_P_K, phi, degtorad(gyroTilt)));