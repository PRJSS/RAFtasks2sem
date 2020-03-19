//
//  main.cpp
//  6.2 (6В)
//
//  Created by Danila Bernat on 3/18/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


void addMemory(int *&arr, int size){ //алгоритм амортизированного выделения памяти
    
    int *arrCopy = new int [size*2];
    
    for (int i=0; i<size; i++){
        arrCopy[i]=arr[i];
    }
    delete[] arr;
    arr = arrCopy;
    
    
}

int main() {
   
    ofstream fout;
    ifstream fin;
    string pathF ="/Users/bernat/RAFtasks2sem/Random/6.2 (6В)/6.2 (6В)/f.txt";
    string pathG ="/Users/bernat/RAFtasks2sem/Random/6.2 (6В)/6.2 (6В)/g.txt";
    
    int buffer, i=0, size=1, j;
    int *arr = new int [1];
    
    fin.open(pathF);
    fout.open(pathG);
    
    while(!fin.eof()){
        fin>>buffer;
        arr[i]=buffer;
        i++;
        
        if (i==size){
            addMemory(arr, size);
            size=size*2;
        }
    }
    
    size=i;
    i=0; j=0;
    
    while(i<size-1 && j<size-1){
        for (int k=0; k<2; k++){
            while (arr[i]<=0) i++;
            fout<<arr[i]<<"\n";
            //cout<<arr[i]<<"\n";
            i++;
        }
        
        for (int k=0; k<2; k++){
            while (arr[j]>=0) j++;
            fout<<arr[j]<<"\n";
            //cout<<arr[j]<<"\n";
            j++;
        }
    }
    fout.close();
}
