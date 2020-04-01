
#include <iostream>
#include <ctime>
#include "Random.h"
#include "Sort.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int i, n;
    double *arr=new double[10];
    cout<<"Размер массива "; cin>>n;
    cout<<endl;

    randArray(arr,n);

    MergeSort(arr, 1, n);
    for (i=1; i<=n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    delete []arr;
}

