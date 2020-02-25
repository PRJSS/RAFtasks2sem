#include "Header.h"

using namespace std;

int main()
{
	srand(time(0));
	const int Size = 6;
	char CstringArray[Size][Size] = {"\0"};
	Enter(CstringArray, Size);
	output(CstringArray, Size);
	merge(CstringArray, 0, Size);
	cout << endl;
	output(CstringArray, Size);

	return 0;
}