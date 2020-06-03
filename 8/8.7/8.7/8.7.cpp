
#include "StackClass.h"
#include "GrafClass.h"
#include <iostream>
#include <ostream>
#include <math.h>

using namespace std;

int main()
{
	Graf graf;
	int n; cout << "Enter number of edges: "; cin >> n;

	cout << "Enter edges:\n";
	int v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> v1 >> v2;
		graf.AddEdge(v1, v2);
	}

	cout << graf;

	cout << "Enter first vertex: "; cin >> v1;
	cout << "Enter second vertex: "; cin >> v2;

	int v = graf.SpecialVertex(v1, v2);
	cout << "Special vertex ";
	if (v == -1)
		cout << "doesn't exist\n";
	else
		cout << "is " << v << '\n';
	
}
