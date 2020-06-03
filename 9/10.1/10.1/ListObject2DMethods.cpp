
#include "Hierarchy.h"
#include "ListObject2D.h"

ListObject2D::ListObject2D() {
	object = list2D;
	list = NULL;
	last = NULL;
	size = 0;
}

ListObject2D::ListObject2D(const ListObject2D &l) {
	object = list2D;
	list = NULL;
	last = NULL;
	List* top = l.list;
	while (top != NULL) {
		switch (top->obj->GetObjectType())
		{
		case rectangle2D: {
			Add(*dynamic_cast<Rectangle*>(top->obj));
			break;
		}
		case ellipse2D: {
			Add(*dynamic_cast<Ellipse*>(top->obj));
			break;
		}
		case star2D: {
			Add(*dynamic_cast<Star*>(top->obj));
			break;
		}
		case polygon2D: {
			Add(*dynamic_cast<Polygon*>(top->obj));
			break;
		}
		case text2D: {
			Add(*dynamic_cast<Text*>(top->obj));
			break;
		}
		}
		top = top->next;
	}
	size = l.size;
}

ListObject2D::ListObject2D(ListObject2D&& l) {
	object = list2D;
	list = l.list;
	l.list = NULL;
	last = l.last;
	l.last = NULL;
	size = l.size;
	l.size = 0;
}

ListObject2D::~ListObject2D() {
	Delete();
}

void ListObject2D::Add(const Rectangle &r) {
	List* ne = new List;
	ne->obj = new Rectangle(r);
	ne->next = NULL;
	if (list == NULL) {
		list = ne;
		last = ne;
	}
	else {
		last->next = ne;
		last = ne;
	}
	size++;
}

void ListObject2D::Add(const Ellipse &e) {
	List* ne = new List;
	ne->obj = new Ellipse(e);
	ne->next = NULL;
	if (list == NULL) {
		list = ne;
		last = ne;
	}
	else {
		last->next = ne;
		last = ne;
	}
	size++;
}

void ListObject2D::Add(const Star &s) {
	List* ne = new List;
	ne->obj = new Star(s);
	ne->next = NULL;
	if (list == NULL) {
		list = ne;
		last = ne;
	}
	else {
		last->next = ne;
		last = ne;
	}
	size++;
}

void ListObject2D::Add(const Polygon &p) {
	List* ne = new List;
	ne->obj = new Polygon(p);
	ne->next = NULL;
	if (list == NULL) {
		list = ne;
		last = ne;
	}
	else {
		last->next = ne;
		last = ne;
	}
	size++;
}

void ListObject2D::Add(const Text &t) {
	List* ne = new List;
	ne->obj = new Text(t);
	ne->next = NULL;
	if (list == NULL) {
		list = ne;
		last = ne;
	}
	else {
		last->next = ne;
		last = ne;
	}
	size++;
}

void ListObject2D::DeleteObject(const int n) {
	if (n > size || n <= 0)
		return;

	List* need_to_delete;

	if (n == 1) {
		need_to_delete = list;
		list = list->next;
		if (list == NULL)
			last = NULL;
	}
	else {
		int k = 1;
		List* ppv = list;
		while (k + 1 < n) {
			ppv = ppv->next;
			k++;
		}
		need_to_delete = ppv->next;
		ppv->next = need_to_delete->next;
		if (ppv->next == NULL)
			last = ppv;
	}

	if (need_to_delete) {
		switch (need_to_delete->obj->GetObjectType()) {
		case rectangle2D: {
			delete dynamic_cast<Rectangle*>(need_to_delete->obj);
			break;
		}
		case ellipse2D: {
			delete dynamic_cast<Ellipse*>(need_to_delete->obj);
			break;
		}
		case star2D: {
			delete dynamic_cast<Star*>(need_to_delete->obj);
			break;
		}
		case polygon2D: {
			delete dynamic_cast<Polygon*>(need_to_delete->obj);
			break;
		}
		case text2D: {
			delete dynamic_cast<Text*>(need_to_delete->obj);
			break;
		}
		}
		delete need_to_delete;
	}

	size--;
}

void ListObject2D::Delete() {
	while (list != NULL) {
		DeleteObject(1);
	}
}

ListObject2D& ListObject2D::operator =(const ListObject2D &l) {
	Delete();

	List* top = l.list;
	while (top != NULL) {
		switch (top->obj->GetObjectType())
		{
		case rectangle2D: {
			Add(*dynamic_cast<Rectangle*>(top->obj));
			break;
		}
		case ellipse2D: {
			Add(*dynamic_cast<Ellipse*>(top->obj));
			break;
		}
		case star2D: {
			Add(*dynamic_cast<Star*>(top->obj));
			break;
		}
		case polygon2D: {
			Add(*dynamic_cast<Polygon*>(top->obj));
			break;
		}
		case text2D: {
			Add(*dynamic_cast<Text*>(top->obj));
			break;
		}
		}
		top = top->next;
	}
	size = l.size;

	return *this;
}

ListObject2D& ListObject2D::operator =(ListObject2D&& l) {
	Delete();

	list = l.list;
	l.list = NULL;
	last = l.last;
	l.last = NULL;
	size = l.size;
	l.size = 0;

	return *this;
}
