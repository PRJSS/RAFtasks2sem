#include <iostream>
#include <iomanip>

using namespace std;

double LeftRectangle	(double (*equation)(double, double),
						 double leftborder = 0,
						 double rightborder = 3,
						 double argument = 0.9,
						 double argumentlast = 1.2,
						 double esp = 0.000001);         //метод левых прямоугольников
double RightRectangle	(double (*equation)(double, double),
						 double leftborder = 0,
						 double rightborder = 3,
						 double argument = 0.9,
						 double argumentlast = 1.2,
						 double esp = 0.000001);        //метод правых прямоугольников
double MidRectangle		(double (*equation)(double, double),
						 double leftborder = 0,
						 double rightborder = 3,
						 double argument = 0.9,
						 double argumentlast = 1.2,
						 double esp = 0.000001);          //метод средних прямоугольников
double Trapeze			(double (*equation)(double, double),
						 double leftborder = 0,
						 double rightborder = 3,
						 double argument = 0.9,
						 double argumentlast = 1.2,
						 double esp = 0.000001);               //метод трапеции
double Simpson			(double (*equation)(double, double),
						 double leftborder = 0,
						 double rightborder = 3,
						 double argument = 0.9,
						 double argumentlast = 1.2,
						 double esp = 0.000001);               //метод Симпсона
double equation(double, double);                         //уравнение для которого проводим рассчёты

int main()
{
	double esp;                             //погрешность
	double argument, argumentlast;           //параметр
	double leftborder, rightborder;         //границы поиска корня
	bool flag;

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
		cout << setw(30) << " LeftRectangle " << endl;
		LeftRectangle(&equation, leftborder, rightborder, argument, argumentlast, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " RightRectangle " << endl;
		RightRectangle(&equation, leftborder, rightborder, argument, argumentlast, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " MidRectandle " << endl;
		MidRectangle(&equation, leftborder, rightborder, argument, argumentlast, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " Trapeze " << endl;
		Trapeze(&equation, leftborder, rightborder, argument, argumentlast, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " Simpson " << endl;
		Simpson(&equation, leftborder, rightborder, argument, argumentlast, esp);
		cout << "\n --------------------------------------------------------------------------- \n";
	}
	else
	{
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " LeftRectangle " << endl;
		LeftRectangle(&equation);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " RightRectangle " << endl;
		RightRectangle(&equation);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " MidRectandle " << endl;
		MidRectangle(&equation);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " Trapeze " << endl;
		Trapeze(&equation);
		cout << "\n --------------------------------------------------------------------------- \n";
		cout << setw(30) << " Simpson " << endl;
		Simpson(&equation);
		cout << "\n --------------------------------------------------------------------------- \n";
	}



	system("pause");;
	return 0;
}
double HalfDivisionMethodB(double (*equation)(double, double), double leftborder = 0, double rightborder = 3, double argument = 0.9, double argumentlast = 1.2, double esp = 0.000001)
{
	cout << "S" << setw(15) << "X" << setw(15) << "F(x)" << setw(15) << "Counter" << endl;
	for (; argument <= argumentlast; argument += 0.02)
	{
		int counter = 0;
		double leftborder1 = leftborder, rightborder1 = rightborder;
		double center = (leftborder1 + rightborder1) / 2; //центр отрезка подставляется в функцию
		while (equation(center, argument) > esp)
		{
			counter++;
			cout << argument << setw(15) << center << setw(15) << equation(center, argument) << setw(15) << counter << endl;
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
