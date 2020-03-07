//
//  func.h
//  5.6
//
//  Created by Danila Bernat on 3/6/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

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

    return    h / 3 * (equation(x,argument,argument1) + 4 * k1 + 2 * k2);
}

double equation(double x, double s, double t)
{
    return pow(sin(pow(x,t)),2)/(sqrt(1+x*x*x));
}

