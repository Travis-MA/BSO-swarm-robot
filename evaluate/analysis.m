clear;
clc;

%% FetchData

data_path = 'D:\Documents A\2018\BSO-swarm-robot\simulation\orig_test2\';

p00 = csvread([data_path, '0.0.csv']); 
p01 = csvread([data_path, '0.1.csv']); 
p02 = csvread([data_path, '0.2.csv']); 
p03 = csvread([data_path, '0.3.csv']); 
p04 = csvread([data_path, '0.4.csv']); 
p05 = csvread([data_path, '0.5.csv']); 
p06 = csvread([data_path, '0.6.csv']); 
p07 = csvread([data_path, '0.7.csv']); 
p08 = csvread([data_path, '0.8.csv']); 
p09 = csvread([data_path, '0.9.csv']);
p10 = csvread([data_path, '1.0.csv']); 

p = [p00, p01, p02, p03, p04, p05, p06, p07, p08, p09, p10];
%% Delaunay triangulate coefficient

dim = size(p00);
% For every single ETA

mat_var = [];
mat_ratio = [];
for eta = 0 : 10
    
    % For every single percenet
    eta_var = [];
    eta_ratio = [];
    for pct = 1 : dim(2)/2-1
        
        x = p(:, eta*30 + (pct-1)*2 + 1);    
        y = p(:, eta*30 + (pct-1)*2 + 2);    
        TRI = delaunay(x,y);

        peri = [];
        tri_dim = size(TRI, 1); % Triangular number
        for i = 1 : tri_dim  %calulate the variance of every triangular
            peri = [peri,  (x(TRI(i, 1)) + x(TRI(i, 2))+x(TRI(i, 3)))];
        end
        
        var = std(peri);
        ratio = (max(x) - min(x)) / (max(y) - min(y));
        eta_var = [eta_var; var];
        eta_ratio = [eta_ratio; ratio];
       
    end
    
    mat_var = [mat_var, eta_var];
    mat_ratio = [mat_ratio, eta_ratio];
end


figure(1);
surfc(mat_var);

figure(2);
surfc(mat_ratio);
    
    