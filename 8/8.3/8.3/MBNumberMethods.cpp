#include "MBNumberClass.h"

MBNumber::MBNumber() : rank(1), nowSize(16), number(new int[nowSize]), isNeg(false) {
	for (int i = 0; i < nowSize; i++)
		number[i] = 0;
}

MBNumber::MBNumber(int n) {
	rank = 1;
	nowSize = 16;
	number = new int[nowSize];
	for (int i = 0; i < nowSize; i++)
		number[i] = 0;
	if (n < 0) {
		isNeg = true;
		n *= -1;
	}
	else
		isNeg = false;
	number[0] = n;
	Stabilize();
}

MBNumber::MBNumber(MBNumber &mbn) {
	rank = 1;
	nowSize = 16;
	number = new int[nowSize];
	*this = mbn;
}

MBNumber::~MBNumber() {
	delete[]number;
}

void MBNumber::NewNumberSize(int n) {
	int* nArr = new int[n];
	for (int i = 0; i < n; i++) {
		if (i < nowSize)
			nArr[i] = number[i];
		else
			nArr[i] = 0;
	}
	nowSize = n;
	delete[]number;
	number = nArr;
}

void MBNumber::Overflow() {
	while (rank >= nowSize) {
		NewNumberSize(nowSize * 2);
	}
}

void MBNumber::Stabilize() {
	int ost = 0;
	for (int i = 0; i < rank; i++) {
		number[i] += ost;
		if (number[i] < 0) {
			number[i] += 10;
			number[i + 1]--;
		}
		ost = number[i] / bt;
		number[i] %= 10;
		if (i == rank - 1 && ost != 0)
			rank++;
		Overflow();
	}

	while (rank != 1 && number[rank - 1] == 0)
		rank--;

	if (rank == 1 && number[0] == 0)
		isNeg = false;
}

int MBNumber::GetRank() {
	return rank;
}

int MBNumber::operator [](const int i) {
	if (i < 1)
		return number[0];
	while (i >= nowSize)
		NewNumberSize(nowSize * 2);
	return number[i - 1];
}

MBNumber MBNumber::operator + () {
	return *this;
}

MBNumber MBNumber::operator - () {
	MBNumber mbn(*this);
	if (isNeg)
		mbn.isNeg = false;
	else
		mbn.isNeg = true;
	return mbn;
}

MBNumber& MBNumber::operator = (const MBNumber &mbn) {
	if (this == &mbn) {
		return *this;
	}
	rank = mbn.rank;
	isNeg = mbn.isNeg;
	NewNumberSize(mbn.nowSize);
	for (int i = 0; i < nowSize; i++) {
		number[i] = mbn.number[i];
	}
	return *this;
}

MBNumber MBNumber::operator + (const MBNumber &mbn) {
	MBNumber z(*this);

	if (z.isNeg != mbn.isNeg) {
		MBNumber y;
		y = mbn;
		y = -y;
		z = z - y;
		return z;
	}

	if (mbn.rank > z.rank)
		z.rank = mbn.rank;
	z.Overflow();
	for (int i = 0; i < mbn.rank; i++)
		z.number[i] += mbn.number[i];
	z.Stabilize();
	return z;
}

MBNumber MBNumber::operator - (const MBNumber &mbn) {
	MBNumber z(*this);

	if (z.isNeg != mbn.isNeg) {
		MBNumber y;
		y = mbn;
		y = -y;
		z = z + y;
		return z;
	}

	if (z.rank < mbn.rank) {
		MBNumber y;
		y = mbn;
		z = y - z;
		z = -z;
		return z;
	}
	else if (z.rank == mbn.rank) {
		bool is_more = false;
		for (int i = z.rank - 1; i >= 0; i--) {
			if (z.number[i] > mbn.number[i]) {
				is_more = true;
				break;
			}
			else if (z.number[i] < mbn.number[i]) {
				MBNumber y;
				y = mbn;
				z = y - z;
				z = -z;
				return z;
			}
		}
		if (!is_more) {
			z = 0;
			z.isNeg = false;
			return z;
		}
	}

	for (int i = 0; i < mbn.rank; i++)
		z.number[i] -= mbn.number[i];
	z.Stabilize();
	return z;
}

MBNumber MBNumber::operator * (const MBNumber &mbn) {
	MBNumber res;

	bool is_changed = false;
	if (isNeg) {
		isNeg = false;
		is_changed = true;
	}

	MBNumber z;
	int mult;
	for (int i = 0; i < mbn.rank; i++) {
		mult = mbn.number[i];
		z = *this;
		for (int j = 0; j < z.rank; j++) {
			z.number[j] *= mult;
		}
		z.Stabilize();
		z >>= i;
		res = res + z;
	}

	if (is_changed)
		isNeg = true;
	if (isNeg != mbn.isNeg)
		res.isNeg = true;

	return res;
}

MBNumber& MBNumber::operator >>= (const int n) {
	if (!n)
		return *this;
	rank += n;
	Overflow();
	for (int i = rank - 1; i >= n; i--)
		number[i] = number[i - n];
	for (int i = 0; i < n; i++)
		number[i] = 0;
	return *this;
}

MBNumber& MBNumber::operator <<= (const int n) {
	rank -= n;
	if (rank <= 0)
		*this = 0;
	for (int i = 0; i < rank; i++) {
		number[i] = number[i + n];
		number[i + n] = 0;
	}
	return *this;
}

MBNumber& MBNumber::operator += (const MBNumber &mbn) {
	*this = *this + mbn;
	return *this;
}

MBNumber& MBNumber::operator -= (const MBNumber &mbn) {
	*this = *this - mbn;
	return *this;
}

MBNumber& MBNumber::operator *= (const MBNumber &mbn) {
	*this = *this * mbn;
	return *this;
}

MBNumber operator + (int n, MBNumber &mbn) {
	MBNumber z;
	z = mbn + n;
	return z;
}

MBNumber operator - (int n, MBNumber &mbn) {
	MBNumber z;
	z = mbn - n;
	return z;
}

MBNumber operator * (int n, MBNumber &mbn) {
	MBNumber z;
	z = mbn * n;
	return z;
}

istream& operator >> (istream& in, MBNumber &mbn) {
	mbn.rank = 0;
	mbn.isNeg = false;

	char c;
	in.get(c);
	while (!('0' <= c && c <= '9')) {
		if (c == '-') {
			in.get(c);
			if ('0' <= c && c <= '9') {
				mbn.isNeg = true;
				break;
			}
		}
		else
			in.get(c);
	}

	string s = "";
	while ('0' <= c && c <= '9') {
		s += c;
		in.get(c);
	}

	for (int i = 0; i < mbn.nowSize; i++)
		mbn.number[i] = 0;
	int l = s.size();
	int k0 = 0;
	for (int i = 0; i < l; i++) {
		mbn.rank++;
		mbn.Overflow();
		mbn.number[i] = s[l - 1 - i] - '0';
		if (s[l - 1 - i] == '0')
			k0++;
		else
			k0 = 0;
	}
	if (mbn.rank == 1 && mbn.number[0] == 0)
		mbn.isNeg = false;
	else
		mbn.rank -= k0;

	return in;
}

ostream& operator << (ostream& out, MBNumber &mbn) {
	if (mbn.isNeg)
		out << '-';
	for (int i = 0; i < mbn.rank; i++) {
		out << mbn[mbn.rank - i];
	}
	return out;
}
