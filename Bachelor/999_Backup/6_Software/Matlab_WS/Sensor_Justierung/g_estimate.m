%G-Sch�tzung aus den Sensorwerten, Z-Achse wird wegen schlechtere
%Sensitivit�t nicht verwendet

s1 = [2.5; 12.5; 14.5];
s2 = [12.5; 12.5; 14.5];
s3 = [14.5; 2.5; 12.5];
s4 = [14.5; 12.5; 12.5];
s5 = [12.5; 14.5; 2.5];
s6 = [12.5; 14.5; 12.5];

s1 = [10.9; 12.2; 14.5];
s2 = [4.1;  12.2; 14.5];
s3 = [14.5; 10.9; 12.2];
s4 = [14.5; 4.1;  12.2];
s5 = [12.2; 14.5; 10.9];
s6 = [12.2; 14.5; 4.1 ];

b1 = sym('b1_', [3 1], 'real');
b1_vals = struct2array(solve([s1, s2, s5, s6]*[b1;1] == 0));

b2 = sym('b2_', [3 1], 'real');
b2_vals = struct2array(solve([s1, s2, s3, s4]*[b2;1] == 0));

b3 = sym('b3_', [3 1], 'real');
b3_vals = struct2array(solve([s3, s4, s5, s6]*[b3;1] == 0));