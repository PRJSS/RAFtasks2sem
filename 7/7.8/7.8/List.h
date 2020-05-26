#include "Stack.h"

struct List {
	int key;
	List* next;
};

void AddEdge(List** &Graf, int v1, int v2);

void PrintGraf(List** &Graf, int n);

int SearchVertex(List** &Graf, int n, int v1, int v2);
