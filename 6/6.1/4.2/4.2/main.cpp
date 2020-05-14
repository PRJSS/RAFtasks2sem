#include <iostream>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int numToDec(int p, int q, char c[1000], int length){
    int dec;
    int n = 1;
    for (int i = length - 1; i >= 0 ; i--){
        if ('0' <= c[i] && c[i] <= '9')
            dec += int(c[i] - '0') * n;
        else
            dec += (10 + int(c[i] - 'a')) * n;
        n *= p;
    }
    return dec;
}

void magic(int p, int q, char c[1000]){
    
    int length = strlen(c);
    int dec = numToDec(p, q, c, length);
    

    int n = 0;
    int ost;
    char otvet[1000] = "";

    do{
        ost = dec % q;
        if (ost < 10)
            otvet[n] = char('0' + ost);
        else
            otvet[n] = char('a' + ost - 10);
        n++;
        dec /= q;
    }while(dec);

    
    length = strlen(otvet);

    cout << "Chislo v ss #2: ";
    for (int i = length - 1; i >= 0; i--){
        cout << otvet[i];
    }
    cout<<"\n";
}


int main()
{
    int p, q;
    cout << "SS #1: "; cin >> p;
    cout << "SS #2: "; cin >> q;

    char c[1000], *ch;
    cout << "Chislo v ss #1: "; cin >> c;

    magic(p, q, c);
    

    return 0;
}
