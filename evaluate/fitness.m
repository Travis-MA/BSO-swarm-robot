clear;
clc;

n_p = 150;   % population size 10
n_d = 42;     % dimension 10
n_c = 7;     % number of clusters

funName = @objective_function; % fitness function name made for BlackBerry
rang_l = -5.12;    % left of dynamic range rastrigin
rang_r = 5.12;     % right of dynamic range

max_iteration = 1; % maximal number of iterations

fit_ans = bso(funName,n_p,n_d,n_c,rang_l,rang_r,max_iteration);%run BSO one time

moid = (rang_r - rang_l)/5;
answer = ceil((fit_ans - rang_l)./moid)
 for i = 1:42
       if(answer(i) > 5)
            answer(i) = 5;
       elseif(answer(i) < 1)
            answer(i) = 1;
       end
end
fid=fopen(['relation.txt'],'w');
for jj=1:length(answer)
    fprintf(fid,'%d ',answer(jj)); 
end
fclose(fid);

%surfc(fit_ans);
