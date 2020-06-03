
#include "Student.h"

void Add(Student &st, list <Student> &l) {
	list<Student>::iterator p = l.begin();
	while (p != l.end()) {
		if (CompareStudents(st, *p)) {
			p = l.insert(p, st);
			return;
		}
		p++;
	}
	l.push_back(st);
}

bool CompareStudents(Student &st1, Student &st2) {
	int k = 0;
	int l1 = strlen(st1.snp.surname);
	int l2 = strlen(st2.snp.surname);
	while (true) {
		if (k == l1)
			return true;
		else if (k == l2)
			return false;
		else if (st1.snp.surname[k] < st2.snp.surname[k])
			return true;
		else if (st1.snp.surname[k] > st2.snp.surname[k])
			return false;
		k++;
	}
	return true;
}

list<Student> KickLagging(list <Student> &l) {
	list<Student> bestStudent;
	double avarageMark = 0;
	int n = 0;
	for (list<Student>::iterator p = l.begin(); p != l.end(); p++) {
		avarageMark += p->mark;
		n++;
	}
	avarageMark /= n;
	for (list<Student>::iterator p = l.begin(); p != l.end();)
		if (p->mark >= avarageMark || fabs(p->mark - avarageMark) < E) {
			bestStudent.push_back(*p);
			p = l.erase(p);
		}
		else
			p++;
	return bestStudent;
}
