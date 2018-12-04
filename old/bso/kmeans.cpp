// Authors: Siqing Ma
// Date: 2018-11-15 created, 2018-12-1 updated
// Kmeans algorithm 
// Distance mode: "cityblock"
// EmptyAction mode: "singleton"

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <string>
#include "kmeans.h"
using namespace std;

Point::Point(int id_point, vector<double>& values)
{
	this->id_point = id_point;
	nd = values.size();
	for (int i = 0; i < nd; i++) this->values.push_back(values[i]);
	id_cluster = -1;
}

int Point::getID()
{
	return id_point;
}

void Point::setID(int id)
{
	this->id_point = id;
}

void Point::setCluster(int id_cluster)
{
	this->id_cluster = id_cluster;
}

int Point::getCluster()
{
	return id_cluster;
}

double Point::getValue(int index)
{
	return values[index];
}

int Point::getDimension()
{
	return nd;
}

void Point::setValue(int index, double value)
{
	values[index] = value;
}



Cluster::Cluster(int id_cluster, Point point)
{
	this->id_cluster = id_cluster;
	int dimension = point.getDimension();

	for (int i = 0; i < dimension; i++)
		central_values.push_back(point.getValue(i));

	//points.insert(pair<int, Point>(point.getID(), point));
}

void Cluster::addPoint(Point point)
{
	points.insert(pair<int, Point>(point.getID(), point));
}

void Cluster::removePoint(int id_point)
{
	points.erase(id_point);
}

double Cluster::getCentralValue(int index)
{
	return central_values[index];
}

void Cluster::setCentralValue(int index, double value)
{
	central_values[index] = value;
}

int Cluster::getSize()
{
	return points.size();
}

int Cluster::getID()
{
	return id_cluster;
}

map<int, Point> Cluster::getPoints()
{
	return points;
}



KMeans::KMeans(int nc, int np, int nd, int max_iterations, vector<Point> centers)
{
	this->nc = nc;
	this->np = np;
	this->nd = nd;
	this->max_iterations = max_iterations;
	this->init_centres = centers;
}

int KMeans::getNearestCentreId(Point point)
{
	double sum = 0.0, min_dist;
	int nearest_centre_id = 0;


	// Initial
	// Uses city block distance
	for (int i = 0; i < nd; i++)
	{
		sum += abs(clusters[0].getCentralValue(i) -
			point.getValue(i));
	}
	min_dist = sum;

	for (int i = 1; i < nc; i++)
	{
		double dist;
		sum = 0.0;
		// Uses city block distance
		for (int j = 0; j < nd; j++)
		{
			sum += abs(clusters[i].getCentralValue(j) -
				point.getValue(j));
		}
		dist = sum;

		if (dist < min_dist)
		{
			min_dist = dist;
			nearest_centre_id = i;
		}
	}
	return nearest_centre_id;
}

Cluster KMeans::getCluster(int index)
{
	return clusters[index];
}

vector<int> KMeans::getDependency()
{
	return dependency;
}

void KMeans::run(vector<Point> & po)
{
	if (nc > np)
		return;

	vector<int> now_indexes;

	// Initial the cluster centre by using the provided centre_2018-11-19
	for (int i = 0; i < nc; i++)
	{
		init_centres[i].setID(-1);
		Cluster centre(i, init_centres[i]);
		clusters.push_back(centre);
	}

	for (int i = 0; i < np; i++)
	{
		po[i].setCluster(-1);
	}

	int iter = 1;
	while (true)
	{
		bool done = true;
		// associates each point to the nearest center
		for (int i = 0; i < np; i++)
		{
			int id_old_cluster = po[i].getCluster();
			int id_nearest_center = getNearestCentreId(po[i]);

			if (id_old_cluster != id_nearest_center)
			{
				if (id_old_cluster != -1)
					clusters[id_old_cluster].removePoint(po[i].getID()); 

				po[i].setCluster(id_nearest_center);
				clusters[id_nearest_center].removePoint(-1); 
				clusters[id_nearest_center].addPoint(po[i]);
				done = false;
			}
		}

		// recalculating the center of each cluster
		map<int, Point> points;
		for (int i = 0; i < nc; i++)
		{
			for (int j = 0; j < nd; j++)
			{
				double sum = 0.0;
				points = clusters[i].getPoints();
				map<int, Point>::iterator iter = points.begin();
				
				if (points.size() > 0)
				{
					while (iter != points.end())
					{
						sum += iter->second.getValue(j); iter++;
					}
					clusters[i].setCentralValue(j, sum / clusters[i].getSize());
				}
			}
		}
		if (done == true || iter >= max_iterations) break;
		iter++;
	}

	//check empty
	int new_cluster = 0;
	double maxlen = -10000000;
	double sum = 0;
	for (int i = 0; i < nc; i++) 
	{
		if (clusters[i].getSize() == 0)
		{	
			for (int j = 0; j < po.size(); j++) 
			{
				for (int k = 0; k < nd; k++)
				{
					sum += abs(clusters[i].getCentralValue(k) - po[j].getValue(k));
				}
				if (sum > maxlen) 
				{
					maxlen = sum;
					new_cluster = j;
				}
			}
			int oclu = po[new_cluster].getCluster();
			po[new_cluster].setCluster(i);
			clusters[i].addPoint(po[new_cluster]);
			for (int j = 0; j < nd; j++) 
			{
				clusters[i].setCentralValue(j, po[new_cluster].getValue(j));
			}
			clusters[oclu].removePoint(po[new_cluster].getID());
			//cout << "add: " << i << " ps: " << presize << " ns " << nowsize << " clusize: " << clusters[i].getSize()<< endl;
		}
	}

	dependency.resize(np);
	int id = 0;
	map<int, Point> points;
	for (int i = 0; i < nc; i++)
	{
		points = clusters[i].getPoints();
		points.erase(-1);
		map<int, Point>::iterator iter = points.begin();
		while (iter != points.end())
		{
			id = iter->first;
			dependency[id] = i;
			iter++;
		}		
	}
}
