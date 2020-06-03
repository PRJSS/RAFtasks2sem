#include "BinTree.h"

int main()
{
	int n;
	cout << "Enter count N of element: "; cin >> n;
	BinTree <int> tree;
	cout << "Enter tree elements: ";
	int v;
	for (int i = 0; i < n; i++) {
		cin >> v;
		tree.Add(v);
	}
	cout << tree;
	cout << "Enter tree element: "; cin >> v;
	tree.WayToElement(v);
	return 0;
}
