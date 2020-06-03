#include "BiListClass.h"

int main()
{
	int n;
	cout << "Enter N: "; cin >> n;
	n *= 2;
	int* arr = new int[n];
	cout << "Enter elements: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	BiList <int> a(n, arr);
	cout << "List: " << a << "Max summ: " << a.MaxSumm() << '\n';
	return 0;
}
