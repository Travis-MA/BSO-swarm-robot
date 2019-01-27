clear;
clc;

Reach = csvread('reach.csv'); 
x = Reach(: , 1);
y = Reach(: , 2);

s = dir('tmp.csv');
if s.bytes == 0
     data = table(x, y);
     writetable(data, 'tmp.csv', 'WriteVariableNames', false) 
else
    old = csvread('tmp.csv'); 
    new_data = [old,  x,  y];
    data = table(new_data);
    writetable(data, 'tmp.csv', 'WriteVariableNames', false) 
end

now = csvread('tmp.csv'); 
a = size(now);
times = a(2)/2