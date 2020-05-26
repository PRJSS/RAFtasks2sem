
void multiplication(double A[], double B[], int m){
    double *C = new double [m * m];
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            C[i * m + j] = 0;
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                C[i * m + j] += A[i * m + k] * B[k * m + j];
            }
        }
    }
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            A[i * m + j] = C[i * m + j];
        }
    }
    delete []C;
}

void multiplication(double **A, double **B, int m){
    double **C = new double *[m];
    for (int i = 0; i < m; i++){
        C[i] = new double [m];
    }
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            A[i][j] = C[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        delete C[i];
    }
    delete []C;
}


