#include "myVector.h"

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

	int arr[] = {1, 3 ,2, 4};
	myVector <bool> a;

	myVector <> b (4, arr);
	myVector <> c (b);

	cout << a;
	a[11] = 1;
	cout << a;
	a.randomElements();
	cout << a;
	cout << b << c;
	cout << "\n==========================================\n";

	myVector <bool> nalichie;
	nalichie.newVectorSize(10001);

	ifstream fin("Chisla.txt");

	myVector <> chisla;
	chisla.newVectorSize(razmer(fin, nalichie));

    zapolnenie(chisla, nalichie);

    cout << chisla;

	system("pause");
	return 0;
}
