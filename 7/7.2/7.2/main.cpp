#include "calculation.h"

using namespace std;

int main()
{
    int m, n;
    cout << "Enter m: "; cin >> m;
    cout << "Enter n: "; cin >> n;

    double *array1 = new double [m * m];
    cout << "1) Enter matrix:\n";
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            cin >> array1[i * m + j];
        }
    }
    calculation(array1, m, n);
    delete []array1;
    cout << "\n----------------------------------\n";


    double **array2 = new double *[m];
    for (int i = 0; i < m; i++){
        array2[i] = new double [m];
    }
    cout << "2) Enter matrix:\n";
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j++){
            cin >> array2[i][j];
        }
    }
    calculation(array2, m, n);


    return 0;
}
