#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <string>
#include "kmeans.h"
using namespace std;

class Function
{
public:
	Function();
	double fun(Point point);
}; 
