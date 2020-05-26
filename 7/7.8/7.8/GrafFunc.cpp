#include "List.h"
#include <iostream>

using namespace std;

void AddEdge(List** &Graf, int v1, int v2) {
	List *l2 = new List;
	l2->key = v2;
	l2->next = NULL;

	if (Graf[v1] == NULL) {
		Graf[v1] = l2;
		return;
	}

	List* top = Graf[v1];
	List* ppv = top;
	while (top != NULL) {
		ppv = top;
		if (top->key == v2)
			return;
		top = top->next;
	}

	ppv->next = l2;
}

void PrintGraf(List** &Graf, int n) {
	cout << "Graf:\n";
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";

		List* top = Graf[i];
		if (top == NULL)
			cout << "NULL";
		while (top != NULL) {
			cout << top->key;
			top = top->next;
			if (top)
				cout << ", ";
		}
		cout << '\n';
	}
}

int SearchVertex(List** &Graf, int n, int v1, int v2) {
	bool* used = new bool[n + 1];

	for (int i = 0; i <= n; i++)
		used[i] = false;

	Stack* way = NULL;
	AddToStack(way, v1);
	used[v1] = true;
	bool is_way = false;
	bool is_next_step = false;

	while (true) {
		if (way->key == v2) {
			is_way = true;
			break;
		}

		List* top = Graf[way->key];
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
			AddToStack(way, top->key);
			continue;
		}

		if (!is_next_step && way->key == v1) {
			is_way = false;
			break;
		}
		PopStack(way);
	}

	if (!is_way)
		return -1;

	while (way != NULL) {
		for (int i = 0; i <= n; i++)
			used[i] = false;
		used[way->key] = true;

		Stack* new_way = NULL;
		AddToStack(new_way, v1);
		used[v1] = true;
		is_way = false;
		is_next_step = false;

		if (way->key == v1 || way->key == v2) {
			PopStack(way);
			continue;
		}

		while (true) {
			if (new_way->key == v2) {
				is_way = true;
				break;
			}

			List* top = Graf[new_way->key];
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
				AddToStack(new_way, top->key);
				continue;
			}

			if (!is_next_step && new_way->key == v1) {
				is_way = false;
				break;
			}
			PopStack(new_way);
		}

		if (!is_way)
			return way->key;

		PopStack(way);
	}

	return -1;
}
