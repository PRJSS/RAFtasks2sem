#include "Source.cpp"

using namespace std;


int main() {
	const int Size = 10;
	int Iarray[Size];
	float Farray[Size];
	double Darray[Size];
	char Carray[Size];
	char CstringArray[Size][Size];
	Enter(Carray, Size);
	output(Carray, Size);
	cout << endl;
	merge(Carray, 0, Size - 1);
	output(Carray, Size);

	return 0;
}