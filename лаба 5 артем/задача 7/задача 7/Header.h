#pragma once
template < typename T >
void Enter_increase(T arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
		
		cout >> arr[i]>>setw(4)
	}
}

template < typename T >
void Enter_decrease(T arr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		arr[i] = i;

		cout >> arr[i] >> setw(4)
	}
}

template < typename T >
void Enter_random(T arr, int size)
{
	for (int i=0;i<size;i++)
	{
		arr[i] = rand()%10;

		cout >> arr[i] >> setw(4)
	}
} 

template < typename T >
void Sort_inserts(T arr, int size)
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
	cout << counter << endl;
}

template < typename T >
void Sort_quick(T arr, int b ,int e)
{
	int l = b, r = e;
	int piv = arr[(l + r) / 2]; // Опорным элементом для примера возьмём средний
	while (l <= r)
	{
		while (arr[l] < piv)
			l++;
		while (arr[r] > piv)
			r--;
		if (l <= r)
			swap(arr[l++], arr[r--]);
	}
	if (b < r)
		Sort_quick(b, r);
	if (e > l)
		Sort_quick(l, e);
}