#include "Function.h"

int main()
{
//	double esp=0.000001;                             //погрешность
//	double argument=1, argumentlast=5;           //параметр s
//	double argument1=0.5, argumentlast1=2.5;           //параметр t
//	double leftborder=3, rightborder=4.254;         //границы поиска корня
//    bool flag=true;
//	int Number_of_partitions = 1,counter=0; //число разбиений
//
//	double x,In,In2;

	

		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " Simpson " << endl;
		cout << "s |" << setw(14) << "t |" << setw(14) << "I(x) |" << setw(14) << "Counter |" << endl;
		cout << 1 << setw(10) << 0.5 << setw(10) << Simpson(&equation) << setw(10) << 2 << setw(10);
		cout << "\n --------------------------------------------------------------------------- \n";
	
}

