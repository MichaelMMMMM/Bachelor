%6.11.2016, Untersuchung der Empfindlichkeiten der Messsysteme

%Empfindlichkeiten der Messsysteme fuer phi
g    = 9.81;
l_1  = 0.14;
l_2  = 0.061;
phi  = -45:1:45;
S_9  = g*sind(phi)*(1-l_1/l_2);
S_10 = g*cosd(phi)*(1-l_1/l_2);
S_11 = -tand(phi).^2 - 1;

figure;
plot(phi, S_9, phi, S_10, phi, S_11); grid;
xlabel('$\varphi [^\circ]$', 'interpreter', 'latex');
ylabel('$S(\varphi) [\ ]$', 'interpreter', 'latex');
legend('S_9', 'S_{10}', 'S_{11}');
title('Empfindlichkeiten der Messsysteme');
print('plots/empfindlichkeit_phi', '-depsc');

%Empfindlichkeiten der Messsysteme fuer phi__d
phi__d = degtorad(-45:1:45);
S_1    = ones(size(phi__d));
S_7    = -2*phi__d*(l_1 - l_2);

figure;
plot(phi__d, S_1, phi__d, S_7); grid;
xlabel('$\dot{\varphi} [\frac{rad}{s}]$', 'interpreter', 'latex');
ylabel('$S(\dot{\varphi})$', 'interpreter', 'latex');
axis([min(phi__d), max(phi__d), -0.2, 1.2]);
legend('S_1', 'S_7', 'location', 'east');
title('Empfindlichkeiten der Messsysteme');
print('plots/empfindlichkeit_phi__d', '-depsc');

%Empfindlichkeiten der Messsysteme fuer phi__d
phi__dd = degtorad(-45:1:45);
S_8     = ones(size(phi__dd)) * (l_1 - l_2);

figure;
plot(phi__d, S_8); grid;
xlabel('$\ddot{\varphi} [\frac{rad}{s^2}]$', 'interpreter', 'latex');
ylabel('$S(\ddot{\varphi})$', 'interpreter', 'latex');
legend('S_8');
title('Empfindlichkeit des Messsystemes');
print('plots/empfindlichkeit_phi__dd', '-depsc');