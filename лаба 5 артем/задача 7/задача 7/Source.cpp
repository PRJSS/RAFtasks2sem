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
	K pivot; // разрешающий элемент
	K l_hold = left; //левая граница
	K r_hold = right; // правая граница
	pivot = numbers[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}