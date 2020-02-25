#include "Function.h"

int main()
{
	double esp=0.000001;                             //погрешность
	double argument=1, argumentlast=5;           //параметр s
	double argument1=0.5, argumentlast1=2.5;           //параметр t
	double leftborder=3, rightborder=4.254;         //границы поиска корня
	bool flag=true,flag1=true;
	int Number_of_partitions = 1,counter=0; //число разбиений 

	double sum,x,h,In,In2;

	cout << "if you want to change the arguments enter 1 :";
	cin >> flag;
	if (flag)
	{
		cout << "Enter leftborder and rightborder : \n";
		cin >> leftborder >> rightborder;


		cout << "Enter esp :";
		cin >> esp;

		cout << "Enter argument and argumentlast(s): \n";
		cin >> argument >> argumentlast;

		cout << "Enter argument and argumentlast(t): \n";
		cin >> argument1 >> argumentlast1;

		cout << "Enter x :";
		cin >> x;

		cout << setw(30) << " Simpson " << endl;
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << "s |" << setw(14) << "t |" << setw(14) << "I(x) |" << setw(14) << "Counter |" << endl;
		cout << "\n --------------------------------------------------------------------------- \n";

		for (double k=argument;k<=argumentlast;k+=1)
		{
			for (double l=argument1;l<=argumentlast1;l+=0.5)
			{ 
				counter = 0;
				Number_of_partitions = 1;
				In = Simpson(&equation, leftborder, x, rightborder, k, l, esp, Number_of_partitions);  //первое приближение для интеграла
				do {
					counter++;
					In2 = In;     //второе приближение
					Number_of_partitions *= 2;  //увеличение числа шагов в два раза,
								//т.е. уменьшение значения шага в два раза
					In = Simpson(&equation, leftborder, x, rightborder, k, l, esp, Number_of_partitions);;
				} while (abs(In2 - In) > esp);  //сравнение приближений с заданной точность
				cout << k << " |" <<setw(10) << l<<" |" << setw(10) << In2 << " |" << setw(10) << counter << " |" <<endl;
			}
			cout << "\n --------------------------------------------------------------------------- \n";
		}
	}
	else
	{

		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " Simpson " << endl;
		cout << "s |" << setw(14) << "t |" << setw(14) << "I(x) |" << setw(14) << "Counter |" << endl;
		cout << 1 << setw(10) << 0.5 << setw(10) << Simpson(&equation) << setw(10) << 2 << setw(10);
		cout << "\n --------------------------------------------------------------------------- \n";
	}



	system("pause");;
	return 0;
}

