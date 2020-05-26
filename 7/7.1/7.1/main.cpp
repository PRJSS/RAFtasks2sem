//
//  main.cpp
//  7.1
//
//  Created by Danila Bernat on 5/13/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int n = 30;

void addMemory(short *&arr, int &size){ //алгоритм амортизированного выделения памяти
short *arrCopy = new short [size*2] {0};
for (int i=0; i<size; i++){
    arrCopy[i]=arr[i];
}
delete[] arr;
arr = arrCopy;
    size=size*2;
}

bool checkFile(string file_name) {
   ifstream file;
   file.open(file_name);
   if(!file){
    return false;}
   else{
       return true;
   }
}

void generateData(string pathF){
    srand(time(0));
    ofstream fout;
    fout.open(pathF,ios::binary);
    srand(time(NULL));
    
    int progress=0;
    for (int i=0; i<n; i++){
        fout<<1+rand()%10000<<"\n";
        if(i%50000000==0){
            progress=progress+5;
            cout<<progress<<"%\n";
        }
    }
    fout.close();
}


int main() {
    
    ifstream fin;
    string pathF ="data.txt";
    
    if (!checkFile(pathF)){
        cout<<"Файл не найден\nНачат процесс генерации файла с данными:\n";
        generateData(pathF);
        fin.open(pathF);
    }else{
        fin.open(pathF);
        if (fin.eof()){cout<<"Файл пуст.\n"; cout<<"Начат процесс генерации файла с данными:\n";
        generateData(pathF);}
    }
    
    short *array = new short [4] {0};
    int size = 4;
 
    fin>>array[0];
    int i=0, j=1;
    fin>>array[j];
    while(array[j]==array[i]){fin>>array[j];}
    
    int min, pmin;
    
    cout<<"Начало обработки:\n";
    while(!fin.eof()){
        
        while(array[j]>=array[i]){
            while(array[j]==array[i]){
                           fin>>array[j];
                           if(size==j+1){addMemory(array, size);}
                       }
            i++;
            j++;
            fin>>array[j];
            if(size==j+1){addMemory(array, size);}
            
            while(array[j]==array[i]){
                           fin>>array[j];
                           if(size==j+1){addMemory(array, size);}
                       }
            
        }
        if(!fin.eof()){
            i++;
            j++;
            fin>>array[j];
            if (size==j+1){addMemory(array, size);}
        }
        
    }
    
    cout<<"Ответ:\n";
    for (i=0; i<size && array[i]!=0; i++){
        cout<<array[i]<<"\n";
    }
}
//123 1223 111123
