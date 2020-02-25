//
//  main.cpp
//  5.5
//
//  Created by Danila Bernat on 2/10/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//


#include <iostream>
#include <cmath>

using namespace std;
int const epsilon=0.000001;


double f(double x) {
    return x*x-pow(2.71828, x)-1.5*s; // Заменить функцией, корни которой мы ищем
}

// a, b - пределы хорды, epsilon — необходимая погрешность
double findRoot(double a, double b, double epsilon) {
    while(fabs(b - a) > epsilon) {
        a = b - (b - a) * f(b) / (f(b) - f(a));
        b = a + (a - b) * f(a) / (f(a) - f(b));
    }
    // a, b — (i - 1)-й и i-й члены

    return b;
}




void func1(int a, int b){
    cout<<"a) ";//<<sqrt(5)+1<<", "<<sqrt(5)-1;
    if (a<(sqrt(5)+1)<b){cout<<sqrt(5)+1<<" ";}
     if (a<(sqrt(5)+1)<b){cout<<sqrt(5)-1<<" ";}
}

void func2(int a, int b){

}




int main() {
    
    cout<<"S\t"<<"X\t"<<"F(x)\t"<<"K_iter\t";
    
    double x, y, a, b;
    cin>>a>>b;
    func1(a, b);

    func2(<#int a#>, <#int b#>)
    
}
