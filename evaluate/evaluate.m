clear;
clc;

n_p = 108;   % population size 100
n_d = 10;     % dimension 10
n_c = 6;     % number of clusters 5

funName = @unicoef; % fitness function name made for BlackBerry
rang_l = -5.12;    % left of dynamic range rastrigin
rang_r = 5.12;     % right of dynamic range

max_iteration = 100; % maximal number of iterations
max_run = 2; % maximum number of runs

for idx = 1:max_run  % run times changed from 50 to 20 or to 8
    fit = bso(funName,n_p,n_d,n_c,rang_l,rang_r,max_iteration) %run BSO one time
    keySpace(:,idx) = fit;
end

figure(1); 
mesh(keySpace);
xlabel('round');
ylabel('iteration');
zlabel('fitness value');

