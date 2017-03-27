%26.03.2017

Ta = 0.02;

[t, phi, uk, ur, tm] = importfile('data/sysid_edge_freq_0_5_amp_0_01.csv');
E1 = [phi(10/Ta:end)';uk(10/Ta:end)';ur(10/Ta:end)'; tm(10/Ta:end)'];
%D1 = [diff(E1(1,:)); diff(E1(2,:)); diff(E1(3,:))]./Ta;
D1 = E1(1:3, 2:end);
E1 = E1(:, 1:end-1);
[t, phi, uk, ur, tm] = importfile('data/sysid_edge_freq_0_amp_0.csv');
E2 = [phi(10/Ta:end)';uk(10/Ta:end)';ur(10/Ta:end)'; tm(10/Ta:end)'];
%D2 = [diff(E2(1,:)); diff(E2(2,:)); diff(E2(3,:))]./Ta;
D2 = E2(1:3, 2:end);
E2 = E2(:, 1:end-1);
[t, phi, uk, ur, tm] = importfile('data/sysid_edge_freq_1_amp_0_01.csv');
E3 = [phi(10/Ta:end)';uk(10/Ta:end)';ur(10/Ta:end)'; tm(10/Ta:end)'];
%D3 = [diff(E3(1,:)); diff(E3(2,:)); diff(E3(3,:))]./Ta;
D3 = E3(1:3, 2:end);
E3 = E3(:, 1:end-1);
[t, phi, uk, ur, tm] = importfile('data/sysid_edge_freq_1_5_amp_0_01.csv');
E4 = [phi(10/Ta:end)';uk(10/Ta:end)';ur(10/Ta:end)'; tm(10/Ta:end)'];
%D4 = [diff(E4(1,:)); diff(E4(2,:)); diff(E4(3,:))]./Ta;
D4 = E4(1:3, 2:end);
E4 = E4(:, 1:end-1);
[t, phi, uk, ur, tm] = importfile('data/sysid_edge_freq_2_amp_0_01.csv');
E5 = [phi(10/Ta:end)';uk(10/Ta:end)';ur(10/Ta:end)'; tm(10/Ta:end)'];
%D5 = [diff(E5(1,:)); diff(E5(2,:)); diff(E5(3,:))]./Ta;
D5 = E5(1:3, 2:end);
E5 = E5(:, 1:end-1);

E = [E1, E2, E3, E4, E5];
D = [D1, D2, D3, D4, D5];


