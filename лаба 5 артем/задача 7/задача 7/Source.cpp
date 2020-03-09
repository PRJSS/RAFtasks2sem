#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

template < typename T >
void Enter_increase(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = static_cast<T>(i);

		cout << setw(4) << arr[i] ;
	}
}

template < typename T >
void Enter_decrease(T* arr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		arr[i] = static_cast<T>(i);

		cout << setw(4) << arr[i] ;
	}

}

template < typename T >
void Enter_random(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = rand() % 10;
		arr[i] = static_cast<T>(k+50);

		cout << setw(4) << arr[i] ;
	}
}

template < typename T >
void Sort_inserts(T* arr, int size)
{
	int counter = 0;
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			counter++;
			T tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout <<setw(2)<< arr[i];
	}
	cout <<"\n Counter "<< counter << endl;
}

template < typename T,typename K >
void quickSort(T*numbers, K left, K right)

{
	K pivot;
	K l_hold = left;
	K r_hold = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
