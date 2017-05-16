I_K = sym('I_K_', [3 3], 'real');
I_R = sym('I_R_', [3 1], 'real');
I_R = [I_R(1), 0, 0; 0, I_R(2), 0; 0, 0, I_R(3)];

u_K = sym('u_K', [3 1], 'real');
u_R = sym('u_R', [3 1], 'real');

