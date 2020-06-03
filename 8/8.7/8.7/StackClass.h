


class Stack {
	struct Node {
		int key;
		Node* next;
	};
	Node* stack;
public:
	Stack();

	~Stack();

	void Push(int k);

	void Pop();

	int Top();

	bool IsEmpty();
};
