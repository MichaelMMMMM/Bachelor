%13.11.2016, Michael Meindl, Auswertung der Simulation

close all;
load('simValues');

fArr = [0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
fName = {'0_5', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10'};

%Plot the phi values
for k = 1:11
    figure; plot(tValues{k}, radtodeg(phiValues{k})); grid;
    xlabel('$Zeit [s]$', 'interpreter', 'latex'); 
    ylabel('$\varphi [^\circ]$', 'interpreter', 'latex'); 
    title(strcat('Simulation f=', num2str(fArr(k))));
    print(strcat('plots/sim_phi_sine_freq_', fName{k}), '-depsc');
end

%Calculate the FFTs
fftValues = cell(11,1);
fValues   = cell(11,1);
dfValues  = cell(11,1);
nValues   = cell(11,1);

fa = 50;
Ta = 1/fa;

t_begin   = [17.04, 17.58, 17.52, 17.72, 17.54, 17.44, 17.54, 17.62, 17.54, 17.48, 17.54];
t_end     = [156.04, 156.08, 156.76, 156.2, 156.16, 156.14, 156.12, 156.12, 156.1, 156.1, 156.1];

for k=1:11
    phiValues{k} = phiValues{k}(floor(t_begin/Ta):floor(t_end/Ta));
    fftValues{k} = fftshift(fft(phiValues{k}));
    nValues{k}   = length(phiValues{k});
    dfValues{k}  = fa/nValues{k};
    fValues{k}   = -fa/2+dfValues{k}/2:dfValues{k}:fa/2-dfValues{k}/2;
    figure; stem(fValues{k}, abs(fftValues{k})); grid;
    xlabel('Frequenz [Hz]'); ylabel('|DFT|'); 
    title(strcat('DFT-Spektrum Simulation f=', num2str(fArr(k)), 'Hz'));
    print(strcat('plots/sim_fft_sine_freq_', fName{k}), '-depsc');
end

%Autokorellation
rxxValues = cell(11,1);
dTValues  = cell(11,1);
for k=1:11
    rxxValues{k} = xcorr(phiValues{k}, 'unbiased');
    dTValues{k}  = -nValues{k}(end)*Ta+Ta:Ta:nValues{k}(end)*Ta-Ta;
    figure; plot(dTValues{k}, rxxValues{k}); grid;
    xlabel('$\Delta T [s]$', 'interpreter', 'latex');
    ylabel('$r_{xx}$', 'interpreter', 'latex');
    title(strcat('Autokorrelation bei f=', num2str(fArr(k)), 'Hz'));
    print(strcat('plots/sim_rxx_sine_freq_', fName{k}), '-depsc');
end

%Leistungsdichtespektrum
ldsValues = cell(11,1);
dfValues  = cell(11,1);

for k = 1:11
    ldsValues{k} = fftshift(fft(rxxValues{k}));
    dfValues{k} = fa/(length(rxxValues{k}));
    fValues{k}   = -fa/2+dfValues{k}/2:dfValues{k}:fa/2-dfValues{k}/2;
    figure; stem(fValues{k}, abs(ldsValues{k})); grid;
    xlabel('Frequenz [Hz]');
    ylabel('|S_{xx}|');
    title(strcat('Leistungsdichtespektrum bei f=', num2str(fArr(k)), 'Hz'));
    print(strcat('plots/sim_lds_sine_freq_', fName{k}), '-depsc');
end