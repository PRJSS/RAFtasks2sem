#include <iostream>
#include <time.h>
#include "Source.cpp"


using namespace std;

int main()
{

	const int size = 10;
	int Iarray[size];
	char Carray[size];
	double Darray[size];
	float Farray[size];

	Enter_increase(Iarray, size);
	cout << endl;
	Enter_decrease(Darray, size);
	cout << endl;
	Enter_random(Farray, size);
	cout << endl;
	Enter_random(Carray, size);
	cout<<"\n --------------------------------------------------- \n" << endl;

	Sort_inserts(Darray, size);
	quickSort(Carray, 0, size);
	for (int i = 1; i < size; i++)
	{
		cout << setw(3) << Carray[i];
	}
	return 0;
}