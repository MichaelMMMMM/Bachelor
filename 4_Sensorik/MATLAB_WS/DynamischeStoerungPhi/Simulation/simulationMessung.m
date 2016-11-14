%13.11.2016, Michael Meindl, Simulation der sinus angerregten Schwingung

close all;

fArr = [0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
phiValues = cell(11,1);
tValues   = cell(11,1);

n = 1:20:160001;
for k = 1:11
    f_sine = fArr(k);
    sim('model_sinWave_1D');
    phiValues{k} = phi_sim.Data(n) + phi_off;
    tValues{k}   = phi_sim.Time(n);
end

save('simValues', 'phiValues', 'tValues');
