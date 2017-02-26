%16.02.2017, Michael Meindl, Skript zur Darstellung der ADC-Daten 

datafiles = {'data/adc_calib_data_rpm_-1085.csv',...
             'data/adc_calib_data_rpm_-725.csv',...
             'data/adc_calib_data_rpm_-360.csv',...
             'data/adc_calib_data_rpm_360.csv',...
             'data/adc_calib_data_rpm_720.csv',...
             'data/adc_calib_data_rpm_1085.csv'};

fileNr = 6;

[t, adc1, adc2, adc3] = importfile(datafiles{fileNr});

figure;
plot(t, adc1, t, adc2, t, adc3); grid;
legend('ADC1', 'ADC2', 'ADC3');
xlabel('Time [s]');
ylabel('ADC-Value []');