#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
const int Size = 10;
template <typename T>
void compare(T array,int  Rightborder, int Leftborder)
{
	if (array[Rightborder] < array[Leftborder])
		swap(array[Rightborder], array[Leftborder]);
	return;
}
template <typename T>
void merge(T* array, int Leftborder, int Rightborder)
{
	if (Rightborder == Leftborder)
		return;
	if (Rightborder - Leftborder == 1)
	{
		compare(array, Rightborder, Leftborder);
	}
	int center = (Rightborder + Leftborder) / 2;
	merge(array,Leftborder, center);
	merge(array,center + 1, Rightborder);
	int buf[Size];
	int xl = Leftborder;
	int xr = center + 1;
	int cur = 0;
	while (Rightborder - Leftborder + 1 != cur)
	{
		if (xl > center)
			buf[cur++] = array[xr++];
		else if (xr > Rightborder)
			buf[cur++] = array[xl++];
		else if (array[xl] > array[xr])
			buf[cur++] = array[xr++];
		else buf[cur++] = array[xl++];

	}
	for (int i = 0; i < cur; i++)
	{
		array[i + Leftborder] = buf[i];
	}
}

template <typename T>
void Enter(T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = static_cast<T>((rand() % 30) + 47);
	}
}

template <typename T>
void output(T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout <<setw(3) <<array[i];
	}
}

