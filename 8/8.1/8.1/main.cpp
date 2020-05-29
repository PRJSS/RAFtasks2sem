#include "myVector.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int razmer(ifstream &infile, myVector <bool> &a){
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

void zapolnenie(myVector <int> &otvet, myVector <bool> &a){
    int k = 0;
    for (int i = 1; i <= 10000; i++){
        if (a[i] == 1){
            otvet[k] = i;
            k++;
        }
    }
}

int main(){
    srand(time(NULL));


	myVector <bool> nalichie;
	nalichie.newVectorSize(10001);

	ifstream fin("Chisla.txt");

	myVector <> chisla;
	chisla.newVectorSize(razmer(fin, nalichie));

    zapolnenie(chisla, nalichie);

    cout << chisla;

	
	return 0;
}
