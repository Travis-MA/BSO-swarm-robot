clear;
clc;

%% FetchData

data_path = '/home/kurt/桌面/BSO-swarm-robot/simulation/final_test1/bso_0/';

p00 = csvread([data_path, '1.csv']); 
p01 = csvread([data_path, '2.csv']); 
p02 = csvread([data_path, '3.csv']); 
p03 = csvread([data_path, '4.csv']); 
p04 = csvread([data_path, '5.csv']); 
p05 = csvread([data_path, '6.csv']); 
p06 = csvread([data_path, '7.csv']); 

% p00 = csvread([data_path, '0.0.csv']); 
% p01 = csvread([data_path, '0.1.csv']); 
% p02 = csvread([data_path, '0.2.csv']); 
% p03 = csvread([data_path, '0.3.csv']); 
% p04 = csvread([data_path, '0.4.csv']); 
% p05 = csvread([data_path, '0.5.csv']); 
% p06 = csvread([data_path, '0.6.csv']); 
% p07 = csvread([data_path, '0.7.csv']); 
% p08 = csvread([data_path, '0.8.csv']); 
% p09 = csvread([data_path, '0.9.csv']); 
% p10 = csvread([data_path, '1.0.csv']); 


dimension = 7; %7
run_step = 5; %5

now_eta = linspace(0.142, 0.995, dimension);
%p = [p00, p01, p02, p03, p04, p05, p06, p07, p08, p09, p10];
p = [p00, p01, p02, p03, p04, p05, p06];
%% Delaunay triangulate coefficient

dim = size(p00);
% For every single ETA

mat_var = [];
mat_ratio = [];
mat_unif = [];
mat_disp_x  = [];
mat_disp_y = [];
for eta = 0 : dimension-1
    
    % For every single percenet
    eta_var = [];
    eta_ratio = [];
    eta_unif = [];
    eta_disp_x = [];
    eta_disp_y = [];
    for pct = 1 : dim(2)/2-1
        
        x = p(:, eta*2*run_step + (pct-1)*2 + 1);    
        y = p(:, eta*2*run_step + (pct-1)*2 + 2);    
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
        
        %%%%%%%%%%%%%%%% 记得改三次方！！！！！！！！！！！！
        eta_disp_x = [eta_disp_x; sum(x)];
        eta_disp_y = [eta_disp_y; sum(abs(y))];
    end
    
    mat_var = [mat_var, eta_var];
    mat_ratio = [mat_ratio, eta_ratio];
    mat_unif = [mat_unif, eta_unif];
    mat_disp_x = [mat_disp_x, eta_disp_x];
    mat_disp_y = [mat_disp_y, eta_disp_y];
end

figure(1);
subplot(1,3,1); surfc(mat_disp_x);
subplot(1,3,2); plot(sum(mat_disp_x)./run_step);
subplot(1,3,3); plot(mat_disp_x(end,:));


% figure(1);0000001
% subplot(1,3,1); surfc(mat_var);
% subplot(1,3,2); plot(sum(mat_var)./run_step);
% subplot(1,3,3); plot(mat_var(end,:));

figure(2);
subplot(1,3,1); surfc(mat_disp_y);
subplot(1,3,2); plot(sum(mat_disp_y)./run_step);
subplot(1,3,3); plot(mat_disp_y(end,:));


Cx = mat_disp_x(end,:) ./ sum(mat_disp_x(end,:))
Cy = mat_disp_y(end,:) ./ sum(mat_disp_y(end,:))


uni_disp_c =  Cx .*  Cx + Cy .* Cy

p_x = polyfit(now_eta, Cx, 2);
p_y = polyfit(now_eta, Cy, 2);
p_c = polyfit(now_eta, uni_disp_c, 2);

x = linspace(0,1,100);
match_x = p_x(1)*x.*x + p_x(2)*x + p_x(3);
match_y = p_y(1)*x.*x + p_y(2)*x + p_y(3);
match_c = p_c(1)*x.*x + p_c(2)*x + p_c(3);
%match_c =    match_x .* match_x .* match_x + 1000 * match_y .* match_y .* match_y ;
match_c = match_c ./ 7;
figure(3);
combine = 4 * match_x .* match_x + match_y .* match_y;
subplot(1,3,1); plot(x, match_x,'-');title('Cx');grid on; 
hold on; plot(now_eta, Cx, 'x-'); hold off;

subplot(1,3,2); plot(x, match_y,'-'); title('Cy');grid on;
hold on; plot(now_eta, Cy, 'x-'); hold off;

subplot(1,3,3); plot(x, combine); title('Merge');grid on;
for i  = 1:dimension
    merge_idx(i)= combine(round(i * 100 / dimension));
end

mini = x(find(combine == min(combine)))
min_merge = min(combine)
merge_idx
now_eta
     