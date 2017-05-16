[tphi, phi2, phi3]   = importPhi('measurements/Exp1_1/phi.csv');
[tuk, uk1, uk2, uk3] = importUK('measurements/Exp1_1/uk.csv');
[tur, ur1, ur2, ur3] = importUR('measurements/Exp1_1/ur.csv');

x = [zeros(size(phi2))'; phi2'; phi3'; uk1'; uk2'; uk3'; ur1'; ur2'; ur3'];
x_K = inv(T_K)*x;

emlFigure();
plot(tphi, x_K'); grid;
emlXLabel('Time in seconds');
emlYLabel('$x_{Ki}$');
emlTitle('$x_{Ki}$ over Time');
emlLegend({'$x_{K1}$', '$x_{K2}$', '$x_{K3}$', '$x_{K4}$', '$x_{K5}$',...
           '$x_{K6}$', '$x_{K7}$', '$x_{K8}$', '$x_{K9}$'});
       
for k = 1:9
    emlFigure();
    plot(tphi, x_K(k, :)); grid;
    emlXLabel('Time in seconds');
    emlYLabel(horzcat('$x_{K', num2str(k), '}$'));
    emlTitle(horzcat('$x_{K', num2str(k), '}$ over Time'));
end