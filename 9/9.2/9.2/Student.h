#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using namespace std;

struct Student
{
	struct SNP {
		char surname[80];
		char name[80];
		char patronymic[80];
	} snp;
	struct  Date
	{
		int day;
		int month;
		int year;
	} birth;
	int grade;
	double mark;

	void ReadStudent() {
		cin >> snp.surname >> snp.name >> snp.patronymic;
		cin >> birth.day >> birth.month >> birth.year;
		cin >> grade;
		cin >> mark;
	}

	void WriteStudent() {
		cout << snp.surname << ' ' << snp.name << ' ' << snp.patronymic << ' ';
		cout << birth.day << '.' << birth.month << '.' << birth.year << ' ';
		cout << grade << ' ';
		cout << mark << '\n';
	}
};

void Add(Student &st, list <Student> &l);

bool CompareStudents(Student &st1, Student &st2);

const double E = 0.000001;
list<Student> KickLagging(list <Student> &l);