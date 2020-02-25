#include <iomanip>//для setw()
#include "iostream"//для ввода и вывода
#include "fstream"//для открытия файла
#include <conio.h>//для getch

using namespace std;

struct student
{
	char suname[20];			//фамилия студента
	char name[20];				//фамилия студента
	char otch[20];				//фамилия студента
	int course;					//курс
	int  ses[5];				//оценки
};
double sredniy(student*, int n, double* sr);			//прототип функции для нахождения только среднего бала
double sort(student*, int n, double* sr);				// прототип функции сортировки по среднему балу
double individum(student*, int n, double* sr);			// прототип функции вывода студентов у которых бал 4.5 и выше

int main()
{
	setlocale(LC_CTYPE, "Russian");						//русский шрифт в консоле
	const int n = 10;									//константная переменная с количеством студентов
	int  i, j, menu;									//обьявляем переменные
	double sr[10];										//массив со средними балами студентов
	char vib;											// переменная для вывода среднего бала в case 1
	student* stud1 = new student[n];					//выделение динамической памяти под массив структур

	ifstream instr_econ("students_econ.txt");			//открытие файла для ввода
	ifstream instr_fiz("students_fiz.txt");				//открытие файла для ввода
	ifstream instr_him("students_him.txt");				//открытие файла для ввода
	if (!instr_econ || !instr_fiz || !instr_him)		//если файлы не найдены тогда....
	{
		cout << "Files can not be open\n";				//выводим сообщение
		return 0;										//выход из программы
	};
	//Меню
one:cout << "/////////////////////////////////////////////////" << endl << endl;
	cout << "                   МЕНЮ" << endl;
	cout << "\n Выберете предмет для вывода студентов: ";
	cout << "\n\n 1 - Экономика: ";
	cout << "\n 2 - физика ";
	cout << "\n 3 - Химия " << endl << endl << endl;
	cout << "/////////////////////////////////////////////////" << endl;
	menu = _getch();									//функция ввода без Enter
	switch (menu)
	{

	case 49:
		//заполнение массива считыванием из файла students_econ
		cout << endl << "Вывод студентов по предмету Экономика: " << endl << endl;
		cout << endl << "     Студент  \t               Группа\t      Оценки" << endl << endl;
		for (i = 0; i < n; i++)
		{
			instr_econ >> stud1[i].suname >> stud1[i].name >> stud1[i].otch >> stud1[i].course;//получение из файла информации
			cout << stud1[i].suname << " " << stud1[i].name << ' ' << stud1[i].otch << setw(4) << "\t" << stud1[i].course; //отображение на экране
			for (j = 0; j < 5; j++)//цикл по оценкам
			{
				instr_econ >> stud1[i].ses[j];
				cout << setw(4) << "    " << stud1[i].ses[j];
			}
			cout << endl;
		}
		cout << endl;
		cout << "\nВsвести студентов с подсчетом средних баллов?(y/n): ";
		cin >> vib;
		if (vib == 'y')goto go;// Если у(да), то переходи на go:
		instr_econ.close(); break;//закрыли файл instr_econ

	case 50:
		//заполнение массива считыванием из файла students_fiz
		cout << endl << "Вывод студентов по предмету Физика: " << endl << endl;
		cout << endl << "     Студент  \t               Группа\t      Оценки" << endl << endl;
		for (i = 0; i < n; i++)
		{
			instr_fiz >> stud1[i].suname >> stud1[i].name >> stud1[i].otch >> stud1[i].course;
			cout << stud1[i].suname << " " << stud1[i].name << ' ' << stud1[i].otch << setw(4) << "\t" << stud1[i].course;
			for (j = 0; j < 5; j++)
			{
				instr_fiz >> stud1[i].ses[j];
				cout << setw(4) << "    " << stud1[i].ses[j];
			}
			cout << endl;
		}
		cout << endl;
		cout << "Вsвести студентов с подсчетом средних баллов?(y/n): ";
		cin >> vib;
		if (vib == 'y')goto go;
		instr_fiz.close(); break;

	case 51:
		//заполнение массива считыванием из файла students_him
		cout << endl << "Вывод студентов по предмету Химия: " << endl << endl;
		cout << endl << "     Студент  \t               Группа\t      Оценки" << endl << endl;
		for (i = 0; i < n; i++)
		{
			instr_him >> stud1[i].suname >> stud1[i].name >> stud1[i].otch >> stud1[i].course;
			cout << stud1[i].suname << " " << stud1[i].name << ' ' << stud1[i].otch << setw(4) << "\t" << stud1[i].course;
			for (j = 0; j < 5; j++)
			{
				instr_him >> stud1[i].ses[j];
				cout << setw(4) << "    " << stud1[i].ses[j];
			}
			cout << endl;
		}
		cout << endl;
		cout << "Вsвести студентов с подсчетом средних баллов?(y/n): ";
		cin >> vib;
		if (vib == 'y')goto go;
		instr_him.close(); break;

	go:cout << endl << "Вывод студентов по возрастанию среднего балла" << endl;
		cout << endl << "     Студент  \t               Группа\t      Оценки\t        Средний бал" << endl << endl;
		sort(stud1, n, sr); //вызываем функцию сортировки
		cout << endl;

		cout << endl << "Студенты у которых средний бал превышает 4.5" << endl;
		cout << endl << "     Студент  \t               Группа\t      Оценки" << endl;
		sredniy(stud1, n, sr); //вызываем функцию вычмсления среднего бала
		individum(stud1, n, sr); //вызываем функцию для вывода студентов у которых бал 4.5 и выше

		delete[] stud1; //очищаем память
		system("pause >> null"); //ждем пока пользователь нажмет любую клавишу
		return 0; //выход с программы
	default:
		cout << "ОШИБКА! Не корректный ввод!" << endl; goto one; break;
	}
}

//сортировку делаеи спомощью "Пузырьковой сортировки"
double sort(student* gr, int n, double* sr)
{
	double s; //перемееная для подсчета суммы балов каждого студента
	double* avg = new double[n]; //выделяем память под массив хранящщего средние балы каждого студента

	//находим средний бал каждого студента
	for (int i = 0; i < n; i++)
	{
		s = 0.;
		for (int j = 0; j < 5; j++) {
			s += gr[i].ses[j];
			avg[i] = s / 5;
			sr[i] = avg[i];
		}
	}

	bool flag = true; //обьявляем булевую переменную и даем есть значение "истина"
	while (flag) //пока "истина" делаем
	{
		flag = false;  //устанавливаем переменную в "ложь
		for (int i = 0; i < n - 1; ++i)
		{
			if (avg[i] > avg[i + 1]) //если элемент массива большн следующий элемент, тогда
			{
				//меняем массивы в структуре местами
				student x = gr[i];
				gr[i] = gr[i + 1];
				gr[i + 1] = x;
				//а также меняем местами и элементы в массиве средних оценок 
				double temp = avg[i];
				avg[i] = avg[i + 1];
				avg[i + 1] = temp;
				flag = true;
			} //уснанавлюем в "истина"
		}
	}

	//выводим на экран отсортированную структуру
	for (int i = 0; i < n; i++)
	{
		cout << gr[i].suname << " " << gr[i].name << ' ' << gr[i].otch << setw(4) << "\t" << gr[i].course;
		for (int j = 0; j < 5; j++)
		{
			cout << "    " << gr[i].ses[j];
		}
		cout << "        " << avg[i]; //выводим на экран средний бал
		cout << endl;
	}
	delete[] avg; //освобождаем память
	return 0;
}
//Находим только средний бал
double sredniy(student* gr, int n, double* sr)
{
	double s; //перемееная для подсчета суммы балов каждого студента
	double* avg = new double[n]; //выделяем память под массив хранящщего средние балы каждого студента

	//находим средний бал каждого студента
	for (int i = 0; i < n; i++)
	{
		s = 0.;
		for (int j = 0; j < 5; j++) {
			s += gr[i].ses[j];
			avg[i] = s / 5;
			sr[i] = avg[i];
		}
	}

	delete[] avg; //освобождаем память
	return 0;
}
//ищем студентов с балом 4.5 и выше
double individum(student* gr, int n, double* sr)
{
	int  z = 0; //объявляем переменyю
	for (int i = 0; i < n; i++)
	{
		if (sr[i] > 4.5) { //если бал 4.5 и выше тогда...
			cout << "\n" << gr[i].suname << " " << gr[i].name << ' ' << gr[i].otch << setw(4) << "\t" << gr[i].course;//выводи этих студентов
			for (int j = 0; j < 5; j++)
				cout << setw(4) << " " << gr[i].ses[j];
			z++;
		}//подсчитываем количество студентов с балом 4.5 и выше
	}
	if (z == 0) //если  нет, тогда ....
	{
		cout << endl << "По данному предмету нет студентов с баллом выше 4.5" << endl; //выводим сообщение об этом
	}
	return 0;
}