
#include "myVector.h"

string ToString(int n) {
	string s = "";
	if (n == 0)
		s += '0';
	while (n) {
		s = char(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}

template<class U = int>
class Matrix {
	myVector<U>* matrix;
	int rows;
	int columns;
	static int obj_number;
	string name;
public:
	Matrix();

	Matrix(const int r, const int c);

	Matrix(const Matrix &m);

	~Matrix();

	/////////////////////

	void Print(ostream &out = cout) const {
		out << name << ":\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++)
				out << matrix[i][j] << ' ';
			out << '\n';
		}
	}

	void SetRowsNumder(const int r);

	void SetColumnsNumber(const int  c);

	void Transpose();

	bool IsSquare();

	bool IsDiagonal();

	bool IsZero();

	bool IsSingle();

	bool IsSymmetrical();

	bool IsUpperTriangular();

	bool IsLowerTriangular();

	void TheWay(int n, ostream& out = cout);

	////////////////////

	myVector<U>& operator [] (int i);

	//matrix & matrix

	Matrix<U>& operator = (const Matrix<U> &m);

	Matrix<U>& operator += (const Matrix<U> &m);

	Matrix<U>& operator -= (const Matrix<U> &m);

	Matrix<U>& operator *= (const Matrix<U> &m);

	Matrix<U> operator + (const Matrix<U> &m);

	Matrix<U> operator - (const Matrix<U> &m);

	Matrix<U> operator * (const Matrix<U> &m);

	//matrix & U

	Matrix<U>& operator += (const U &n);

	Matrix<U>& operator -= (const U &n);

	Matrix<U>& operator *= (const U &n);

	Matrix<U>& operator /= (const U &n);

	Matrix<U>& operator ^= (const unsigned int &n);

	Matrix<U> operator + (const U &n);

	Matrix<U> operator - (const U &n);

	Matrix<U> operator * (const U &n);

	Matrix<U> operator / (const U &n);

	Matrix<U> operator ^ (const unsigned int &n);

	//U & matrix

	friend Matrix<U> operator + (const U n, const Matrix<U> &m) {
		Matrix<U> nm(m.rows, m.columns);
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.columns; j++)
				nm[i][j] = n + m.matrix[i][j];
		return nm;
	}

	friend Matrix<U> operator - (const U n, const Matrix<U> &m) {
		Matrix<U> nm(m.rows, m.columns);
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.columns; j++)
				nm[i][j] = n - m.matrix[i][j];
		return nm;
	}

	friend Matrix<U> operator * (const U n, const Matrix<U> &m) {
		Matrix<U> nm(m.rows, m.columns);
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.columns; j++)
				nm[i][j] = n * m.matrix[i][j];
		return nm;
	}

	friend Matrix<U> operator / (const U n, const Matrix<U> &m) {
		Matrix<U> nm(m.rows, m.columns);
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.columns; j++)
				nm[i][j] = n / m.matrix[i][j];
		return nm;
	}

	//bool

	bool operator == (const Matrix<U> &m);

	bool operator != (const Matrix<U> &m);

	//stream

	friend ostream& operator << (ostream& out, const Matrix<U> &m) {
		m.Print(out);
		return out;
	}

	friend istream& operator >> (istream& in, Matrix<U> &m) {
		cout << "Enter " << m.name << " --> " << m.rows << " rows, " << m.columns << " columns:\n";
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.columns; j++)
				in >> m[i][j];
		return in;
	}
};

template<class U>
int Matrix<U>::obj_number = 1;

template<class U>
Matrix<U>::Matrix() {
	rows = 1;
	columns = 1;
	matrix = new myVector<U>[rows];

	name = "Matrix " + ToString(obj_number);
	obj_number++;
}

template<class U>
Matrix<U>::Matrix(const int r, const int c) {
	rows = r;
	columns = c;
	matrix = new myVector<U>[rows];
	for (int i = 0; i < rows; i++)
		matrix[i].newVectorSize(columns);

	name = "Matrix " + ToString(obj_number);
	obj_number++;
}

template<class U>
Matrix<U>::Matrix(const Matrix &m) {
	rows = m.rows;
	columns = m.columns;
	matrix = new myVector<U>[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = m.matrix[i];

	name = "Matrix " + ToString(obj_number);
	obj_number++;
}

template<class U>
Matrix<U>::~Matrix() {
	obj_number--;
	delete[]matrix;
}

template<class U>
void Matrix<U>::SetRowsNumder(const int r) {
	Matrix<> nm(r, columns);
	for (int i = 0; i < r; i++)
		if (i < rows)
			nm.matrix[i] = matrix[i];
	*this = nm;
	rows = r;
}

template<class U>
void Matrix<U>::SetColumnsNumber(const int  c) {
	for (int i = 0; i < rows; i++)
		matrix[i].newVectorSize(c);
	columns = c;
}

template<class U>
void Matrix<U>::Transpose() {
	Matrix<U> nm(columns, rows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			nm[j][i] = matrix[i][j];
	*this = nm;
}

template<class U>
bool Matrix<U>::IsSquare() {
	return rows == columns;
}

template<class U>
bool Matrix<U>::IsDiagonal() {
	if (rows != columns)
		return false;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] != 0 && j != i)
				return false;

	return true;
}

template<class U>
bool Matrix<U>::IsZero() {
	if (rows != columns)
		return false;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] != 0)
				return false;

	return true;
}

template<class U>
bool Matrix<U>::IsSingle() {
	if (rows != columns)
		return false;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] != 0 && i != j || matrix[i][j] != 1 && i == j)
				return false;

	return true;
}

template<class U>
bool Matrix<U>::IsSymmetrical() {
	if (rows != columns)
		return false;

	for (int i = 0; i < rows; i++)
		for (int j = i; j < columns; j++)
			if (matrix[i][j] != matrix[j][i])
				return false;

	return true;
}

template<class U>
bool Matrix<U>::IsUpperTriangular() {
	if (rows != columns)
		return false;

	for (int i = 1; i < rows; i++)
		for (int j = 0; j < i; j++)
			if (matrix[i][j] != 0)
				return false;

	return true;
}

template<class U>
bool Matrix<U>::IsLowerTriangular() {
	if (rows != columns)
		return false;

	for (int i = 0; i < rows; i++)
		for (int j = i + 1; j < columns; j++)
			if (matrix[i][j] != 0)
				return false;

	return true;
}

template<class U>
void Matrix<U>::TheWay(int n, ostream& out) {
	if (!IsSquare())
		return;

	Matrix<U> m(*this);
	U sum = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < rows; j++)
			sum += m[j][j];
		out << "The way for " << name << "^" << i + 1 << ": " << sum << '\n';
		m *= *this;
	}
}

template<class U>
myVector<U>& Matrix<U>::operator [] (int i) {
	try {
		if (i >= rows || i < 0) {
			throw 1;
		}
		return matrix[i];
	}
	catch (int err) {
		cout << "Out of matrix bounds. [0]-value returned: ";
		return matrix[0];
	}
}

template<class U>
Matrix<U>& Matrix<U>::operator = (const Matrix<U> &m) {
	delete[]matrix;

	rows = m.rows;
	columns = m.columns;
	matrix = new myVector<U>[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = m.matrix[i];

	return *this;
}

template<class U>
Matrix<U>& Matrix<U>::operator += (const Matrix<U> &m) {
	try {
		if (rows != m.rows || columns != m.columns)
			throw 1;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matrix[i][j] += m.matrix[i][j];
	}
	catch (int err) {
		cout << "Matrices sizes are not equal. First operand returned: ";
	}
	return *this;
}

template<class U>
Matrix<U>& Matrix<U>::operator -= (const Matrix<U> &m) {
	try {
		if (rows != m.rows || columns != m.columns)
			throw 1;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matrix[i][j] -= m.matrix[i][j];
	}
	catch (int err) {
		cout << "Matrices sizes are not equal. First operand returned: ";
	}
	return *this;
}

template<class U>
Matrix<U>& Matrix<U>::operator *= (const Matrix<U> &m) {
	try {
		if (columns != m.rows)
			throw 1;

		Matrix<U> nm(rows, m.columns);
		for (int i = 0; i < nm.rows; i++)
			for (int j = 0; j < nm.columns; j++)
				for (int k = 0; k < columns; k++)
					nm[i][j] += matrix[i][k] * m.matrix[k][j];
		*this = nm;
	}
	catch (int err) {
		cout << "Can't multiply this matrices. First operand returned: ";
	}
	return *this;
}

template<class U>
Matrix<U> Matrix<U>::operator + (const Matrix<U> &m) {
	try {
		if (rows != m.rows || columns != m.columns)
			throw 1;

		Matrix<U> nm(rows, columns);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				nm[i][j] = matrix[i][j] + m.matrix[i][j];
		return nm;
	}
	catch (int err) {
		cout << "Matrices sizes are not equal. First operand returned: ";
		return *this;
	}
}

template<class U>
Matrix<U> Matrix<U>::operator - (const Matrix<U> &m) {
	try {
		if (rows != m.rows || columns != m.columns)
			throw 1;

		Matrix<U> nm(rows, columns);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				nm[i][j] = matrix[i][j] - m.matrix[i][j];
		return nm;
	}
	catch (int err) {
		cout << "Matrices sizes are not equal. First operand returned: ";
		return *this;
	}
}

template<class U>
Matrix<U> Matrix<U>::operator * (const Matrix<U> &m) {
	try {
		if (columns != m.rows)
			throw 1;

		Matrix<U> nm(rows, m.columns);
		for (int i = 0; i < nm.rows; i++)
			for (int j = 0; j < nm.columns; j++)
				for (int k = 0; k < columns; k++)
					nm[i][j] += matrix[i][k] * m.matrix[k][j];
		return nm;
	}
	catch (int err) {
		cout << "Can't multiply this matrices. First operand returned: ";
		return *this;
	}
}

template<class U>
Matrix<U>& Matrix<U>::operator += (const U &n) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] += n;
	return *this;
}

template<class U>
Matrix<U>& Matrix<U>::operator -= (const U &n) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] -= n;
	return *this;
}

template<class U>
Matrix<U>& Matrix<U>::operator *= (const U &n) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] *= n;
	return *this;
}

template<class U>
Matrix<U>& Matrix<U>::operator /= (const U &n) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] /= n;
	return *this;
}

template<class U>
Matrix<U>& Matrix<U>::operator ^= (const unsigned int &n) {
	try {
		if (rows != columns)
			throw 1;

		Matrix<U> m(*this);
		for (int i = 1; i < n; i++)
			*this *= m;
	}
	catch (int err) {
		cout << "Matrix is not square. First operand returned: ";
	}
	return *this;
}

template<class U>
Matrix<U> Matrix<U>::operator + (const U &n) {
	Matrix<U> nm(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			nm[i][j] = matrix[i][j] + n;
	return nm;
}

template<class U>
Matrix<U> Matrix<U>::operator - (const U &n) {
	Matrix<U> nm(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			nm[i][j] = matrix[i][j] - n;
	return nm;
}

template<class U>
Matrix<U> Matrix<U>::operator * (const U &n) {
	Matrix<U> nm(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			nm[i][j] = matrix[i][j] * n;
	return nm;
}

template<class U>
Matrix<U> Matrix<U>::operator / (const U &n) {
	Matrix<U> nm(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			nm[i][j] = matrix[i][j] / n;
	return nm;
}

template<class U>
Matrix<U> Matrix<U>::operator ^ (const unsigned int &n) {
	try {
		if (rows != columns)
			throw 1;

		Matrix<U> m(*this);
		Matrix<U> nm(*this);
		for (unsigned int i = 1; i < n; i++)
			nm *= m;
		return nm;
	}
	catch (char *err) {
		cout << "Matrix is not square. First operand returned: ";
		return *this;
	}
}

template<class U>
bool Matrix<U>::operator == (const Matrix<U> &m) {
	if (rows != m.rows || columns != m.columns)
		return false;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] != m.matrix[i][j])
				return false;
	return true;
}

template<class U>
bool Matrix<U>::operator != (const Matrix<U> &m) {
	if (rows != m.rows || columns != m.columns)
		return true;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] == m.matrix[i][j])
				return false;
	return true;
}
