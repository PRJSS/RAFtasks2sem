#pragma once
#include <fstream>
#include "Hierarchy.h"

class VectorObject2D : public Object2D{
	Object2D** vector;
	int max_size;
	int size;
	string saving_file;
public:
	VectorObject2D();

	VectorObject2D(const string &name);

	VectorObject2D(const VectorObject2D &v);

	VectorObject2D(VectorObject2D&& v);

	~VectorObject2D();
	
	////////////////////////////////////////////////

	void Print(ostream &out = cout) {
		if (size == 0) {
			out << "Vector is empty\n";
			return;
		}
		out << "Vector --> size -- " << size << ":\n";
		for (int i = 0; i < size; i++)
			out << i << ": " << *vector[i];
	}

	void GetInformation(ostream& out = cout) {
		out << "vector " << size << ' ' << max_size << '\n';
		for (int i = 0; i < size; i++)
			vector[i]->GetInformation(out);
	}

	void SetSavingFile(const string &name);

	void Add(const Rectangle &r);

	void Add(const Ellipse &e);

	void Add(const Star &s);

	void Add(const Polygon &p);

	void Add(const Text &t);

private:
	void NewVectorSize(int new_size);

public:
	void Delete();

	void DeleteObject(int n);

	VectorObject2D& operator =(const VectorObject2D &v);

	VectorObject2D& operator =(VectorObject2D&& v);
};