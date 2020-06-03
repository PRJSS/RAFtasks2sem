
#include "myVector.h"
#include "Matrix.h"
#include <string>

int main()
{
	Matrix<> m1(2, 2);
	cin >> m1;
	cout << m1;
	int n; cout << "Enter n: "; cin >> n;
	cout << "Answer:\n"; m1.TheWay(n);

	cout << "\n============================\n\n";
	int k;
	cout << "M1[9][0] -- ";
	k = m1[9][0];
	cout << k;

	cout << "\n============================\n\n";
	Matrix<> m2(3, 2);
	Matrix<> m3(2, 3);
	cin >> m2; 
	cin >> m3; 
	cout << m2;
	cout << m3;

	cout << "\n============================\n\n";
	cout << "Size changes:\n";
	m2.SetRowsNumder(4);
	cout << m2 << '\n';
	m2.SetColumnsNumber(3);
	cout << m2 << '\n';
	m2.SetRowsNumder(3);
	m2.SetColumnsNumber(2);
	cout << m2 << '\n';

	cout << "\n============================\n\n";
	cout << "Matrix & int:\n";
	cout << "M2 + 3 = " << m2 + 3 << '\n';
	cout << "M2 - 3 = " << m2 - 3 << '\n';
	cout << "M2 * 3 = " << m2 * 3 << '\n';
	cout << "M2 / 3 = " << m2 / 3 << '\n';

	cout << "\n============================\n\n";
	cout << "int & Matrix:\n";
	cout << "3 + M3 = " << 3 + m3 << '\n';
	cout << "3 - M3 = " << 3 - m3 << '\n';
	cout << "3 * M3 = " << 3 * m3 << '\n';
	cout << "3 / M3 = " << 3 / m3 << '\n';

	cout << "\n============================\n\n";
	cout << "Transpose:\n";
	cout << m2 << '\n';
	m2.Transpose();
	cout << m2 << '\n';
	m2.Transpose();
	cout << m2 << '\n';

	cout << "\n============================\n\n";
	cout << "Matrix & Matrix:\n";
	m3.Transpose();
	cout << "M2 + M3^T = " << m2 + m3 << '\n';
	cout << "M2 - M3^T = " << m2 - m3 << '\n';
	m3.Transpose();
	cout << "M2 * M3 = " << m2 * m3 << '\n';
	cout << "M3 * M2 = " << m3 * m2 << '\n';

	cout << "\n============================\n\n";
	cout << "Boolian:\n";
	cout << "M2 == M3 -- " << (m2 == m3) << '\n';
	cout << "M2 != M3 -- " << (m2 != m3) << '\n';

	cout << "\n============================\n\n";
	cout << "Exponentiation:\n";
	cout << "M1 ^ 1 = " << (m1 ^ 1) << '\n';
	cout << "M1 ^ 2 = " << (m1 ^ 2) << '\n';
	cout << "M1 ^ 3 = " << (m1 ^ 3) << '\n';
	cout << "M1 ^ 4 = " << (m1 ^ 4) << '\n';
}
