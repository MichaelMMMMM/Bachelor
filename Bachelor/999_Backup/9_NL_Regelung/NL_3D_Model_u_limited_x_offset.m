u_sat_on  = true;
x_offset  = [0.05; 0.2; 0.5; zeros(6,1)];
x_noise   = zeros(9,1);
stop_time = 20;

for n = 1:it
    x_0 = double(subs(A_P_K, phi, [phi_10; phi_20; phi_30-phi_30_0(n)]))*[-9.81;0;0];
    x_0 = [x_0;zeros(6,1)];
    sim('closedloop_3d.slx');
    
    x_g{n}  = x_g__SIM.Data;
    x_ur{n} = x_ur__SIM.Data;
    x_uk{n} = x_uk__SIM.Data;
    u_c{n}  = u__SIM.Data(:,4:6);
    u{n}    = u__SIM.Data(:,1:3);
    t_x{n}  = x_g__SIM.Time;
    t_u{n}  = u__SIM.Time;
end

figure;
for n = 1:it
    g_k1 = x_g{n}(:,1); g_k2 = x_g{n}(:,2); g_k3 = x_g{n}(:,3);
    quiver3(g_k1, g_k2, g_k3, gradient(g_k1), gradient(g_k2), gradient(g_k3), 0, 'black'); 
    hold on;
    %quiver3(g_k1(1), g_k2(1), g_k3(1), 0, 0, 0, 0, 'b*');
    text(g_k1(1), g_k2(1), g_k3(1), strcat(num2str(radtodeg(phi_30_0(n))), '°'));
end
quiver3(0, 0, 0, 0, 0, 0, 'r*');
xlabel('g_{k1}'); ylabel('g_{k2}'); zlabel('g_{k3}');
title('Verlauf x_g, limitierte Stellgröße, x_{offset}');

figure;
subplot(3,1,1);
for n = 1:it
    ur1 = x_ur{n}(:,1); ur2 = x_ur{n}(:,2); ur3 = x_ur{n}(:,3);
    subplot(3,1,1);
    plot(t_x{n}, ur1, 'black'); grid; hold on;
    xlabel('Zeit [s]'); ylabel('u_{R1} [rad/sec]');
    title('Verlauf u_{R1}, limitierte Stellgröße, x_{offset}');
    subplot(3,1,2);
    plot(t_x{n}, ur2, 'black'); grid; hold on;
    xlabel('Zeit [s]'); ylabel('u_{R2} [rad/sec]');
    title('Verlauf u_{R2}, limitierte Stellgröße, x_{offset}');
    subplot(3,1,3);
    plot(t_x{n}, ur3, 'black'); grid; hold on;
    xlabel('Zeit [s]'); ylabel('u_{R3} [rad/sec]');
    title('Verlauf u_{R3}, limitierte Stellgröße, x_{offset}');
end

figure;
subplot(3,1,1);
for n = 1:it
    u1 = u{n}(:,1); u2 = u{n}(:,1); u3 = u{n}(:,3);
    subplot(3,1,1);
    plot(t_u{n}, u1, 'black'); grid; hold on;
    xlabel('Zeit [s]'); ylabel('u_1 [Nm]');
    title('Verlauf u_1, limitierte Stellgröße, x_{offset}');
    subplot(3,1,2);
    plot(t_u{n}, u2, 'black'); grid; hold on;
    xlabel('Zeit [s]'); ylabel('u_2 [Nm]');
    title('Verlauf u_2, limitierte Stellgröße, x_{offset}');
    subplot(3,1,3);
    plot(t_u{n}, u3, 'black'); grid; hold on;
    xlabel('Zeit [s]'); ylabel('u_3 [Nm]');
    title('Verlauf u_3, limitierte Stellgröße, x_{offset}');
end