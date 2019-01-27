clear;
clc;

p00 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.0.csv'); 
p01 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.1.csv'); 
p02 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.2.csv'); 
p03 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.3.csv'); 
p04 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.4.csv'); 
p05 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.5.csv'); 
p06 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.6.csv'); 
p07 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.7.csv'); 
p08 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.8.csv'); 
p09 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/0.9.csv');
p10 = csvread('/home/kurt/桌面/BSO-swarm-robot/simulation/test2/1.0.csv'); 

var = [ p00(:, 1), p01(:, 1), p02(:, 1), p03(:, 1), p04(:, 1), p05(:, 1), p06(:, 1), p07(:, 1), p08(:, 1), p09(:, 1), p10(:, 1) ];
ratio =  [ p00(:, 2), p01(:, 2), p02(:, 2), p03(:, 2), p04(:, 2), p05(:, 2), p06(:, 2), p07(:, 2), p08(:, 2), p09(:, 2), p10(:, 2) ];

var_final = var(end, :);
ratio_final = ratio(end, :);

a = sqrt(var .* var + 144 .* ratio .* ratio);

figure(1);
surfc(var);

figure(2);
surfc(ratio);

figure(3);
plot(var_final);

figure(4);
plot(ratio_final);

figure(5);
surfc(a);