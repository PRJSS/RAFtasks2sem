
#include <iostream>
using namespace std;
template <typename T, typename N>

void randArray(T *arr, N n)
{
    for(int i = 1; i<=n; i++)
    {
    arr[i]=rand()%100; //
        arr[i]/=10;
    }
    for (int i=1; i<=n; i++)
       {
           cout<<arr[i]<<" ";
       }
    cout<<endl;
}
