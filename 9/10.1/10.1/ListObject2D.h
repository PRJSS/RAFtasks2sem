#pragma once
#include "Hierarchy.h"

class ListObject2D : public Object2D{
	struct List {
		Object2D* obj;
		List* next;
	};
	List* list;
	List* last; //хранит указатель на последний объект
	int size;
public:
	ListObject2D();

	ListObject2D(const ListObject2D &l);

	ListObject2D(ListObject2D&& l);

	~ListObject2D();

	/////////////////////////////////////////////

	void Print(ostream& out = cout) {
		if (list == NULL) {
			out << "List is empty\n";
			return;
		}
		out << "List --> size: " << size << ":\n";
		List* top = list;
		int k = 1;
		while (top) {
			out << k << ": ";
			top->obj->Print(out);
			top = top->next;
			k++;
		}
	}

	void GetInformation(ostream& out = cout) {
		out << "list " << size << '\n';
		List* top = list;
		while (top) {
			top->obj->GetInformation(out);
			top = top->next;
		}
	}

	void Add(const Rectangle &r);

	void Add(const Ellipse &e);

	void Add(const Star &s);

	void Add(const Polygon &p);

	void Add(const Text &t);

	void DeleteObject(const int n);

	void Delete();

	ListObject2D& operator =(const ListObject2D &l);

	ListObject2D& operator =(ListObject2D&& l);
};