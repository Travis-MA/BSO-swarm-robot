  /function best_fitness = bso(fun,n_p,n_d,n_c,rang_l,rang_r,max_iteration)
% fun = fitness_function
% n_p; population size
% n_d; number of dimension
% n_c: number of clusters
% rang_l; left boundary of the dynamic range
% rang_r; right boundary of the dynamic range

prob_one_cluster = 0.8; % probability for select one cluster to form new individual; 

stepSize = ones(1,n_d); % effecting the step size of generating new individuals by adding random values

popu = rang_l + (rang_r - rang_l) * rand(n_p,n_d); % initialize the population of individuals

popu_sorted  = rang_l + (rang_r - rang_l) * rand(n_p,n_d); % initialize the  population of individuals sorted according to clusters

n_iteration = 0; % current iteration number

% initialize cluster probability to be zeros
prob = zeros(n_c,1);

best = zeros(n_c,1);  % index of best individual in each cluster

centers = rang_l + (rang_r - rang_l) * rand(n_c,n_d);  % initialize best individual in each cluster
centers_copy = rang_l + (rang_r - rang_l) * rand(n_c,n_d);  % initialize best individual-COPY in each cluster FOR the purpose of introduce random best

best_fitness = 1000000*ones(max_iteration,1);
fitness_popu = 1000000*ones(n_p,1);  % store fitness value for each individual
fitness_popu_sorted = 1000000*ones(n_p,1);  % store  fitness value for each sorted individual

indi_temp = zeros(1,n_d);  % store temperary individual

% calculate fitness for each individual in the initialized population
for idx = 1:n_p
    fitness_popu(idx,1) = fun(popu(idx,:));
end

while n_iteration < max_iteration
    
    cluster = kmeans(popu, n_c,'Distance','cityblock','Start',centers,'EmptyAction','singleton'); % k-mean cluster

    % clustering    
    fit_values = 100000000000000000000000000.0*ones(n_c,1);  % assign a initial big fitness value  as best fitness for each cluster in minimization problems
    
    number_in_cluster = zeros(n_c,1);  % initialize 0 individual in each cluster
           
    for idx = 1:n_p
        number_in_cluster(cluster(idx,1),1)= number_in_cluster(cluster(idx,1),1) + 1;
               
        % find the best individual in each cluster
        if fit_values(cluster(idx,1),1) > fitness_popu(idx,1)  % minimization
            fit_values(cluster(idx,1),1) = fitness_popu(idx,1);
            best(cluster(idx,1),1) = idx;
        end
            
    end
    
    % form population sorted according to clusters
    counter_cluster = zeros(n_c,1);  % initialize cluster counter to be 0 
    
    acculate_num_cluster = zeros(n_c,1);  % initialize accumulated number of individuals in previous clusters
    
    for idx =2:n_c
        acculate_num_cluster(idx,1) = acculate_num_cluster((idx-1),1) + number_in_cluster((idx-1),1);
    end
    
    acculate_num_cluster
    
    %start form sorted population
    for idx = 1:n_p
        counter_cluster(cluster(idx,1),1) = counter_cluster(cluster(idx,1),1) + 1 ;
        temIdx = acculate_num_cluster(cluster(idx,1),1) +  counter_cluster(cluster(idx,1),1);
        popu_sorted(temIdx,:) = popu(idx,:);
        fitness_popu_sorted(temIdx,1) = fitness_popu(idx,1);
    end
       
    % record the best individual in each cluster
    for idx = 1:n_c
        centers(idx,:) = popu(best(idx,1),:);        
    end
    
    centers_copy = centers;  % make a copy
    
    if (rand() < 0.2) %  select one cluster center to be replaced by a randomly generated center
        cenIdx = ceil(rand()*n_c);
        centers(cenIdx,:) = rang_l + (rang_r - rang_l) * rand(1,n_d);
    end 
           
    % calculate cluster probabilities based on number of individuals in
    % each cluster
    for idx = 1:n_c
        prob(idx,1) = number_in_cluster(idx,1)/n_p;
        if idx > 1
            prob(idx,1) = prob(idx,1) + prob(idx-1,1);
        end
    end
    
    % generate n_p new individuals by adding Gaussian random values
                   
    for idx = 1:n_p
        r_1 = rand();  % probability for select one cluster to form new individual
        if r_1 < prob_one_cluster % select one cluster
            r = rand();
            for idj = 1:n_c
                if r < prob(idj,1)                      
                    if rand() < 0.4  % use the center
                       indi_temp(1,:) = centers(idj,:); 
                    else % use one randomly selected  cluster
                        indi_1 = acculate_num_cluster(idj,1) + ceil(rand() * number_in_cluster(idj,1));
                        indi_temp(1,:) = popu_sorted(indi_1,:);  
                    end
                    break
                end
            end
        else % select two clusters
            % pick two clusters 
            cluster_1 = ceil(rand() * n_c);
            indi_1 = acculate_num_cluster(cluster_1,1) + ceil(rand() * number_in_cluster(cluster_1,1));
            
            cluster_2 = ceil(rand() * n_c);
            indi_2 = acculate_num_cluster(cluster_2,1) + ceil(rand() * number_in_cluster(cluster_2,1));
            
            tem = rand();
            if rand() < 0.5 %use center
                indi_temp(1,:) = tem * centers(cluster_1,:) + (1-tem) * centers(cluster_2,:); 
            else   % use randomly selected individuals from each cluster            
                indi_temp(1,:) = tem * popu_sorted(indi_1,:) + (1-tem) * popu_sorted(indi_2,:); 
            end
        end         
        
        stepSize = logsig( ( (0.5*max_iteration - n_iteration) /20)    ) * rand(1,n_d);
        
        
        indi_temp(1,:) = indi_temp(1,:) + stepSize .* normrnd(0,1,1,n_d);
        % if better than the previous one, replace it
        fv = fun(indi_temp);
        if fv < fitness_popu(idx,1)  % better than the previous one, replace
            fitness_popu(idx,1) = fv;
            popu(idx,:) = indi_temp(1,:);
        end 
        
    end
        
    % keep the best for each cluster
    for idx = 1:n_c
        popu(best(idx,1),:) = centers_copy(idx,:);  
        fitness_popu(best(idx,1),1) = fit_values(idx,1);
    end
       
    n_iteration = n_iteration +1;
    
    % record the best fitness in each iteration
    best_fitness(n_iteration, 1) = min(fit_values);
end


    
    

