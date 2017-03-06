%1.3.2017, Michael Meindl, Filterentwurf

orders = 2:1:10;
n      = length(orders);

Af = cell(n, 1);
Bf = cell(n, 1);
Cf = cell(n, 1);
Df = cell(n, 1);

filter_ss = cell(n,1);

f_A = 100;
f_n = 10;
W_n = f_n/(f_A/2);

for k = 1:n
    [Af{k},Bf{k},Cf{k},Df{k}] = butter(n, W_n);
    filter_ss{k} = ss(Af{k},Bf{k},Cf{k},Df{k},1/f_A);
end