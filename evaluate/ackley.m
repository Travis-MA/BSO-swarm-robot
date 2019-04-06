function value = ackley(xx)
    minvalue = 0.6465;
    
    x = xx-minvalue;
    para1 = x * x';
    para2 = sum(cos(2 * pi * x'));
   
    value = -20 * exp(-0.2 * sqrt(0.5 * para1)) - exp(0.5 * para2) + exp(1) + 20;
end