#include <iostream>
#include "ListStruct.h"



using namespace std;

void Student::enter(){
    
    cin>> snp.surname >> snp.name >> snp.patronymic;
    cin >> birthday.day >> birthday.month >> birthday.year;
    cin >> kurs;
    cin >> mark;
}

void Student::print(){
    cout << snp.surname << ' ' << snp.name << ' ' << snp.patronymic << ' ';
    cout << birthday.day << '.' << birthday.month << '.' << birthday.year << ' ';
    cout << kurs << ' ';
    cout << mark << '\n';
}
