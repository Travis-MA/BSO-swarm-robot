clear;
clc;

Reach = csvread('reach0.4.1.csv');
x = Reach(: , 1);
y = Reach(: , 2);

TRI = delaunay(x,y);  % get the triangulate results
dim = size(TRI, 1); 

TRI_id = [ [1 : dim]', TRI];

peri = zeros(dim, 1);



figure; 
axis([ -5, 60, -20, 20 ]);
grid on;
hold on;

for i = 1 : dim
    t1 = TRI(i, :);

    for j = 1 : length(t1)-1
        
        xt = [x(t1(j)) x(t1(j+1))];
        yt = [y(t1(j)) y(t1(j+1))];

        plot(xt, yt, 'k-', 'LineWidth', 1);
    end

    xt = [x(t1(end)) x(t1(1))];
    yt = [y(t1(end)) y(t1(1))];

    plot(xt, yt, 'k-', 'LineWidth', 1);
end

