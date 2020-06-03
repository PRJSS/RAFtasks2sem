
#include "Hierarchy.h"
//#include "VectorObject2D.h"
#include "ListObject2D.h"

int main()
{
	//Объект из 10.1
	Star star(4, 2, 5, 6, "red", 5);

	//Конструктор по умолчанию
	ListObject2D l1;
	cout << l1 << '\n';
	//Добавление объектов
	l1.Add(star);
	l1.Add(Star(4, 2, 5.5, 6.2, "green", 5));
	l1.Add(Text(3, 4, 4.5, "TEXT", "black"));
	cout << l1 << '\n';

	//Конструктор копирования
	ListObject2D l2(l1);
	cout << l2 << '\n';
	//Удание объекта первого объекта из списка
	l2.DeleteObject(1);
	cout << l2 << '\n';
	//Удаление всех элементов из списка
	l2.Delete();
	cout << l2 <<  '\n';

	//Оператор копирования
	l2 = l1;
	cout << l2 << '\n';
}
