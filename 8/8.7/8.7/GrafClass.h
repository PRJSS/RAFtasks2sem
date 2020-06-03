
#include <iostream>

using namespace std;

class Graf {
	struct List {
		int key;
		List* next;
	};
	struct GrafList {
		int Vertex;
		List* list_v;
		GrafList* next;
	};
	GrafList* graf;
	GrafList* last_vertex;
public:
	Graf();

	Graf(int n);

	Graf(Graf &g);

	~Graf();

	////////////////////////////////////////////

	void AddVertex(int v);

	void AddEdge(int v1, int v2);

	void Print(ostream &out);

	void Delete();

	void DeleteVertex(int v);

	int SpecialVertex(int v1, int v2);

	///////////////////////////////////////////
private:
	List* ReturnVertexList(int v);

public:
	friend ostream& operator << (ostream &out, Graf &g);
};
