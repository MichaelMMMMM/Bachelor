n  = 1024;
fa = 100;
dt = 1/fa;
t  = 0:dt:(n-1)*dt;
s = rand(1,n);

for k = 3:1:n
    s(k) = mean(s(k-2:k)); 
end
x  = sin(2*pi*10*t);

plot(t, x);

spec = fft(x);
spec = abs(spec)/2/pi/fa;
spec = [spec(n/2:n), spec(1:n/2-1)];

plot(abs(spec));

df = fa/n;
f = -fa/2:df:fa/2-df;
m = 0:1:n-1;
w = 2*pi*m/n;

stem(w, abs(spec)); grid;

df = 1/n*fa;
f = -n/2*df:df:(n/2-1)*df;
figure;
stem(f, spec); grid