
#include "StackClass.h"
#include <iostream>
#include <ostream>
#include <math.h>

Stack::Stack() {
	stack = NULL;
}

Stack::~Stack() {
	Node* ppv = stack;
	while (stack) {
		ppv = stack;
		stack = stack->next;
		delete ppv;
	}
}

void Stack::Push(int k) {
	Node* ne = new Node;
	ne->key = k;
	ne->next = stack;
	stack = ne;
}

void Stack::Pop() {
	if (!stack)
		return;
	Node* pe = stack;
	stack = stack->next;
	delete pe;
}

int Stack::Top() {
	if (stack == NULL)
		return 0;
	return stack->key;
}

bool Stack::IsEmpty() {
	return !stack;
}
