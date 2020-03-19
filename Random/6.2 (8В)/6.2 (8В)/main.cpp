//
//  main.cpp
//  6.2 (8В)
//
//  Created by Danila Bernat on 3/20/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void addMemory(double *&arr, int size){ //алгоритм амортизированного выделения памяти
    
    double *arrCopy = new double [size*2];
    
    for (int i=0; i<size; i++){
        arrCopy[i]=arr[i];
    }
    delete[] arr;
    arr = arrCopy;
}

int main() {
   
    ofstream ansOut;
    ifstream gin;
    ifstream fin;
    string pathF ="/Users/bernat/RAFtasks2sem/Random/6.2 (8В)/6.2 (8В)/f.txt";
    string pathG ="/Users/bernat/RAFtasks2sem/Random/6.2 (8В)/6.2 (8В)/g.txt";
    string pathAnswer ="/Users/bernat/RAFtasks2sem/Random/6.2 (8В)/6.2 (8В)/answer.txt";
    
    fin.open(pathF);
    gin.open(pathG);
    ansOut.open(pathAnswer);
    
    int f1, f2, g1, g2;
    
    fin>>f2; fin>>f1;
    gin>>g2; gin>>g1;
    
    if (f2!=f1 && f2!=g1  && f2!=g2) ansOut<<f2<<"\n";
    if (g2!=f1 && g2!=g1  && g2!=f2) ansOut<<g2<<"\n";
    //проверяем переменные 2
    
    
    
    while (!fin.eof() || !gin.eof())
    {
        while (f1==f2) {f2=f1; fin>>f1;}//проверка на повторы
        while (g1==g2) {g2=f1; gin>>g1;}//проверка на повторы
        //при проверке на повторы в переменной 2 хранится повторяющееся число
        
        if (f1>g1){
            f2=f1; fin>>f1;
            
        }
        
        
    }
    
}
