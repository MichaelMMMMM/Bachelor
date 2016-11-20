%13.11.2016, Michael Meindl, Schwingungsanalyse über Integration der Gyros

close all;

freqName = {'0.5', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10'};

load('datafiles/gyro_calibration');
load('datafiles/messwerte_sinusanregung');

p1_phi__d  = -0.0076;
p2_phi1__d = -mean(sensordata.mPhi1__d);
p2_phi2__d = -mean(sensordata.mPhi2__d);

phi__d = cell(11,1);

phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_0_5_amp_0_05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_0_5_amp_0_05.mPhi2__d+p2_phi2__d));
phi__d{1}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_1_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_1_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{2}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_2_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_2_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{3}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_3_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_3_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{4}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_4_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_4_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{5}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_5_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_5_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{6}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_6_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_6_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{7}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_7_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_7_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{8}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_8_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_8_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{9}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_9_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_9_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{10}  = (phi1__d+phi2__d)/2;
phi1__d    = degtorad(p1_phi__d*(sensordata_sin_freq_10_amp_0__05.mPhi1__d+p2_phi1__d));
phi2__d    = degtorad(p1_phi__d*(sensordata_sin_freq_10_amp_0__05.mPhi2__d+p2_phi2__d));
phi__d{11}  = (phi1__d+phi2__d)/2;

phi = cell(11,1);
t   = cell(11,1);
fa  = 50;
Ta  = 0.02;

for z = 1:11
    phi{z} = zeros(size(phi__d{z}));
    n = length(phi__d{z});
    t{z} = 0:Ta:(n-1)*Ta;
    for k=2:n
        dPhi = (phi__d{z}(k-1)+phi__d{z}(k))/2*Ta;
        phi{z}(k) = phi{z}(k-1)+dPhi;
    end
    figure; plot(t{z}, radtodeg(phi{z})); grid;
    xlabel('$Zeit [s]$', 'interpreter', 'latex');
    ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
    title(horzcat('Phi-Gyro bei Frequenz ', freqName{z}, 'Hz'));
    print(strcat('plots/phi_g_', num2str(z)), '-depsc');
end

PHI_G = cell(11,1);

for z = 1:11
    phi{z} = phi{z}(1000:end);
    n = length(phi{z});
    PHI_G{z} = fftshift(fft(phi{z}));
    df = fa/n;
    f  = -fa/2+df/2:df:fa/2-df/2;
    figure; stem(f, abs(PHI_G{z})); grid;
    xlabel('Frequenz [Hz]'); ylabel('|DFT|');
    title(horzcat('DFT-Spektrum Phi-Gyro bei Frequenz ', freqName{z}, 'Hz'));
    print(strcat('plots/dft_phi_g_', num2str(z)), '-depsc');
end

SXX_G = cell(11,1);

for z = 1:11
    rxx = xcorr(phi{z}, 'unbiased');
    n = length(rxx);
    SXX_G{z} = fftshift(fft(rxx));
    df = fa/n;
    f = -fa/2+df/2:df:fa/2-df/2;
    figure; stem(f, abs(SXX_G{z})); grid;
    xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
    title(horzcat('Leistungsdichtespektrum Phi-Gyro bei Frequenz ', freqName{z}, 'Hz'));
    print(strcat('plots/lds_phi_g_', num2str(z)), '-depsc');
end