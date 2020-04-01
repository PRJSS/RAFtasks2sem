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

int main() {
   
    ofstream fout;
    ifstream fin;
    string pathF ="/Users/bernat/RAFtasks2sem/6/6.2/6.2/f.txt";
    string pathG ="/Users/bernat/RAFtasks2sem/6/6.2/6.2/g.txt";
    int buffer;
    
    vector<int> vec;
    
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
    
}