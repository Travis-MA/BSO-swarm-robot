clear;
clc;

Reach = csvread('reach0.8.csv');
x = Reach(: , 1);
y = Reach(: , 2);
%% Delaunay triangulate

TRI = delaunay(x,y);  % get the triangulate results
dim = size(TRI, 1); % Triangular number

peri = zeros(dim, 1);


% plot the triangulate
figure; 
grid on;
hold on;

for i = 1 : dim
    t1 = TRI(i, :);
    for jy = 1 : length(t1)-1
        xt = [x(t1(jy)) x(t1(jy+1))];
        yt = [y(t1(jy)) y(t1(jy+1))];
        %plot(xt, yt, 'k-', 'LineWidth', 1);
        plot(x(t1(jy)), y(t1(jy)), 'ro', 'LineWidth', 2);
    end
    plot(x(t1(length(t1))), y(t1(length(t1))), 'ro', 'LineWidth', 2);
    xt = [x(t1(end)) x(t1(1))];
    yt = [y(t1(end)) y(t1(1))];
    %plot(xt, yt, 'k-', 'LineWidth', 1);
    
    
end
idx = 1 : length(x);
str_idx=num2str(idx(:));
text(x+0.5, y+0.5, str_idx);

%% Evaluate the uniformity coefficient

% Calculate the total variance
total_var = 0;
for i = 1 : dim  %calulate the variance of every triangular
    
    var1 = abs(x(TRI(i, 1)) - x(TRI(i, 2)));
    var2 = abs(x(TRI(i, 1)) - x(TRI(i, 3)));
    var3 = abs(x(TRI(i, 2)) - x(TRI(i, 3)));
    total_var = total_var + var([var1 var2 var3]);
end

% Do deviison 5*2
y_cent = mean(y);
x_cent = mean(x);
y_max = max(y);
y_min = min(y);
x_max = max(x);
x_min = min(x);

cluster = {} ;
clu_id = 1;
x_div = 5; 
y_div = 2;
x_step = (x_max - x_min) / x_div;
y_step = (y_max - y_min) / y_div;
%clu_x_dev = [];
%clu_y_dev = [];
for ix = 0 : x_div - 1
    for jy = 0 : y_div - 1
        %clu_x_dev = [clu_x_dev, x_min + (ix + 1) * x_step];
        %clu_y_dev = [clu_y_dev, y_min + (jy + 1) * y_step];
        now_clu = [];
        for iid = 1 : length(x)
            if(x(iid) >= x_min + ix * x_step && x(iid) < x_min + (ix + 1) * x_step + 0.00001)
                if(y(iid) >= y_min + jy * y_step && y(iid) < y_min + (jy + 1) * y_step + 0.00001)
                    now_clu = [now_clu, iid];
                    cluster{clu_id} = now_clu;
                end
            end
        end       
        clu_id = clu_id + 1;
    end
end
celldisp(cluster);
%save('cluster.txt', 'cluster');



