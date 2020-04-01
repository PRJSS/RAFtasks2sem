
#include <iostream>
#include <ctime>
using namespace std;
template <typename T, typename N>
void Merge(T *arr, N first, N last)
{
    N middle, start, final, j;
    T *array=new T[100];
    
    middle=(first+last)/2; //вычисление среднего элемента
    start=first; //начало левой части
    final=middle+1; //начало правой части
    
    for(j=first; j<=last; j++)
    if ((start<=middle) && ((final>last) || (arr[start]<arr[final])))
    {
    array[j]=arr[start];
    start++;
    }
    else
    {
    array[j]=arr[final];
    final++;
    }
    
//возвращение результата в список
    for (j=first; j<=last; j++) arr[j]=array[j];
    delete[]array;
}
//рекурсивная процедура сортировки
template <typename T, typename N>
void MergeSort(T *arr, N first, N last)
{
    if (first<last)
{
    MergeSort(arr, first, (first+last)/2); //сортировка левой части
    MergeSort(arr, (first+last)/2+1, last); //сортировка правой части
    Merge(arr, first, last); //слияние двух частей
}
}
