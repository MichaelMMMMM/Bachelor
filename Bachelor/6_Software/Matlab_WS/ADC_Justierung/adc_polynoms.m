%16.02.2017, Michael Meindl, Berechnung der Ausgleichspolynome fuer die
%ADC-Justierung

datafiles = {'data/adc_calib_data_rpm_-1085.csv',...
             'data/adc_calib_data_rpm_-725.csv',...
             'data/adc_calib_data_rpm_-360.csv',...
             'data/adc_calib_data_rpm_360.csv',...
             'data/adc_calib_data_rpm_720.csv',...
             'data/adc_calib_data_rpm_1085.csv'};
         
adc_mean = zeros(3, 6);

for n = 1:length(datafiles)
    [t, adc1, adc2, adc3] = importfile(datafiles{n});
    adc_mean(:,n) = [mean(adc1(250:end));mean(adc2(250:end));mean(adc3(250:end))]; 
end

target_values = [-1085, -725, -360, 360, 720, 1085]*2*pi/60;

adc1_poly = fit(adc_mean(1,:)', target_values', 'poly1');
adc2_poly = fit(adc_mean(2,:)', target_values', 'poly1');
adc3_poly = fit(adc_mean(3,:)', target_values', 'poly1');