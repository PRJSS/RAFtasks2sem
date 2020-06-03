
#include "StackClass.h"
#include "GrafClass.h"
#include <iostream>
#include <math.h>

Graf::Graf() {
	graf = NULL;
	last_vertex = NULL;
}

Graf::Graf(int n) {
	GrafList* ne = new GrafList;
	ne->Vertex = 1;
	ne->list_v = NULL;
	ne->next = NULL;
	graf = ne;
	GrafList* ppv = graf;
	for (int i = 2; i <= n; i++) {
		ne = new GrafList;
		ne->Vertex = i;
		ne->list_v = NULL;
		ne->next = NULL;
		ppv->next = ne;
		ppv = ppv->next;
	}
	last_vertex = ppv;
}

Graf::Graf(Graf &g) {
	GrafList* gv = g.graf;
	GrafList* ppv = g.graf;
	while (gv != NULL) {
		GrafList* ne = new GrafList;
		ne->Vertex = gv->Vertex;

		ne->list_v = NULL;
		List* vl = gv->list_v;
		List* lppv = gv->list_v;
		while (vl != NULL) {
			List* lne = new List;
			lne->key = vl->key;
			lne->next = NULL;

			if (ne->list_v == NULL) {
				ne->list_v = lne;
				lppv = lne;
			}
			else {
				lppv->next = lne;
				lppv = lppv->next;
			}

			vl = vl->next;
		}

		ne->next = NULL;
		if (graf == NULL) {
			graf = ne;
			ppv = ne;
		}
		else {
			ppv->next = ne;
			ppv = ppv->next;
		}

		gv = gv->next;
	}
	last_vertex = ppv;
}

Graf::~Graf() {
	Delete();
}

void Graf::AddVertex(int v) {
	v = abs(v);
	GrafList* ne = new GrafList;
	ne->Vertex = v;
	ne->list_v = NULL;
	ne->next = NULL;

	if (graf == NULL) {
		graf = ne;
		last_vertex = ne;
		return;
	}
	if (graf->Vertex == v)
		return;
	if (graf->Vertex > v) {
		ne->next = graf;
		graf = ne;
		return;
	}
	GrafList* ppv = graf;
	while (ppv->next != NULL) {
		if (ppv->next->Vertex == v)
			return;
		if (ppv->next->Vertex > v)
			break;
		ppv = ppv->next;
	}
	ne->next = ppv->next;
	ppv->next = ne;
	if (ne->next == NULL)
		last_vertex = ne;
}

void Graf::AddEdge(int v1, int v2) {
	v1 = abs(v1);
	v2 = abs(v2);
	if (v1 == v2)
		return;
	AddVertex(v1);
	AddVertex(v2);

	GrafList* v = graf;
	while (v->Vertex != v1)
		v = v->next;

	List* ne = new List;
	ne->key = v2;
	ne->next = NULL;

	if (v->list_v == NULL) {
		v->list_v = ne;
		return;
	}
	if (v->list_v->key == v2)
		return;
	if (v->list_v->key > v2) {
		ne->next = v->list_v;
		v->list_v = ne;
	}
	List* ppv = v->list_v;
	while (ppv->next != NULL) {
		if (ppv->next->key == v2)
			return;
		if (ppv->next->key > v2)
			break;
		ppv = ppv->next;
	}
	ne->next = ppv->next;
	ppv->next = ne;
}

void Graf::Print(ostream &out = cout) {
	if (graf == NULL) {
		out << "Graf is empty\n";
		return;
	}
	out << "Graf:\n";
	GrafList* v = graf;
	while (v) {
		out << v->Vertex << ": ";

		List* vl = v->list_v;
		if (vl == NULL)
			out << "NULL";
		while (vl) {
			out << vl->key;
			vl = vl->next;
			if (vl)
				out << ", ";
		}
		out << '\n';
		v = v->next;
	}
}

void Graf::Delete() {
	GrafList* ppv;
	List* lppv;
	while (graf) {
		ppv = graf;
		while (graf->list_v) {
			lppv = graf->list_v;
			graf->list_v = lppv->next;
			delete lppv;
		}
		graf = graf->next;
		delete ppv;
	}
}

void Graf::DeleteVertex(int v) {
	v = abs(v);
	if (graf == NULL)
		return;

	GrafList* ppv;
	List* lppv;
	if (graf->Vertex == v) {
		ppv = graf;
		while (graf->list_v) {
			lppv = graf->list_v;
			graf->list_v = lppv->next;
			delete lppv;
		}
		graf = graf->next;
		if (graf == NULL)
			last_vertex = NULL;
		delete ppv;
	}

	GrafList* top = graf;
	List* ltop;
	while (top) {
		if (top->list_v && top->list_v->key == v) {
			lppv = top->list_v;
			top->list_v = lppv->next;
			delete lppv;
		}
		ltop = top->list_v;
		while (ltop) {
			if (ltop->next && ltop->next->key == v) {
				lppv = ltop->next;
				ltop->next = lppv->next;
				delete lppv;
				break;
			}
			ltop = ltop->next;
		}

		if (top->next && top->next->Vertex == v) {
			ppv = top->next;
			while (ppv->list_v) {
				lppv = ppv->list_v;
				ppv->list_v = lppv->next;
				delete lppv;
			}
			top->next = ppv->next;
			delete ppv;
		}
		if (top->next = NULL)
			last_vertex = top;
		top = top->next;
	}
}

int Graf::SpecialVertex(int v1, int v2) {
	v1 = abs(v1);
	AddVertex(v1);
	v2 = abs(v2);
	AddVertex(v2);

	int max_v = last_vertex->Vertex;
	bool* used = new bool[max_v + 1];

	for (int i = 0; i <= max_v; i++)
		used[i] = false;

	Stack way;
	way.Push(v1);
	used[v1] = true;
	bool is_way = false;
	bool is_next_step = false;

	while (true) {
		if (way.Top() == v2) {
			is_way = true;
			break;
		}

		List* top = ReturnVertexList(way.Top());
		is_next_step = false;
		while (top != NULL) {
			if (!used[top->key]) {
				is_next_step = true;
				break;
			}
			top = top->next;
		}

		if (is_next_step) {
			used[top->key] = true;
			way.Push(top->key);
			continue;
		}

		if (!is_next_step && way.Top() == v1) {
			is_way = false;
			break;
		}
		way.Pop();
	}

	if (!is_way)
		return -1;

	while (!way.IsEmpty()) {
		for (int i = 0; i <= max_v; i++)
			used[i] = false;
		used[way.Top()] = true;

		Stack new_way;
		new_way.Push(v1);
		used[v1] = true;
		is_way = false;
		is_next_step = false;

		if (way.Top() == v1 || way.Top() == v2) {
			way.Pop();
			continue;
		}

		while (true) {
			if (new_way.Top() == v2) {
				is_way = true;
				break;
			}

			List* top = ReturnVertexList(new_way.Top());
			is_next_step = false;
			while (top != NULL) {
				if (!used[top->key]) {
					is_next_step = true;
					break;
				}
				top = top->next;
			}

			if (is_next_step) {
				used[top->key] = true;
				new_way.Push(top->key);
				continue;
			}

			if (!is_next_step && new_way.Top() == v1) {
				is_way = false;
				break;
			}
			new_way.Pop();
		}

		if (!is_way)
			return way.Top();

		way.Pop();
	}

	return -1;
}

Graf::List* Graf::ReturnVertexList(int v) {
	GrafList* top = graf;
	while (top) {
		if (top->Vertex == v)
			return top->list_v;
		top = top->next;
	}
	return NULL;
}

ostream& operator << (ostream &out, Graf &g) {
	g.Print(out);
	return out;
}
