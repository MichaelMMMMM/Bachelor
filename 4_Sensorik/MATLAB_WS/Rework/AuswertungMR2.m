%19.11.16, Michael Meindl, Auswertung der Messreihe2, Spektren der
%Phi-Werte aus Accel und Gyro, mit Modulationsfrequenz 200Hz

close all;

fa = 50;
Ta = 0.02;

load('Messreihe2');
load('accel_polynoms');

freqName = {'0', '0.5', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10'};

data       = {sensordata_freq_0, sensordata_freq_05, sensordata_freq_1,...
              sensordata_freq_2, sensordata_freq_3, sensordata_freq_4,...
              sensordata_freq_5, sensordata_freq_6, sensordata_freq_7,...
              sensordata_freq_8, sensordata_freq_9, sensordata_freq_10};
time  = cell(12,1);
x1_dd = cell(12,1);
x2_dd = cell(12,1);
y1_dd = cell(12,1);
y2_dd = cell(12,1);

for k = 1:12
    y1_dd{k} = feval(x1_polynom, data{k}.mX1__dd); 
    y2_dd{k} = feval(x2_polynom, data{k}.mX2__dd);
    x1_dd{k} = feval(y1_polynom, data{k}.mY1__dd);
    x2_dd{k} = feval(y2_polynom, data{k}.mY2__dd);
    time{k}  = data{k}.mTime;
end

l1 = 0.14;
l2 = 0.061;
g  = 9.81;

phi_a = cell(12,1);     %Phi-Values from the Accelerometer

for k = 1:12
    tmp1   = x1_dd{k} - l1/l2*x2_dd{k};
    tmp2 = y1_dd{k} - l1/l2*y2_dd{k};
    phi_a{k} = tmp2./tmp1;
end

phi_g = cell(12,1);     %Phi-Values from the Gyroscope

load('gyro_calibration');

p1_phi__d  = -0.0076;
p2_phi1__d = -mean(sensordata.mPhi1__d);
p2_phi2__d = -mean(sensordata.mPhi2__d);

phi__d = cell(12,1);
for k = 1:12
    phi__d{k} = degtorad(p1_phi__d*(data{k}.mPhi1__d+p2_phi1__d)+...
                         p1_phi__d*(data{k}.mPhi2__d+p2_phi2__d))/2;    
    phi_g{k} = ones(size(phi_a{k}))*phi_a{k}(1);
    for n = 2:length(phi_g{k})
        phi_g{k}(n) = phi_g{k}(n-1) + (phi__d{k}(n)+phi__d{k}(n-1))/(2*Ta);
    end
end


for k = 1:12
    figure; plot(time{k}, radtodeg(phi_a{k})); 
    grid; xlabel('Zeit [s]'); ylabel('\phi [°]');
    title(horzcat('\phi-Accel bei Frequenz ', freqName{k}, ' Hz, f_a=50Hz f_m=200Hz'));
    figure; plot(time{k}, radtodeg(phi_g{k})); grid; xlabel('Zeit [s]'); ylabel('\phi [°]');
    title(horzcat('\phi-Gyro bei Frequenz ', freqName{k}, ' Hz, f_a=f_m=50Hz'));
end

close all;

%DFT-Spektrum

PHI_A = cell(12,1);
PHI_G = cell(12,1);

phi_offset = mean(phi_a{1});

for k = 1:12
   phi = phi_a{k}(1000:end)-phi_offset;
   n   = length(phi);
   PHI_A{k} = fftshift(fft(phi));
   df  = fa/n;
   f   = -fa/2+df/2:df:fa/2-df/2;
   figure; stem(f, abs(PHI_A{k})); grid;
   xlabel('Frequenz [Hz]'); ylabel('|DFT|'); 
   title(horzcat('DFT-Spektrum \phi-Accel bei Frequenz ', freqName{k}, ' Hz, f_a=50Hz f_m=200Hz'));
   phi = phi_g{k}(1000:end)-phi_offset;
   n   = length(phi);
   PHI_G{k} = fftshift(fft(phi));
   df = fa/n;
   f  = -fa/2+df/2:df:fa/2-df/2;
%    figure; stem(f, abs(PHI_G{k})); grid;
%    xlabel('Frequenz [Hz]'); ylabel('|DFT|');
%    title(horzcat('DFT-Spektrum \phi-Gyro bei Frequenz ', freqName{k}, ' Hz, f_a=f_m=50Hz'));
end

%LDS-Spektrum
LDS_A = cell(12,1);
LDS_G = cell(12,1);

for k = 1:12
   phi = phi_a{k}(1000:end)-phi_offset;
   LDS_A{k} = fftshift(fft(xcorr(phi, 'unbiased')));
   n        = length(LDS_A{k});
   df       = fa/n;
   f        = -fa/2+df/2:df:fa/2-df/2;
   figure; stem(f, abs(LDS_A{k})); grid;
   xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
   title(horzcat('LDS \phi-Accel bei Frequenz ', freqName{k}, ' Hz, f_a=50Hz f_m=200Hz'));
   
   phi = phi_g{k}(1000:end)-phi_offset;
   LDS_G{k} = fftshift(fft(xcorr(phi, 'unbiased')));
   n        = length(LDS_G{k});
   df       = fa/n;
   f        = -fa/2+df/2:df:fa/2-df/2;
%    figure; stem(f, abs(LDS_G{k})); grid;
%    xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
%    title(horzcat('Leistungsdichtespektrum \phi-Gyro bei Frequenz ', freqName{k}, ' Hz, f_a=f_m=50Hz'));
end