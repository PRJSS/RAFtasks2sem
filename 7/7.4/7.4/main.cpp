//
//  main.cpp
//  7.4
//
//  Created by Danila Bernat on 5/20/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int const MAX = 1000;

void add(char c, char top[], int pTop[], int &nz, int &ns){

    int pos = pTop[nz];

    while (pTop[pos] != nz){
        pos = pTop[pos];
    }

    top[ns] = c;
    pTop[pos] = ns;
    ns++;
}

void print(char top[], int pTop[], int &nz){
    int pos = nz;
    if (pTop[nz] == 0) return;
    do{
        cout << top[pos] << ' ';
        pos = pTop[pos];
    }while (pos != 0);
    cout << '\n';
}

void replace(int enterPos, int exitPos, char L[], int pL[], int &ns, char L2[]){
    L[enterPos] =  L2[0];
    pL[enterPos] = ns;
    int k = 1;
    while(L2[k] != '\0'){
        L[ns] = L2[k];
        pL[ns] = ns + 1;
        ns++;
        k++;
    }
    if (pL[enterPos] == ns) pL[enterPos] = exitPos;
    else pL[ns - 1] = exitPos;
}

bool insert(char L[], int pL[], int &nzL, int &nsL, char L1[], char L2[]){
    int pos = nzL;
    int k = 0;
    bool zacep = 0;
    int enterPos;

    do{
        if (L[pos] == L1[k]){
            if (zacep == 0){
                zacep = 1;
                enterPos = pos;
            }
            if (L1[k + 1] != '\0') k++;
            else{
                replace(enterPos, pL[pos], L, pL, nsL, L2);
                return true;
            }
        }else{
            zacep = 0;
            k = 0;
        }
        pos = pL[pos];
    }while(pos != nzL);

    return false;
}

int main()
{
    char slovo[MAX];
    int k;
    char L[2 * MAX];
    int pL[2 * MAX] = {0};
    int nzL = 0;
    int nsL = 0;
    
    cout<<"Print string: ";
    cin >> slovo;
    k = 0;
    while (slovo[k] != '\0'){
        add(slovo[k], L, pL, nzL, nsL);
        k++;
    }

    print(L, pL, nzL);

    char L1[MAX];
    int pL1[MAX];
    cout<<"Print L1: ";
    cin >> L1;

    char L2[MAX];
    int pL2[MAX];
    cout<<"Print L2: ";
    cin >> L2;

    if (insert(L, pL, nzL, nsL, L1, L2)) print(L, pL, nzL);
    else cout << "Error.";

    
    cout << "\n\n";
    return 0;
}
