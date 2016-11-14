%12.11.2016, Michael Meindl, FFT-Spektren der sinus-angeregten Schwingungen

close all;

load('datafiles/messwerte_sinusanregung');
load('datafiles/accel_polynoms');

freqArr = [0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
freqName = {'0_5', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10'};
dataArr = [sensordata_sin_freq_0_5_amp_0_05, sensordata_sin_freq_1_amp_0__05,...
           sensordata_sin_freq_2_amp_0__05, sensordata_sin_freq_3_amp_0__05,...
           sensordata_sin_freq_4_amp_0__05, sensordata_sin_freq_5_amp_0__05,...
           sensordata_sin_freq_6_amp_0__05, sensordata_sin_freq_7_amp_0__05,...
           sensordata_sin_freq_8_amp_0__05, sensordata_sin_freq_9_amp_0__05,...
           sensordata_sin_freq_10_amp_0__05];
t       = {dataArr(1).mTime; dataArr(2).mTime; dataArr(3).mTime;...
           dataArr(4).mTime; dataArr(5).mTime; dataArr(6).mTime;...
           dataArr(7).mTime; dataArr(8).mTime; dataArr(9).mTime;...
           dataArr(10).mTime; dataArr(11).mTime};

%Display sensor axis in the bodies reference frame
a_S1_y = cell(11,1);
a_S2_y = cell(11,1);
a_S1_x = cell(11,1);
a_S2_x = cell(11,1);
for k = 1:11
    a_S1_y{k} = feval(x1_polynom, dataArr(k).mX1__dd);
    a_S2_y{k} = feval(x2_polynom, dataArr(k).mX2__dd);
    a_S1_x{k} = feval(y1_polynom, dataArr(k).mY1__dd);
    a_S2_x{k} = feval(y2_polynom, dataArr(k).mY2__dd);
end

l1 = 0.14;
l2 = 0.061;
g  = 9.81;

y_9  = cell(11,1);
y_10 = cell(11,1);
y_11 = cell(11,1);
for k = 1:11
    y_9{k}  = a_S1_x{k} - l1/l2*a_S2_x{k};
    y_10{k} = a_S1_y{k} - l1/l2*a_S2_y{k};
    y_11{k} = y_10{k}./y_9{k};
end

phi_9  = cell(11,1);
phi_10 = cell(11,1);
phi_11 = cell(11,1);
for k = 1:11
    phi_9{k}  = acosd(y_9{k} / (g*(1-l1/l2)));
    phi_10{k} = asind(y_10{k} / (-g*(1-l1/l2)));
    phi_11{k} = -atand(y_11{k});
end

phi_offset = 6.7768;
T_a = 0.02;
fa  = 50;

for k = 1:11
   figure;
   phi_11{k} = phi_11{k}-phi_offset;
   plot(t{k}, phi_11{k}); grid;
   xlabel('$Zeit [s]$', 'interpreter', 'latex');
   ylabel('$\varphi [^\circ]$', 'interpreter', 'latex');
   title(strcat('Frequenz ', num2str(freqArr(k)), ' Amplitude 0.05Nm'));
   print(strcat('plots/phi_sinefreq_', freqName{k}), '-depsc');
end

phi  = phi_11{1};
phi1 = degtorad(phi(1002:8052));
t1   = 0:T_a:(length(phi1)-1)*T_a;
n1   = length(phi1);
PHI1 = fftshift(fft(phi1));
df1 = fa/n1;
f = -fa/2+df1/2:df1:fa/2-df1/2;
figure;stem(f, abs(PHI1)); grid;
xlabel('Frequenz [Hz]'); ylabel('|DFT|'); 
title('FFT-Spektrum der Schwingung mit 0.5Hz');
print('plots/dft_sinefreq_0_5', '-depsc');

phi  = phi_11{2};
phi2 = degtorad(phi(1027:8102));
n2   = length(phi2);
t2   = 0:T_a:(n2-1)*T_a;
PHI2 = fftshift(fft(phi2));
df2  = fa/n2;
f    = -fa/2+df2/2:df2:fa/2-df2/2;
figure;
stem(f, abs(PHI2)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 1Hz');
print('plots/dft_sinefreq_1', '-depsc');

phi  = phi_11{3};
phi3 = degtorad(phi(1000:8101));
n3   = length(phi3);
t3   = 0:T_a:(n3-1)*T_a;
PHI3 = fftshift(fft(phi3));
df3  = fa/n3;
f3   = -fa/2+df3/2:df3:fa/2-df3/2;
figure;
stem(f3, abs(PHI3)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 2Hz');
print('plots/dft_sinefreq_2', '-depsc');

phi  = phi_11{4};
phi4 = degtorad(phi(1002:8000));
n4   = length(phi4);
t4   = 0:T_a:(n4-1)*T_a;
PHI4 = fftshift(fft(phi4));
df4  = fa/n4;
f4   = -fa/2+df4/2:df4:fa/2-df4/2;
figure;
stem(f4, abs(PHI4)); grid; 
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 3Hz');
print('plots/dft_sinefreq_3', '-depsc');

phi  = phi_11{5};
phi5 = degtorad(phi(1000:8002));
n5   = length(phi5);
t5   = 0:T_a:(n5-1)*T_a;
PHI5 = fftshift(fft(phi5));
df5  = fa/n5;
f5   = -fa/2+df5/2:df5:fa/2-df5/2;
figure;
stem(f5, abs(PHI5)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 4Hz');
print('plots/dft_sinefreq_4', '-depsc');

phi  = phi_11{6};
phi6 = degtorad(phi(1000:8000));
n6   = length(phi6);
t6   = 0:T_a:(n6-1)*T_a;
PHI6 = fftshift(fft(phi6));
df6  = fa/n6;
f6   = -fa/2+df6/2:df6:fa/2-df6/2;
figure;
stem(f6, abs(PHI6)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 5Hz');
print('plots/dft_sinefreq_5', '-depsc');

phi  = phi_11{7};
phi7 = degtorad(phi(993:7999));
n7   = length(phi7);
t7   = 0:T_a:(n7-1)*T_a;
PHI7 = fftshift(fft(phi7));
df7  = fa/n7;
f7   = -fa/2+df7/2:df7:fa/2-df7/2;
figure; stem(f7, abs(PHI7)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 6Hz');
print('plots/dft_sinefreq_6', '-depsc');

phi  = phi_11{8};
phi8 = degtorad(phi(998:8006));
n8   = length(phi8);
t8   = 0:T_a:(n8-1)*T_a;
PHI8 = fftshift(fft(phi8));
df8  = fa/n8;
f8   = -fa/2+df8/2:df8:fa/2-df8/2;
figure; stem(f8, abs(PHI8)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 7Hz');
print('plots/dft_sinefreq_7', '-depsc');

phi  = phi_11{9};
phi9 = degtorad(phi(988:8010));
n9   = length(phi9);
t9   = 0:T_a:(n9-1)*T_a;
PHI9 = fftshift(fft(phi9));
df9  = fa/n9;
f9   = -fa/2+df9/2:df9:fa/2-df9/2;
figure; stem(f9, abs(PHI9)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 8Hz');
print('plots/dft_sinefreq_8', '-depsc');

phi   = phi_11{10};
phi10 = degtorad(phi(1003:7998));
n10   = length(phi10);
t10   = 0:T_a:(n10-1)*T_a;
PHI10 = fftshift(fft(phi10));
df10  = fa/n10;
f10   = -fa/2+df10/2:df10:fa/2-df10/2;
figure; stem(f10, abs(PHI10)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 9Hz');
print('plots/dft_sinefreq_9', '-depsc');

phi   = phi_11{11};
phi11 = degtorad(phi(1000:7990));
n11   = length(phi11);
t11   = 0:T_a:(n11-1)*T_a;
PHI11 = fftshift(fft(phi11));
df11  = fa/n11;
f11   = -fa/2+df11/2:df11:fa/2-df11/2;
figure; stem(f11, abs(PHI11)); grid;
xlabel('$Frequenz [Hz]$'); ylabel('|DFT| []'); 
title('FFT-Spektrum der Schwingung mit 10Hz');
print('plots/dft_sinefreq_10', '-depsc');

%Autocorrelation
rxx1 = xcorr(phi1, 'unbiased');
T1   = t1(end);
dt1  = -T1:T_a:T1;
figure; plot(dt1, rxx1); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 0.5Hz');
print('plots/rxx_sinefreq_0_5', '-depsc');

rxx2 = xcorr(phi2, 'unbiased');
T2   = t2(end);
dt2  = -T2:T_a:T2;
figure; plot(dt2, rxx2); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 1Hz');
print('plots/rxx_sinefreq_1', '-depsc');

rxx3 = xcorr(phi3, 'unbiased');
T3   = t3(end);
dt3  = -T3:T_a:T3;
figure; plot(dt3, rxx3); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 2Hz');
print('plots/rxx_sinefreq_2', '-depsc');

rxx4 = xcorr(phi4, 'unbiased');
T4   = t4(end);
dt4  = -T4:T_a:T4;
figure; plot(dt4, rxx4); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 3Hz');
print('plots/rxx_sinefreq_3', '-depsc');

rxx5 = xcorr(phi5, 'unbiased');
T5   = t5(end);
dt5  = -T5:T_a:T5;
figure; plot(dt5, rxx5); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 4Hz');
print('plots/rxx_sinefreq_4', '-depsc');

rxx6 = xcorr(phi6, 'unbiased');
T6   = t6(end);
dt6  = -T6:T_a:T6;
figure; plot(dt6, rxx6); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 5Hz');
print('plots/rxx_sinefreq_5', '-depsc');

rxx7 = xcorr(phi7, 'unbiased');
T7   = t7(end);
dt7  = -T7:T_a:T7;
figure; plot(dt7, rxx7); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 6Hz');
print('plots/rxx_sinefreq_6', '-depsc');

rxx8 = xcorr(phi8, 'unbiased');
T8   = t8(end);
dt8  = -T8:T_a:T8;
figure; plot(dt8, rxx8); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 7Hz');
print('plots/rxx_sinefreq_7', '-depsc');

rxx9 = xcorr(phi9, 'unbiased');
T9   = t9(end);
dt9  = -T9:T_a:T9;
figure; plot(dt9, rxx9); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 8Hz');
print('plots/rxx_sinefreq_8', '-depsc');

rxx10 = xcorr(phi10, 'unbiased');
T10   = t10(end);
dt10  = -T10:T_a:T10;
figure; plot(dt10, rxx10); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 9Hz');
print('plots/rxx_sinefreq_9', '-depsc');

rxx11 = xcorr(phi11, 'unbiased');
T11   = t11(end);
dt11  = -T11:T_a:T11;
figure; plot(dt11, rxx11); grid;
xlabel('\Delta t [s]'); ylabel('r_{xx}');
title('Autokorrelation der Schwingung mit 10Hz');
print('plots/rxx_sinefreq_10', '-depsc');

%Leistungsdichtespektren
LDS1  = fftshift(fft(rxx1));
n1    = length(rxx1);
df1   = fa/n1;
f1    = -fa/2+df1/2:df1:fa/2-df1/2;
figure; stem(f1, abs(LDS1)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 0.5Hz');
print('plots/lds_sinefreq_0_5', '-depsc');

LDS2  = fftshift(fft(rxx2));
n2    = length(rxx2);
df2   = fa/n2;
f2    = -fa/2+df2/2:df2:fa/2-df2/2;
figure; stem(f2, abs(LDS2)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 1Hz');
print('plots/lds_sinefreq_1', '-depsc');

LDS3  = fftshift(fft(rxx3));
n3    = length(rxx3);
df3   = fa/n3;
f3    = -fa/2+df3/2:df3:fa/2-df3/2;
figure; stem(f3, abs(LDS3)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 2Hz');
print('plots/lds_sinefreq_2', '-depsc');

LDS4  = fftshift(fft(rxx4));
n4    = length(LDS4);
df4   = fa/n4;
f4    = -fa/2+df4/2:df4:fa/2-df4/2;
figure; stem(f4, abs(LDS4)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 3Hz');
print('plots/lds_sinefreq_3', '-depsc');

LDS5  = fftshift(fft(rxx5));
n5    = length(LDS5);
df5   = fa/n5;
f5    = -fa/2+df5/2:df5:fa/2-df5/2;
figure; stem(f5, abs(LDS5)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 4Hz');
print('plots/lds_sinefreq_4', '-depsc');

LDS6  = fftshift(fft(rxx6));
n6    = length(LDS6);
df6   = fa/n6;
f6    = -fa/2+df6/2:df6:fa/2-df6/2;
figure; stem(f6, abs(LDS6)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 5Hz');
print('plots/lds_sinefreq_5', '-depsc');

LDS7  = fftshift(fft(rxx7));
n7    = length(LDS7);
df7   = fa/n7;
f7    = -fa/2+df7/2:df7:fa/2-df7/2;
figure; stem(f7, abs(LDS7)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 6Hz');
print('plots/lds_sinefreq_6', '-depsc');

LDS8  = fftshift(fft(rxx8));
n8    = length(LDS8);
df8   = fa/n8;
f8    = -fa/2+df8/2:df8:fa/2-df8/2;
figure; stem(f8, abs(LDS8)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 7Hz');
print('plots/lds_sinefreq_7', '-depsc');

LDS9  = fftshift(fft(rxx9));
n9    = length(LDS9);
df9   = fa/n9;
f9    = -fa/2+df9/2:df9:fa/2-df9/2;
figure; stem(f9, abs(LDS9)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 8Hz');
print('plots/lds_sinefreq_8', '-depsc');

LDS10 = fftshift(fft(rxx10));
n10   = length(LDS10);
df10  = fa/n10;
f10   = -fa/2+df10/2:df10:fa/2-df10/2;
figure; stem(f10, abs(LDS10)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 9Hz');
print('plots/lds_sinefreq_9', '-depsc');

LDS11 = fftshift(fft(rxx11));
n11   = length(LDS11);
df11  = fa/n11;
f11   = -fa/2+df11/2:df11:fa/2-df11/2;
figure; stem(f11, abs(LDS11)); grid;
xlabel('Frequenz [Hz]'); ylabel('|S_{xx}|');
title('Leistungsdichtespektrum der Schwingung mit 10Hz');
print('plots/lds_sinefreq_10', '-depsc');
