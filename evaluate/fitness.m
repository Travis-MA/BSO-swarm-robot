clear;
clc;

n_p = 150;   % population size 10
n_d = 7;     % dimension 10
n_c = 7;     % number of clusters

funName = @ackley; % fitness function name made for BlackBerry
rang_l = -5.12;    % left of dynamic range rastrigin
rang_r = 5.12;     % right of dynamic range

max_iteration = 7; % maximal number of iterations

fit_ans = bso(funName,n_p,n_d,n_c,rang_l,rang_r,max_iteration);%run BSO one time
mean(fit_ans)
fit_ans = abs(fit_ans(end, :));
for i = 1 : length(fit_ans)
    if fit_ans(i) > 1
        fit_ans(i) = fit_ans(i) / 5.12;
    end
end

fit_ans
    
%surfc(fit_ans);
