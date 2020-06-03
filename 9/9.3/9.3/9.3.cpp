
#include "ReversePolishRecord.h"

int main()
{
	string exp;
	getline(cin, exp, '=');
	ReversePolishRecord(exp);
	cout << "Answer: " << exp;
    
    cout<<"\n\n";
	return 0;
}
