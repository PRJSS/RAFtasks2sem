#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int Size = 8;
const int DeltX[8] = {1,2,2,1,-1,-2,-2,-1};
const int DeltY[8] = {2,1,-1,-2,-2,-1,1,2};

void Print(int Matrix[][Size]);
void Horse(int Matrix[][Size],  int num, int i0, int j0);

void main()
{
	setlocale(LC_ALL, "rus");
	int Matrix[Size][Size] = {};
	Horse(Matrix, 1, 0, 0);
}

void Print(int Matrix[][Size])
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			cout << setw(3) << Matrix[i][j];
		}
		cout << endl;
	}
}

void Horse(int Matrix[][Size], int num, int i0, int j0)
{
	Matrix[i0][j0] = num++;
	for (int i = 0; i < 8; i++)
	{
		int inew = i0 + DeltX[i];
		int jnew = j0 + DeltY[i];

		if (num > Size * Size)
		{
			Print(Matrix);
			exit(0);
		}
		if ((inew < 0) || (inew > Size - 1) || (jnew < 0) || (jnew > Size - 1) || Matrix[inew][jnew] != 0)
		{
			continue;
		}

		Horse(Matrix, num, inew, jnew);
		Matrix[inew][jnew] = 0;
	}
}