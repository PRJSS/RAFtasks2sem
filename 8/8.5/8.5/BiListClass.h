#include <iostream>

using namespace std;

template<class U = double>
class BiList {
	struct Node {
		U value;
		Node* prev;
		Node* next;
	};
	Node* top;
	int listSize;
public:
	BiList();

	BiList(int n, U* arr);

	BiList(BiList &L);

	~BiList();

	///////////////////////////////////////////////////////

	void Add(U v);

	void DeleteList();

	void DeleteElement(U v);

	int ListSize();

	U MaxSumm();

	Node* FindElement(U v) {
		Node* ntop = top;
		for (int i = 0; i < listSize; i++) {
			if (ntop->value == v)
				return ntop;
			ntop = ntop->next;
		}
		return NULL;
	}

	////////////////////////////////////////////////////////

	friend ostream& operator << (ostream& out, BiList &L) {
		Node* ntop = L.top;
		for (int i = 0; i < L.listSize; i++) {
			out << ntop->value << ' ';
			ntop = ntop->next;
		}
		out << '\n';
		return out;
	}
};

template<class U>
BiList<U>::BiList() {
	top = NULL;
	listSize = 0;
}

template<class U>
BiList<U>::BiList(int n, U* arr) {
	top = NULL;
	listSize = 0;

	for (int i = 0; i < n; i++) {
		Add(arr[i]);
	}
}

template<class U>
BiList<U>::BiList(BiList &L) {
	top = NULL;
	listSize = 0;

	Node* ntop = L.top;
	for (int i = 0; i < L.listSize; i++) {
		Add(ntop->value);
		ntop = ntop->next;
	}
}

template<class U>
BiList<U>::~BiList() {
	DeleteList();
}

template<class U>
void BiList<U>::Add(U v) {
	Node* nEl = new Node;
	nEl->value = v;
	nEl->next = NULL;
	nEl->prev = NULL;

	if (!top) {
		top = nEl;
		top->next = top;
		top->prev = top;
	}
	else {
		top->prev->next = nEl;
		nEl->prev = top->prev;
		top->prev = nEl;
		nEl->next = top;
	}
	listSize++;
}

template<class U>
void BiList<U>::DeleteList() {
	top->prev->next = NULL;
	Node* nt;
	while (top) {
		nt = top;
		top = top->next;
		delete nt;
	}
	listSize = 0;
}

template<class U>
void BiList<U>::DeleteElement(U v) {
	Node* el = FindElement(v);

	if (!el)
		return;

	el->next->prev = el->prev;
	el->prev->next = el->next;

	delete el;
	listSize--;
}

template<class U>
int BiList<U>::ListSize() {
	return listSize;
}

template<class U>
U BiList<U>::MaxSumm() {
	Node* ntop = top;
	Node* nbot = top->prev;

	int l = listSize / 2;
	U ms = ntop->value + nbot->value;
	for (int i = 0; i < l; i++) {
		if (ntop->value + nbot->value > ms)
			ms = ntop->value + nbot->value;
		ntop = ntop->next;
		nbot = nbot->prev;
	}

	return ms;
}
