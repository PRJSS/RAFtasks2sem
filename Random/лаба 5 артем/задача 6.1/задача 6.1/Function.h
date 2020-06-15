#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;



double Simpson(double (*equation)(double, double, double),
	double leftborder = 3,
	double x = 3,
	double rightborder = 4.254,
	double argument = 1,
	double argument1 = 0.5,
	double esp = 0.000001,//
	int Number_of_partitions = 2);
double equation(double x, double s, double t);

