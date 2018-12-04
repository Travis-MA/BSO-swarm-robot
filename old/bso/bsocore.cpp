// Authors: Siqing Ma
// Date: 2018-11-15 created, 2018-12-1 updated
// BSO CORE

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <string>
#include <random>
#include "kmeans.h"
#include "function.h"

using namespace std;
#define INF 1000000000;


/*
*  Gnerate an uniform distribution random variable in [0, 1]
*/
double uniRand()
{
	default_random_engine e;
	random_device r;
	e.seed(r());
	uniform_real_distribution<double> u(0, 1);
	return u(e);
}

/* Generate a set of random value sample points
*  [min, max]: the uniform distribution domain
*  m: Sample point number
*  n: Single point value dimension
*/
vector<Point> randomSet(double min, double max, int m, int n)
{
	vector<Point> po;
	for (int i = 0; i < m; i++)
	{
		vector<double> content;
		for (int j = 0; j < n; j++)
		{
			default_random_engine e; random_device r; e.seed(r());
			uniform_real_distribution<double> u(min, max);
			content.push_back(u(e));
		}
		Point point(i, content); po.push_back(point);
	}
	return po;
}

/* Generate a random value sample points
*  [min, max]: the uniform distribution domain
*  n: Point value dimension
*  id: Point id
*/
Point randomPoint(double min, double max, int n, int id)
{
	vector<double> content;
	for (int j = 0; j < n; j++)
	{
		default_random_engine e; random_device r; e.seed(r());
		uniform_real_distribution<double> u(min, max);
		content.push_back(u(e));
	}
	Point point(id, content);
	return point;
}

/* Sample point multiply with a number (value * coef)
*  coef: 
*  origin: 
*/
Point pointMtply(double coef, Point origin)
{
	int dim = origin.getDimension();
	vector<double> newvel(dim);
	for (int i = 0; i < dim; i++)
	{
		newvel[i] = coef * origin.getValue(i);
	}
	Point ans(-1, newvel); 
	return ans;
}

/* Sample point multiply with each other (value * value)
*  p1:
*  p2:
*/
Point pointAdd(Point p1, Point p2)
{
	int dim = p1.getDimension();
	vector<double> newvel(dim);

	for (int i = 0; i < dim; i++)
	{
		newvel[i] = p1.getValue(i) + p2.getValue(i);
	}
	Point ans(-1, newvel); 
	return ans;
}


int main(int argc, char *argv[])
{
	srand(time(NULL));

	const int np = 100; // Number of population
	const int nd = 10; // Number of dimension
	const int nc = 5;  // Number of cluster
	
	const double rang_l = -5.12; // Point values limits
	const double rang_r = 5.12;
	
	const int max_iteration = 250; // Pick any deviations you want
	
	const int max_run = 5; // Pick any laps you want
	Function Fun;

	// Runs off laps from here
	for (int idx = 0; idx < max_run; idx++)
	{
		// Genetate a random 
		vector<Point> popu = randomSet(rang_l, rang_r, np, nd);
		vector<Point> popu_sort = randomSet(rang_l, rang_r, np, nd);
		vector<double> prob(nc); // Initialize cluster probability
		vector<double> best(nc); // Index of best individual in each cluster
		vector<Point> centers = randomSet(rang_l, rang_r, nc, nd); // Randomly pick a best individual in each cluster

		// initialize best individual - COPY in each cluster FOR the purpose of introduce random best
		vector<Point> centers_copy = randomSet(rang_l, rang_r, nc, nd);
		vector<double> best_fitness(max_iteration);
		vector<double> fit_popu(np); // Store fitness value for each individual
		vector<double> fit_popu_sorted(np); // Store fitness value for each sorted individual
		Point indi_temp = randomPoint(rang_l, rang_r, nd, 0); // Store temperary individual


		// Evaluate the fitness of n ideas
		for (int times = 0; times < np; times++)
		{
			fit_popu[times] = Fun.fun(popu[times]); 
		}

		int n_iteration = 0;
		while (n_iteration < max_iteration)
		{
			cout << "Iteration: " << n_iteration << endl;
			KMeans kmeans(nc, np, nd, 100, centers);
			kmeans.run(popu);  // Cluster each population

			vector<int> cluster = kmeans.getDependency(); // Containing cluster indices of each observation.
			vector<double> fit_values(nc,0);
			vector<int> number_in_cluster(nc,0); // The number of points in each cluster

			// Initialize the fit_values and get the number in each cluster
			for (int clu = 0; clu < nc; clu++)
			{
				fit_values[clu] = INF;  // Assign a initial big fitness value as best fitness
				number_in_cluster[clu] = kmeans.getCluster(clu).getSize();
			}

			for (int times = 0; times < np; times++)
			{
				// Find the best individual in each cluster
				if (fit_values[cluster[times]] > fit_popu[times])
				{
					fit_values[cluster[times]] = fit_popu[times];
					best[cluster[times]] = times; // Refresh the index of best individual in each cluster			
				}
			}

			vector<int> counter_cluster(nc,0); // Initialization cluster counter
			vector<int> acculate_num_cluster(nc,0); // Accumulated number of individuals in previous clusters

			// Check with every cluster
			acculate_num_cluster[0] = 0;
			for (int times = 1; times < nc; times++)
			{
				acculate_num_cluster[times] = acculate_num_cluster[times - 1] + number_in_cluster[times - 1];
			}

			// Evaluate the individuals
			for (int times = 0; times < np; times++)
			{
				counter_cluster[cluster[times]]++;
				int temldx = acculate_num_cluster[cluster[times]] + counter_cluster[cluster[times]];
				popu_sort[temldx - 1] = popu[times]; // The population of individuals sorted according to clusters
				fit_popu_sorted[temldx - 1] = fit_popu[times]; // Fitness value for each sorted individual
			}

			// Rank individuals in each cluster
			for (int times = 0; times < nc; times++)
			{
				centers[times] = popu[best[times]];
			}
			// make a copy
			centers_copy.assign(centers.begin(), centers.end()); 

			// Select one cluster center to be replaced by a randomly generated center
			if (uniRand() < 0.2)
			{
				int cenldx = floor(uniRand()*nc);
				centers[cenldx] = randomPoint(rang_l, rang_r, nd, cenldx);
			}

			// Calculate cluster probabilities based on number of individuals in each cluster
			for (int times = 0; times < nc; times++)
			{
				prob[times] = number_in_cluster[times] / np;
				if (times > 0)
				{
					prob[times] = prob[times] + prob[times - 1];
				}
			}


			int indi_1, indi_2, c1, c2;
			// Generate new individuals
			for (int times = 0; times < np; times++)
			{
				double r_1 = uniRand();
				if (r_1 < 0.8)
				{
					double r = uniRand();
					for (int idj = 0; idj < nc; idj++)
					{
						if (r < prob[idj])
						{
							if (uniRand() < 0.4)
							{
								indi_temp = centers[idj];
							}
							else
							{
								indi_1 = acculate_num_cluster[idj] + floor(uniRand() * number_in_cluster[idj]);
								indi_temp = popu_sort[indi_1];
							}
							break;
						}
					}
				}
				else
				{
					c1 = floor(uniRand() * nc);
					indi_1 = acculate_num_cluster[c1] + floor(uniRand() * number_in_cluster[c1]);
					c2 = floor(uniRand() * nc);
					indi_2 = acculate_num_cluster[c2] + floor(uniRand() * number_in_cluster[c2]);
					
					double tem = uniRand();
					if (uniRand() < 0.5)
					{
						indi_temp = pointAdd(pointMtply(tem, centers[c1]), pointMtply((1 - tem), centers[c2]));
					}
					else
					{
						indi_temp = pointAdd(pointMtply(tem, popu_sort[indi_1]), pointMtply((1 - tem), popu_sort[indi_2]));
					}
				}
				double coef = 1 / (1 + exp(-((0.5*max_iteration - n_iteration) / 20)));
				Point stepSize = pointMtply(coef, randomPoint(0, 1, nd, 0));

				default_random_engine e; random_device r; e.seed(r());
				normal_distribution<double> n(0, 1);
				indi_temp = pointAdd(indi_temp, pointMtply(n(e), stepSize));

				double fv = Fun.fun(indi_temp); 

				if (fv < fit_popu[times])
				{
					fit_popu[times] = fv;
					indi_temp.setID(times);
					popu[times] = indi_temp;
				}
			}

			for (int times = 0; times < nc; times++)
			{
				popu[best[times]] = centers_copy[times];
				fit_popu[best[times]] = fit_values[times];
			}

			// record the best fitness in each iteration
			double min = INF;
			for (int k = 0; k < fit_values.size(); k++)
			{
				if (min > fit_values[k]) min = fit_values[k];
			}
			best_fitness[n_iteration] = min;

			n_iteration++;
		}

		cout << "Best Fitness: ";
		for (int succ = 0; succ < best_fitness.size(); succ++)
		{
			cout << best_fitness[succ] << " ";
		}
		cout << endl;
	}

	cout << "Enter any character to exit" << endl;
	int i;
	cin >> i;
	return 0;
}
