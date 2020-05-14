//
//  main.cpp
//  6.4
//
//  Created by Danila Bernat on 4/30/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <ctime>


using namespace std;

char arrayOfLatters [8] = {'A','B','C','D','E','F','G','H'};

int numToLetter(short num){
    return arrayOfLatters[num];
    
}

struct info{
    unsigned short schoolNumber : 9;
    unsigned short grade : 4;
    unsigned short letter : 3;
}field;

bool comp1 (info student1, info student2){
    return student1.schoolNumber < student2.schoolNumber;
}
    
bool comp2 (info student1, info student2){
    return student1.grade < student2.grade;
}
    
bool comp3 (info student1, info student2){
    return student1.letter < student2.letter;
}




int main() {
    srand(time(NULL));
    
    int n=20, i=0, rLetter, j,k;
    
    info *schools = new info [n];
    
    cout<<"Генерация:\n";
    
    for (i=0; i<n; i++){
        schools[i].schoolNumber = rand() % 277 + 1;
        schools[i].grade = rand() % 11 + 1;
        
        rLetter = rand() % 8;
        
        schools[i].letter = rLetter;
    }
    
    for (i=0; i<n; i++){
        cout<<schools[i].schoolNumber<<" "<<schools[i].grade<<" "<<(char)numToLetter(schools[i].letter)<<"\n";
    }
    
    cout<<"\n////////////////////\nОдинаковые номера школы:\n";
    //вывод совпадений в номере школе
    sort(schools, schools+n, comp1);
    
    if (schools[0].schoolNumber==schools[1].schoolNumber){cout<<schools[0].schoolNumber<<" "<<schools[0].grade<<" "<<(char)numToLetter(schools[0].letter)<<"\n";}
    if (schools[n-1].schoolNumber==schools[n-2].schoolNumber){cout<<schools[n-1].schoolNumber<<" "<<schools[n-1].grade<<" "<<(char)numToLetter(schools[n-1].letter)<<"\n";}
    
    for (i=1; i<n-1; i++){
        if (schools[i].schoolNumber==schools[i-1].schoolNumber || schools[i].schoolNumber==schools[i+1].schoolNumber)
        {cout<<schools[i].schoolNumber<<" "<<schools[i].grade<<" "<<(char)numToLetter(schools[i].letter)<<"\n";}
    }

    
    cout<<"\n////////////////////\nОдинаковые классы:\n";
      //вывод совпадений в номере школе
      sort(schools, schools+n, comp2);
      
    if (schools[0].grade==schools[1].grade){cout<<schools[0].schoolNumber<<" "<<schools[0].grade<<" "<<(char)numToLetter(schools[0].letter)<<"\n";}
    if (schools[n-1].grade==schools[n-2].grade){cout<<schools[n-1].schoolNumber<<" "<<schools[n-1].grade<<" "<<(char)numToLetter(schools[n-1].letter)<<"\n";}
    
    for (i=1; i<n-1; i++){
        if (schools[i].grade==schools[i-1].grade || schools[i].grade==schools[i+1].grade)
        {cout<<schools[i].schoolNumber<<" "<<schools[i].grade<<" "<<(char)numToLetter(schools[i].letter)<<"\n";}
    }
    
    
    cout<<"\n////////////////////\nОдинаковые буквы:\n";
      //вывод совпадений в номере школе
      sort(schools, schools+n, comp3);
      
    if (schools[0].letter==schools[1].letter){cout<<schools[0].schoolNumber<<" "<<schools[0].grade<<" "<<(char)numToLetter(schools[0].letter)<<"\n";}
    if (schools[n-1].letter==schools[n-2].letter){cout<<schools[n-1].schoolNumber<<" "<<schools[n-1].grade<<" "<<(char)numToLetter(schools[n-1].letter)<<"\n";}
    
    for (i=1; i<n-1; i++){
        if (schools[i].letter==schools[i-1].letter || schools[i].letter==schools[i+1].letter)
        {cout<<schools[i].schoolNumber<<" "<<schools[i].grade<<" "<<(char)numToLetter(schools[i].letter)<<"\n";}
    }
    
}
