#include "Stack.h"

void AddToStack(Stack* &top, int k) {
	Stack* ne = new Stack;
	ne->key = k;
	ne->next = top;
	top = ne;
}

void PopStack(Stack* &top) {
	Stack* pe = top;
	top = top->next;
	delete pe;
}
