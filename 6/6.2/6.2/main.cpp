//
//  main.cpp
//  5.2
//
//  Created by Danila Bernat on 3/17/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool checkFile(string file_name) {
   ifstream file;
   file.open(file_name);
   if(!file){
    return false;}
   else{
       return true;
   }
}

int main() {
   
    ofstream fout;
    ifstream fin;
    string pathF ="f.txt";
    string pathG ="g.txt";
    
    if(!checkFile(pathF)){
        cout<<"File not found\n"; exit(1);}
   
    
    float buffer;
    
    vector<float> vec;
    
    fin.open(pathF);
    fout.open(pathG);
    
    while(!fin.eof()){
        fin>>buffer;
        vec.push_back(buffer);
    }
    
    short unsigned size = vec.size();
    
    sort(vec.rbegin(), vec.rend());
    
    int i=size-1;
    
    while (i>-1){
        fout<<vec[i]<<"\n";
        i--;
    }
    
    fin.close();
    fout.close();
}
