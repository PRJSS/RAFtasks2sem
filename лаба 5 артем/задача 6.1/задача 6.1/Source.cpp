#include "Function.h"


double Simpson (double (*equation)(double, double, double),
				double leftborder,
				double x,
				double rightborder,
				double argument,
				double argument1,
				double esp,
				int Number_of_partitions)
{
	double k1 = 0, k2 = 0;
	const double h = (rightborder - leftborder) / Number_of_partitions;

	for (int i = 1; i < Number_of_partitions; i += 2)
	{
		k1 += equation(leftborder + i * h,argument,argument1);
		k2 += equation(leftborder + (i + 1) * h,argument,argument1);
	}

	return	h / 3 * (equation(x,argument,argument1) + 4 * k1 + 2 * k2);
}

double equation(double x, double s, double t)
{
	return pow(sin(pow(x,t)),2)/(sqrt(1+x*x*x));
}
