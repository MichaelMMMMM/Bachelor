%26.02.2017, Michael Meindl, Berechnung des geschlossenen RK bei
%unbegrenztem Drehmoment

limit_on = false;
t   = cell(1,n);
x1  = cell(1,n);
x3  = cell(1,n);
u   = cell(1,n);
tu  = cell(1,n);


for r = 1:n
    x_0 = [phi0(r); 0; 0];
    sim('closedloop_1D.slx');
    
    t{r}   = x__SIM.Time;
    x1{r}  = x__SIM.Data(:,1);
    x3{r}  = x__SIM.Data(:,3);
    u{r}   = u__SIM.Data(:,1);
    tu{r}  = u__SIM.Time;
end

figure;
plot(cell2mat(t), radtodeg(cell2mat(x1)), 'black'); grid;
title('Verlauf x1, unlimitierte Stellgröße');
xlabel('Zeit in Sekunden', 'interpreter', 'latex');
ylabel('$\varphi$', 'interpreter', 'latex');

figure;
plot(cell2mat(t), cell2mat(x3), 'black'); grid;
title('Verlauf x3, unlimitierte Stellgröße');
xlabel('Zeit in Sekunden', 'interpreter', 'latex');
ylabel('$\dot{\psi}$', 'interpreter', 'latex');

figure;
plot(cell2mat(tu), cell2mat(u), 'black'); grid;
title('Verlauf der Stellgröße');
xlabel('Zeit in Sekunden', 'interpreter', 'latex');
ylabel('$u_c$', 'interpreter', 'latex');