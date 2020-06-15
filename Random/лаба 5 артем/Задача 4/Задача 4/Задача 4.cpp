#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;


int& search(int [], int );

int main()
{
	const int size = 10;
	srand(time(NULL));
	int array [size];

	cout << " ARRAY \n";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + 1;
		cout<< array[i]<<setw(4);
	}
	cout << endl;

	cout << search(array, size);

	cout << "\n NewArray \n";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << setw(4);
	}
	cout << endl;
	system("pause");
	return 0;
}

int& search(int array[], int size)
{
	int counter = 0;
	int im=0;
	for (int i = 0; i < size; i++)
	{
		for (int j=1;j<sqrt(array[i])+1;j++)
		{
			if (array[i] == j*j) 
			{ 
				if (array[im] < array[i])
				{
					im = i;
					counter++;
				}
			}
		}
	}
	if (counter == 0)
	{
		int k;
		cout << "Enter k: ";
		cin >> k;
		int temp;
		int max = array[0];
		for (int i = 1; i < size; i++)
		{
			if (max < array[i])
			{
				max = array[i];
				temp = i;
			}
		}
		array[temp] = k;
		return max;
	}
	return array[im];
}