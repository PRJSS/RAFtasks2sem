#pragma once

struct Stack {
	int key;
	Stack* next;
};

void AddToStack(Stack* &top, int k);

void PopStack(Stack* &top);
