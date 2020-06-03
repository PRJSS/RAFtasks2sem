#include <iostream>
#include <ostream>

using namespace std;

template<class U>
class BinTree {
	struct tree {
		U value;
		tree* left;
		tree* right;
	};
	tree* top;

public:
	BinTree();

	BinTree(int n, U *arr);

	BinTree(BinTree &BT);

	~BinTree();

	/////////////////////////////////////////////////////////////

	void Add(U v);

	void Delete();

	void WayToElement(U v);

	void DeleteElement(U v);

	bool ElementExist(U v);

private:
	void CopyTree(tree* ntop);

	void DeleteTree(tree* ntop);

	void DeleteTreeElement(tree* pt);

	tree* SrchPos(U v) {
		tree* ntop = top;
		tree* ppv = top;
		while (ntop) {
			ppv = ntop;
			if (ntop->value > v) {
				ntop = ntop->left;
			}
			else {
				ntop = ntop->right;
			}
		}
		return ppv;
	}

	/////////////////////////////////////////////////////////////

public:
	friend ostream& operator << (ostream& out, BinTree &tr) {
		out << "=========================================================\n";
		if (tr.top != NULL)
			print_tree_level(out, tr.top, 0);
		else
			out << "Tree is empty\n";
		out << "=========================================================\n";
		return out;
	}

private:
	friend void print_tree_level(ostream& out, tree* ntop, int level) {
		if (ntop) {
			print_tree_level(out, ntop->right, level + 1);
			for (int i = 0; i < level; i++)
				out << '\t';
			out << ntop->value << '\n';
			print_tree_level(out, ntop->left, level + 1);
		}
	}
};

template<class U>
BinTree<U>::BinTree() {
	top = NULL;
}

template<class U>
BinTree<U>::BinTree(int n, U *arr) {
	top = NULL;
}

template<class U>
BinTree<U>::BinTree(BinTree &BT) {
	top = NULL;
	CopyTree(BT.top);
}

template<class U>
BinTree<U>::~BinTree() {
	Delete();
}

template<class U>
void BinTree<U>::Add(U v) {
	tree* nEl = new tree;
	nEl->value = v;
	nEl->left = NULL;
	nEl->right = NULL;

	if (!top) {
		top = nEl;
	}
	else {
		tree* ppv = SrchPos(v);
		if (ppv->value > v) {
			ppv->left = nEl;
		}
		else {
			ppv->right = nEl;
		}
	}
}

template<class U>
void BinTree<U>::Delete() {
	DeleteTree(top);
	top = NULL;
}

template<class U>
void BinTree<U>::WayToElement(U v) {
	int k = 0;
	if (ElementExist(v)) {
		tree* tr = top;
		cout << "Way: ";
		while (tr) {
			k++;
			if (tr->value != v)
				cout << tr->value << "-->";
			else
				cout << tr->value;
			if (v < tr->value) tr = tr->left;
			else if (v > tr->value) tr = tr->right;
			else {
				cout << ". Branches -- " << --k << '\n';
				return;
			}
		}
	}
	else
		cout << "Element doesn't exist\n";
}

template<class U>
void BinTree<U>::DeleteElement(U v) {
	tree* ntop = top;
	tree* ppv = top;
	while (ntop && !(ntop->value == v)) {
		ppv = ntop;
		if (ntop->value > v)
			ntop = ntop->left;
		else
			ntop = ntop->right;
	}
	if (ntop) {
		DeleteTreeElement(ntop);
	}
}

template<class U>
void BinTree<U>::CopyTree(tree* ntop) {
	if (ntop) {
		Add(ntop->value);
		CopyTree(ntop->left);
		CopyTree(ntop->right);
	}
}

template<class U>
void BinTree<U>::DeleteTree(tree* ntop) {
	if (ntop) {
		DeleteTree(ntop->left);
		DeleteTree(ntop->right);
		delete ntop;
	}
}

template<class U>
void BinTree<U>::DeleteTreeElement(tree* pt) {
	tree* nt = pt;
	tree* pv = pt;

	if (pt->left) {
		nt = nt->left;
		while (nt)
		{
			pv = nt;
			nt = nt->right;
		}
	}
	else if (pt->right) {
		nt = nt->right;
		while (nt)
		{
			pv = nt;
			nt = nt->left;
		}
	}

	U newValue = pv->value;

	if (pv->left != NULL || pv->right != NULL)
		DeleteTreeElement(pv);
	else
	{
		nt = top;
		tree* ppv = top;
		while (nt != pv) {
			ppv = nt;
			if (pv->value < nt->value) {
				nt = nt->left;
			}
			else {
				nt = nt->right;
			}
		}

		if (ppv == top && pv->value == top->value) {
			top = NULL;
			delete pv;
		}
		else if (ppv->left == pv) {
			ppv->left = NULL;
			delete pv;
		}
		else {
			ppv->right = NULL;
			delete pv;
		}
	}

	pt->value = newValue;
}

template<class U>
bool BinTree<U>::ElementExist(U v) {
	tree* tr = top;
	while (tr) {
		if (v < tr->value) tr = tr->left;
		else if (v > tr->value) tr = tr->right;
		else return true;
	}
	return false;
}
