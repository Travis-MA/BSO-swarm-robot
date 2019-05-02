function value = objective_function(xx)

     rang_l = -5.12;    % left of dynamic range rastrigin
     rang_r = 5.12;     % right of dynamic range
     moid = (rang_r - rang_l)/5;
     
     old_relation = importdata('relation.txt');
     relation = ceil((xx - rang_l)./moid);
     goal_x= [10, 25, 15, 40, 20];
     goal_y = [15, 15, -20, 20, -30];
     level = [1, 2, 2, 1, 3];
     goal_bus = [0, 0, 0, 0, 0];
     
    
     Reach = csvread('reach.csv'); 
     x = Reach(: , 1);
     y = Reach(: , 2);
     
     alpha = 0.2;
     beta = 0.8; 
     gama = 0.2;
     
     term1 = 0;
     term3 = 0;
     for i = 1:42
           if( relation(i) > 5)
                relation(i) = 5;
           elseif( relation(i) < 1)
                relation(i) = 1;
           end
           term1 = term1 + sqrt( (x(i) - goal_x(relation(i)))^2 + (y(i) - goal_y(relation(i)))^2 );
           goal_bus(relation(i)) = goal_bus(relation(i))+1;
           if(relation(i)~=old_relation(i))
                term3 = term3 + 1;
           end
     end

     term2 = 0;
     for i = 1:5
         term2 = term2 + level(i)/sum(level)*42/goal_bus(i);
     end
     
     value = alpha * term1/200 + beta * term2 + gama * term3/6;
     
end