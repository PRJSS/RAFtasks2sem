
#include <iostream>
#include "multiplication.h"

using namespace std;

void calculation(double A[], int m, int n){
    double *B = new double [m * m];
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            B[i * m + j] = A[i * m + j];
        }
    }

    double sum;

    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = 0; j < m; j++){
            sum += A[j * m + j];
        }
        cout << sum << ' ';
        multiplication(A, B, m);
    }

    delete []B;
}

void calculation(double **A, int m, int n){
    double **B = new double *[m];
    for (int i = 0; i < m; i++){
        B[i] = new double [m];
    }
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            B[i][j] = A[i][j];
        }
    }

    double sum;

    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = 0; j < m; j++){
            sum += A[j][j];
        }
        cout << sum << ' ';
        multiplication(A, B, m);
    }

    for (int i = 0; i < m; i++){
        delete B[i];
    }
    delete []B;
}


