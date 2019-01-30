clear;
clc;

%% FetchData

data_path = 'D:\Documents A\2018\BSO-swarm-robot\simulation\orig_test1\';

p00 = csvread([data_path, '0.0.csv']); 
p01 = csvread([data_path, '0.1.csv']); 
p02 = csvread([data_path, '0.2.csv']); 
p03 = csvread([data_path, '0.3.csv']); 
p04 = csvread([data_path, '0.4.csv']); 
p05 = csvread([data_path, '0.5.csv']); 
p06 = csvread([data_path, '0.6.csv']); 

now_eta = [1.42, 2.85, 4.27, 5.69, 7.11, 8.53, 9.95];
p = [p00, p01, p02, p03, p04, p05, p06];
%% Delaunay triangulate coefficient

dim = size(p00);
% For every single ETA

mat_var = [];
mat_ratio = [];
mat_unif = [];
mat_disp_x  = [];
mat_disp_y = [];
for eta = 0 : 6
    
    % For every single percenet
    eta_var = [];
    eta_ratio = [];
    eta_unif = [];
    eta_disp_x = [];
    eta_disp_y = [];
    for pct = 1 : dim(2)/2-1
        
        x = p(:, eta*30 + (pct-1)*2 + 1);    
        y = p(:, eta*30 + (pct-1)*2 + 2);    
        TRI = delaunay(x,y);

        peri = [];
        unif = 0;
        tri_dim = size(TRI, 1); % Triangular number
        for i = 1 : tri_dim  %calulate the variance of every triangular
            peri = [peri,  (x(TRI(i, 1)) + x(TRI(i, 2))+x(TRI(i, 3)))];
            sub_peri = x(TRI(i, 1)) + x(TRI(i, 2))+x(TRI(i, 3));
            sub_unif = std([abs(x(TRI(i, 1))-x(TRI(i, 2))), abs(x(TRI(i, 1))-x(TRI(i, 3))), abs(x(TRI(i, 2))-x(TRI(i, 3)))]);
            unif = unif + sub_unif;
        end
        
        var = std(peri);
        ratio = (max(x) - min(x)) / (max(y) - min(y));
        eta_var = [eta_var; var];
        eta_ratio = [eta_ratio; ratio];
        eta_unif = [eta_unif; unif];
        eta_disp_x = [eta_disp_x; sum(x)/42];
        eta_disp_y = [eta_disp_y; sum(abs(y))/42];
    end
    
    mat_var = [mat_var, eta_var];
    mat_ratio = [mat_ratio, eta_ratio];
    mat_unif = [mat_unif, eta_unif];
    mat_disp_x = [mat_disp_x, eta_disp_x];
    mat_disp_y = [mat_disp_y, eta_disp_y];
end

% figure(1);
% subplot(1,3,1); surfc(mat_disp_x);
% subplot(1,3,2); plot(sum(mat_disp_x)./15);
% subplot(1,3,3); plot(mat_disp_x(end,:));
% 
% figure(2);
% subplot(1,3,1); surfc(mat_disp_y);
% subplot(1,3,2); plot(sum(mat_disp_y)./15);
% subplot(1,3,3); plot(mat_disp_y(end,:));

uni_disp_x = mat_disp_x(end,:) ./ sum(mat_disp_x(end,:));
uni_disp_y = mat_disp_y(end,:) ./ sum(mat_disp_y(end,:));
p_x = polyfit(now_eta, uni_disp_x, 2);
p_y = polyfit(now_eta, uni_disp_y, 2);

x = linspace(1,10,100);
match_x = p_x(1)*x.*x + p_x(2)*x + p_x(3);
match_y = p_y(1)*x.*x + p_y(2)*x+ p_y(3);

figure(1);
combine = 4 * match_x .* match_x + match_y .* match_y;
subplot(1,3,1); plot(x, match_x);
subplot(1,3,2); plot(x, match_y);
subplot(1,3,3); plot(x, combine);
min = x(find(combine == min(combine)))
     