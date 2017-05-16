%18.04.2017, Read the sensor measurements from the csv-files

s1 = zeros(21,6); s2 = zeros(21,6); s3 = zeros(21,6); 
s4 = zeros(21,6); s5 = zeros(21,6); s6 = zeros(21,6);

app = {'_phi1_0.csv', '_phi1_15.csv', '_phi1_30.csv', '_phi1_45.csv',...
       '_phi1_60.csv', '_phi1_75.csv', '_phi1_90.csv', '_phi2_0.csv',...
       '_phi2_15.csv', '_phi2_30.csv', '_phi2_45.csv', '_phi2_60.csv',...
       '_phi2_75.csv', '_phi2_90.csv', '_phi3_0.csv', '_phi3_15.csv',...
       '_phi3_30.csv', '_phi3_45.csv', '_phi3_60.csv', '_phi3_75.csv',...
       '_phi3_90.csv'};
   
for n = 1:length(app)
    [t, ax, ay, az,  wx, wy, wz] = importfile(horzcat('measurements/s1', app{n}));
    s1(n,:) = [mean(ax), mean(ay), mean(az), mean(wx), mean(wy), mean(wz)];
    [t, ax, ay, az,  wx, wy, wz] = importfile(horzcat('measurements/s2', app{n}));
    s2(n,:) = [mean(ax), mean(ay), mean(az), mean(wx), mean(wy), mean(wz)];
    [t, ax, ay, az,  wx, wy, wz] = importfile(horzcat('measurements/s3', app{n}));
    s3(n,:) = [mean(ax), mean(ay), mean(az), mean(wx), mean(wy), mean(wz)];
    [t, ax, ay, az,  wx, wy, wz] = importfile(horzcat('measurements/s4', app{n}));
    s4(n,:) = [mean(ax), mean(ay), mean(az), mean(wx), mean(wy), mean(wz)];
    [t, ax, ay, az,  wx, wy, wz] = importfile(horzcat('measurements/s5', app{n}));
    s5(n,:) = [mean(ax), mean(ay), mean(az), mean(wx), mean(wy), mean(wz)];
    [t, ax, ay, az,  wx, wy, wz] = importfile(horzcat('measurements/s6', app{n}));
    s6(n,:) = [mean(ax), mean(ay), mean(az), mean(wx), mean(wy), mean(wz)];
end