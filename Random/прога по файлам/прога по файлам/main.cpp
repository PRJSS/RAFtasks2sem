//
//  main.cpp
//  прога по файлам
//
//  Created by Danila Bernat on 3/18/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//



/*
 В файле записано число n, а затем n строк.
 Прочитать их в массив строк типа std::string,
 выбрать случайную и записать в другой файл.
 */


#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    
    srand(time(0));
    
    int n;
    
    ofstream fout;
    ifstream fin;
    string pathF ="/Users/bernat/RAFtasks2sem/Random/прога по файлам/прога по файлам/f.txt";
    string buffer;
    
    fin.open(pathF);
    fin>>n;  //чтение кол-ва строк
    
    string *arr = new string[n] ;
    
    
    for (int i = 0; i<n; i++) {  //запись строк в массив
        buffer="";
        fin>>buffer;
        arr[i]=buffer;
    }
    
    cout<<"Ответ "<<arr[(rand()%n)]; //вывод рандомной строки
    
    
    
    fout.close();
    
    cout<<"\n\n\n\n";
    
}
