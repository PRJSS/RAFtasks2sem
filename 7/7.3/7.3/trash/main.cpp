////
////  main.cpp
////  7.3
////
////  Created by Danila Bernat on 5/16/20.
////  Copyright © 2020 Danila Bernat. All rights reserved.
////
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <stdlib.h>
//#include <list>
//using namespace std;
//
//struct info {
//
//    string name;
//    int age;
//    int year;
//    string gender;
//    double mark;
//
//};
//
//
//int main() {
//
//
//    int i=0, n=30;
//
//    info students[n];
//
//    ifstream fin;
//    string pathF ="students.txt", name;
//    fin.open(pathF);
//
//    while(!fin.eof())
//    {
//        fin >> name;
//        students[i].name = students[i].name + name;
//        fin >> name;
//        students[i].name = students[i].name + " " + name;
//        fin >> name;
//        students[i].name = students[i].name + " " + name;
//
//        fin >> students[i].age;
//
//        fin >> students[i].gender;
//
//        fin >> students[i].year;
//
//        fin >> students[i].mark;
//
//        i++;
//    }
//    fin.close();
//
//
//    double averageMark=0;
//
//    for (i=0; i<n; i++){
//        averageMark = averageMark + students[i].mark;
//    }
//    averageMark = averageMark / n;
//
//    for (i=0; i<n; i++){
//        if (students[i].mark>averageMark){
//            cout<<students[i].name<<" "<<students[i].age<<" "<<students[i].gender<<" "<<students[i].year<<" "<<students[i].mark<<" "<<"\n";
//        }
//    }
//
//}
