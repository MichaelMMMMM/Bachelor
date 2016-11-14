%12.11.2016, Michael Meindl, Bestimmung des Phi-Offset

load('accel_polynoms');
load('phioffset');

a_S1_y = feval(x1_polynom, sensordata_phi_offset.mX1__dd);
a_S2_y = feval(x2_polynom, sensordata_phi_offset.mX2__dd);
a_S1_x = feval(y1_polynom, sensordata_phi_offset.mY1__dd);
a_S2_x = feval(y2_polynom, sensordata_phi_offset.mY2__dd);

l1 = 0.14;
l2 = 0.061;
g  = 9.81;

y_9  = a_S1_x - l1/l2*a_S2_x;
y_10 = a_S1_y - l1/l2*a_S2_y;
y_11 = y_10./y_9;

phi_9  = acosd(y_9 /(-g*(1-l1/l2)));
phi_10 = asind(y_10 /(g*(1-l1/l2)));
phi_11 = -atand(y_11);

t = sensordata_phi_offset.mTime;

phi_offset = mean(phi_11(1:7000));