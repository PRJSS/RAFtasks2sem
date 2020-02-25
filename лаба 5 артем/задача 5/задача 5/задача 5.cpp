#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

//FOR PART A
double HalfDivisionMethodA(double (*equation)(double), double leftborder = 0, double rightborder = 3, double esp = 0.000001);			//метод половинного деления
double TangentMethodA(double (*equation)(double), double leftborder = 0, double rightborder = 3, double esp = 0.000001);				//метод касательных
double ChordMethodA(double (*equation)(double), double leftborder = 0, double rightborder = 3, double esp = 0.000001);					//метод хорд
double equationA(double x);																//уравнение для которого проводим рассчёты

//FOR PART B
double HalfDivisionMethodB(double (*equation)(double, double), double leftborder = 0, double rightborder = 3, double argument = 0.9, double argumentlast = 1.2, double esp = 0.000001);			//метод половинного деления
double TangentMethodB(double (*equation)(double, double), double leftborder = 0, double rightborder = 3, double argument = 0.9, double argumentlast = 1.2, double esp = 0.000001);				//метод касательных
double ChordMethodB(double (*equation)(double, double), double leftborder = 0, double rightborder = 3, double argument = 0.9, double argumentlast = 1.2, double esp = 0.000001);				//метод хорд
double equationB(double , double);																				//уравнение для которого проводим рассчёты


int main()
{
	double esp;								//погрешность
	double argument,argumentlast;			//параметр
	double leftborder, rightborder;			//границы поиска корня
	bool flag;
	cout << "if you want to change the arguments enter 1 :";
	cin >> flag;

	cout << "PART A" << endl;
	if (flag)
	{
		cout << "Enter leftborder and rightborder : \n";
		cin >> leftborder >> rightborder;


		cout << "Enter esp :";
		cin >> esp;

		cout << "\n --------------------------------------------------------------------------- \n";
		cout <<setw(30)<< " HalfDivisionMethod "<<endl;
		HalfDivisionMethodA(&equationA, leftborder, rightborder, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " ChordMethodA " << endl;
		ChordMethodA(&equationA, leftborder, rightborder, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " TangentMethodA " << endl;
		TangentMethodA(&equationA, leftborder, rightborder, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
	}
	else
	{
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << "\n HalfDivisionMethod \n";
		HalfDivisionMethodA(&equationA);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << "\n ChordMethod \n";
		ChordMethodA(&equationA);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << "\n TangentMethod \n";
		TangentMethodA(&equationA);
		cout << "\n --------------------------------------------------------------------------- \n";
	}

	cout << "\n PART B \n" << endl;
	cout << "if you want to change the arguments enter 1 :";
	cin >> flag;
	if (flag)
	{
		cout << "Enter leftborder and rightborder : \n";
		cin >> leftborder >> rightborder;


		cout << "Enter esp :";
		cin >> esp;

		cout << "Enter argument and argumentlast: \n";
		cin >> argument >> argumentlast;

		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " HalfDivisionMethod " << endl;
		HalfDivisionMethodB(&equationB, leftborder, rightborder, argument, argumentlast, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " ChordMethod " << endl;
		ChordMethodB(&equationB, leftborder, rightborder, argument, argumentlast, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " TangentMethod " << endl;
		TangentMethodB(&equationB, leftborder, rightborder, argument, argumentlast, esp);
	}
	else
	{
		cout << "\n --------------------------------------------------------------------------- \n";
		cout <<setw(30)<< "\n HalfDivisionMethod \n";
		HalfDivisionMethodB(*equationB);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << "\n TangentMethodB \n";
		TangentMethodB(*equationB);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << "\n ChordMethodB \n";
		ChordMethodB(*equationB);
		cout << "\n --------------------------------------------------------------------------- \n";
	}

	

	system("pause");;
	return 0;
}

//for part a
double HalfDivisionMethodA (double (*equation)(double), double leftborder , double rightborder , double esp )
{
	int counter = 0;
	double center = (leftborder + rightborder) / 2; //центр отрезка подставляетDся в функцию

	cout << setw(8) << "X" << setw(16) << "F(x)" << setw(10) << "Counter" << setw(8) <<endl;
	while (abs(equation(center)) > esp && counter < 40)
	{
		counter++;
		cout << setw(8) << center << setw(16) << equation(center) << setw(10) << counter << setw(8) << endl;;
		if (equation(center) * equation(leftborder) < 0)
		{
			rightborder = center;
			center = (rightborder + leftborder) / 2;
		}
		else
		{
			leftborder = center;
			center = (leftborder + rightborder) / 2;
		}
	}
	return center;
}

//for part b
double HalfDivisionMethodB (double (*equation)(double,double), double leftborder, double rightborder , double argument ,double argumentlast ,double esp )
{
	cout <<"S"<< setw(15) << "X" << setw(15) << "F(x)" << setw(15) << "Counter"<< endl;
	for (;argument<=argumentlast;argument+=0.02)
	{
		int counter = 0;
		double leftborder1 = leftborder, rightborder1 = rightborder;
		double center = (leftborder1 + rightborder1) / 2; //центр отрезка подставляется в функцию
		while (equation(center, argument) > esp)
		{
			counter++;
			cout << argument << setw(15) << center << setw(15) << equation(center, argument) << setw(15) << counter<<endl;
			if (equation(center, argument) * equation(leftborder1, argument) < 0)
			{
				rightborder1 = center;
				center = (rightborder1 + leftborder1) / 2;
			}
			else
			{
				leftborder = center;
				center = (leftborder1 + rightborder1) / 2;
			}
		}
		cout << "\n --------------------------------------------------------------------------- \n";
	}
	return 0;
}

//for part a
double TangentMethodA (double (*equation)(double), double leftborder , double rightborder , double esp)
{
	int counter = 0;
	double center = (leftborder + rightborder) / 2;
	cout << setw(8) << "X" << setw(16) << "F(x)" << setw(10) << "Counter" << setw(8) << endl;
	while (abs(equationA(center)) > esp && counter < 40)
	{

		counter++;
		cout<< setw(8) << center << setw(16) << equation(center) << setw(10) << counter<<setw(8)<<endl;
		center = center - (equationA(center) / (2 * (center + 1)));
	}
	return 0;
}

//for part b
double TangentMethodB (double (*equation)(double, double), double leftborder , double rightborder , double argument , double argumentlast ,  double esp )
{
	double center = (leftborder + rightborder) / 2;
	cout << "S" << setw(18) << "X" << setw(18) << "F(x)" << setw(18) << "Counter" << endl;
	for (; argument < argumentlast; argument += 0.02)
	{
		int counter = 0;
		while (abs(equationB(center,argument)) > esp)
		{
			counter++;
			cout << argument << setw(18) << center << setw(18) << equation(center, argument) << setw(18) << counter << endl;
			center = center - (equationB(center, argument) /(2*center-6.28*sin(3.14*center)*cos(3.14*center) ));
		}
		cout << "\n --------------------------------------------------------------------------- \n";
	}
	return 0;
}

//for part a
double ChordMethodA (double (*equation)(double), double leftborder , double rightborder , double esp)
{
	int counter = 0;
	double center =leftborder-(rightborder-leftborder)*(equationA(leftborder))/(equationA(rightborder)-equationA(leftborder));
	cout << setw(8) << "X" << setw(16) << "F(x)" << setw(10) << "Counter" << setw(8) << endl;
	while (abs(equationA(center)) > esp && (abs(leftborder-rightborder)>esp) && counter < 40)
	{
		counter++;
		cout << setw(8) << center << setw(16) << equation(center) << setw(10) << counter << setw(8) << endl;
		if (equation(center) * equation(leftborder) < 0)
		{
			rightborder = center;
			center = leftborder - (rightborder - leftborder) * (equationA(leftborder)) / (equationA(rightborder) - equationA(leftborder));
		}
		else
		{
			leftborder = center;
			center = leftborder - (rightborder - leftborder) * (equationA(leftborder)) / (equationA(rightborder) - equationA(leftborder));
		}
	}
	return 0;
}

//for part b
double ChordMethodB (double (*equation)(double, double), double leftborder , double rightborder , double argument , double argumentlast ,double esp)
{
	cout << "S" << setw(15) << "X" << setw(15) << "F(x)" << setw(15) << "Counter" << endl;
	for (; argument < argumentlast; argument += 0.02)
	{
		int counter = 0;
		double leftborder1 = leftborder, rightborder1 = rightborder;
		double center = (leftborder + rightborder) / 2;
		while (abs(equationB(center,argument)) > esp && (abs(leftborder - rightborder) > esp) && counter < 40)
		{
			counter++;
			cout << argument << setw(18) << center << setw(18) << equation(center, argument) << setw(18) << counter << endl;
			if (equation(center,argument) * equation(leftborder1,argument) < 0)
			{
				rightborder1 = center;
				center = leftborder1 - (rightborder1 - leftborder1) * (equationB(leftborder1,argument)) / (equationB(rightborder1, argument) - equationB(leftborder1, argument));
			}
			else
			{
				leftborder1 = center;
				center = leftborder1 - (rightborder1 - leftborder1) * (equationB(leftborder1, argument)) / (equationB(rightborder1, argument) - equationB(leftborder1, argument));
			}
		}
		cout << "\n --------------------------------------------------------------------------- \n";
	}
	return 0;
}

//for part a
double equationA (double x)
{
	return (x + 1) * (x + 1) - 4;
}

//for part b
double equationB (double x, double argument)
{ 
	return cos(3.14 * x)* cos(3.14 * x)+x*x-1.5*argument;
}