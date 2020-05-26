#include "Stack.h"
#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	int n; cout << "Enter number of tops: "; cin >> n;

	List** Graf = new List*[n + 1];
	for (int i = 0; i <= n; i++)
		Graf[i] = NULL;

	int engesNum; cout << "Enter number of edges: "; cin >> engesNum;
	int t1, t2;
	for (int i = 0; i < engesNum; i++) {
		cin >> t1 >> t2;
		AddEdge(Graf, t1, t2);
	}

	PrintGraf(Graf, n);

	int v1, v2;
	cout << "Enter first vertex: "; cin >> v1;
	cout << "Enter second vertex: "; cin >> v2;
	int c = SearchVertex(Graf, n, v1, v2);

	if (c != -1)
		cout << "Special vertex is " << c;
	else
		cout << "Special vertex doesn't exist";

    cout<<"\n";
	return 0;
}
