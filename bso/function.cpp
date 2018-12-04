// Authors: Siqing Ma
// Date: 2018-11-15 created, 2018-12-1 updated
// BSO FUNCTION


#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "kmeans.h"
#include "function.h"


using namespace std;

Function::Function() {}

double Function::fun(Point point)
{
	double z = 0;
	for (int i = 0; i < 10; i++) 
	{
		z = z + pow(point.getValue(i), 2) + 10 - 10 * cos(2 * 3.141592654 * point.getValue(i));
	}
	return z;
}