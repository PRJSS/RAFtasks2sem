//
//  main.cpp
//  7.6
//
//  Created by Danila Bernat on 5/20/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include "ListFunc.h"
using namespace std;
int main()
{
    int n;
    cout << "Enter N: "; cin >> n;
    n *= 2;

    double a;
    Node* listA = NULL;
    cout << "Enter list: ";
    for (int i = 0; i < n; i++){
        cin >> a;
        add(listA, a);
    }
    
    print(listA);
    
    cout<<"+\n";
    
    printRevers(listA);
    

    cout << "Max Summ: "<< maxSum(listA);

    
    cout<<"\n\n";
    return 0;
}
