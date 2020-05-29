
#include <iostream>
#include <ostream>
#include <istream>
#include <string>

using namespace std;

class MBNumber {
	int rank;
	bool isNeg;
	int nowSize;
	int* number;
	int const bt = 10;
public:
	MBNumber();

	MBNumber(int n);

	MBNumber(MBNumber &mbn);

	~MBNumber();

	/////////////////////////////////////////////////////////////

private:
	void NewNumberSize(int n);

	void Overflow();

	void Stabilize();

public:
	int GetRank();

	/////////////////////////////////////////////////////////////

	int operator [](const int i);

	//unar\\

	MBNumber operator + ();

	MBNumber operator - ();

	//class & class\\

	MBNumber& operator = (const MBNumber &mbn);

	MBNumber operator + (const MBNumber &mbn);

	MBNumber operator - (const MBNumber &mbn);

	MBNumber operator * (const MBNumber &mbn);

	//prisv\\

	MBNumber& operator >>= (const int n);

	MBNumber& operator <<= (const int n);

	MBNumber& operator +=(const MBNumber &mbn);

	MBNumber& operator -=(const MBNumber &mbn);

	MBNumber& operator *=(const MBNumber &mbn);

	//int & class\\

	friend MBNumber operator + (int n, MBNumber &mbn);

	friend MBNumber operator - (int n, MBNumber &mbn);

	friend MBNumber operator * (int n, MBNumber &mbn);

	//stream\\

	friend istream& operator >> (istream& in, MBNumber &mbn);

	friend ostream& operator << (ostream& out, MBNumber &mbn);
};
