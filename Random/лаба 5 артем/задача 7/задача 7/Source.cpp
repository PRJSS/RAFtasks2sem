#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;


//template < typename T >
//void Enter_increase(T* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = static_cast<T>(i);
//
//		cout << setw(4) << arr[i] ;
//	}
//}
//
//template < typename T >
//void Enter_decrease(T* arr, int size)
//{
//	for (int i = size - 1; i >= 0; i--)
//	{
//		arr[i] = static_cast<T>(i);
//
//		cout << setw(4) << arr[i] ;
//	}
//
//}

template < typename T >
void Enter_random(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = rand() % 20;
		arr[i] = static_cast<T>(k);

		cout << setw(4) << arr[i] ;
	}
}


template < typename T >
int binarySearch(T arr[], T item, T low, T high) {
   if (high <= low)
      return (item > arr[low])? (low + 1): low;
      int mid = (low + high)/2;
   if(item == arr[mid])
      return mid+1;
   if(item > arr[mid])
      return binarySearch(arr, item, mid+1, high);
      return binarySearch(arr, item, low, mid-1);
}


template < typename T >
void BinaryInsertionSort(T arr[], int n) {
    int counter=0;
   int i, loc, j, selected;
   for (i = 1; i < n; ++i) {
      j = i - 1;
      selected = arr[i];
      loc = binarySearch(arr, selected, 0, j);
      while (j >= loc) {
         arr[j+1] = arr[j];
         j--;
          counter++;
      }
      arr[j+1] = selected;
   }
    for (int i = 0; i < n; i++)
    {
        cout <<" "<< arr[i];
    }
    cout <<"\n Counter "<< counter << endl;
}



template < typename T >
void choicesSort(T arrayPtr, int length_array) // сортировка выбором
{
     int counter=0;
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
        {
            if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
            {
                temp = arrayPtr[repeat_counter];
                arrayPtr[repeat_counter] = arrayPtr[element_counter];
                arrayPtr[element_counter] = temp;
                counter++;
                
            }
        }
    }cout <<"\n Counter "<< counter << endl;
}
