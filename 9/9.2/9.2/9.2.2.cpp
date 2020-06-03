
#include "Student.h"

int main()
{
	list <Student> StList;

	int n; cout << "Enter number of students: "; cin >> n;
	Student st;
	cout << "Enter students:\n";
	
	//Фамилия, Имя, Отчество, День рождения, Месяц рождения, Год рождения, Курс, Оценнка
	for (int i = 0; i < n; i++) {
		st.ReadStudent();
		Add(st, StList);
	}
	cout << "Students:\n";
	for (list<Student>::iterator p = StList.begin(); p != StList.end(); p++)
		p->WriteStudent();
	list<Student> bestStudents = KickLagging(StList);
	cout << "\n==================================\n";
	cout << "Best students:\n";
	for (list<Student>::iterator p = bestStudents.begin(); p != bestStudents.end(); p++)
		p->WriteStudent();
	cout << "Other students:\n";
	for (list<Student>::iterator p = StList.begin(); p != StList.end(); p++)
		p->WriteStudent();
}
