#include <iostream>
#include <ctime>
#include "Source.cpp"


using namespace std;

int main()
{
    srand(time(0));
	const int size = 10;
	int Iarray[size];
	char Carray[size];
	double Darray[size];
	float Farray[size];

//	Enter_increase(Carray, size);
//	cout << endl;
//	Enter_decrease(Farray, size);
//	cout << endl;
	Enter_random(Iarray, size);
	cout << endl;
	Enter_random(Darray, size);
	cout<<"\n --------------------------------------------------- \n" << endl;

	BinaryInsertionSort(Iarray, size);
    choicesSort(Iarray, size);
	
    
	for (int i = 1; i < size; i++)
	{
		cout << setw(3) << Iarray[i];
	}
    cout<<"\n\n\n";
}
