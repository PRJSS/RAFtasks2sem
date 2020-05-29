#include "MBNumberClass.h"

MBNumber factorial(int);

int main()
{
	MBNumber fact;
	fact = factorial(100);
	cout <<"100! = "<<fact << "\n\n";
	return 0;
}

MBNumber factorial(int n) {
	MBNumber z(1);
	for (int i = 1; i < n; i++)
		z *= i;
	return z;
}
