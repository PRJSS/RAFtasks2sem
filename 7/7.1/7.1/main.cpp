//
//  main.cpp
//  7.1
//
//  Created by Danila Bernat on 5/13/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

int const MAX = 10000;

void createFile(ofstream &outfile){
    int v;
    for (int i = 0; i < 2000000000; i++){
        v = rand() % 9999 +  1;
        outfile << v << ' ';
    }
}

int razmer(ifstream &infile, bool a[]){
    int v;
    int k = 0;
    infile >> v;
    while (!infile.eof()){
        if (a[v] == 0){
            k++;
            a[v] = 1;
        }
        infile >> v;
    }
    return k;
}

void zapolnenie(int otvet[], bool a[]){
    int k = 0;
    for (int i = 1; i <= MAX; i++){
        if (a[i] == 1){
            otvet[k] = i;
            k++;
        }
    }
}

int main()
{
    srand(time(NULL));
    //ofstream fout("Chisla.txt");
    //createFile(fout);
    //fout.close();

    bool a[MAX + 1] = {0};

    ifstream fin("Chisla.txt");
    if (!fin){
        cout << "Err1";
        return 1;
    }

    int k = razmer(fin, a);
    cout << k << ' ';

    int *otvet = new  int [k];

    zapolnenie(otvet, a);

    for (int i = 0; i < k; i++){
        cout << otvet[i] << ' ';
    }

    return 0;
}
