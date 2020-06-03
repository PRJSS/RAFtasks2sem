#include <iostream>

using namespace std;

template<class U = int>
class List{
    struct Node{
        U znachenie;
        Node *link;
    };
    Node* top;
    int listSize;
public:
    List(){
		top = NULL;
		listSize = 0;
	}

    List(U a){
		top = NULL;
		listSize = 0;
        add(a);
    }

    List(char c[]){
		top = NULL;
		listSize = 0;
        int k = 0;
        while(c[k] != '\0'){
            add(c[k]);
            k++;
        }
    }

	List(List &l){
		top = NULL;
		listSize = 0;
		Node* ntop = l.top;
		while(ntop){
			add(ntop->znachenie);
			ntop = ntop->link;
		}
	}

    ~List(){
		Node* ntop = top;
		while(top){
			top = top->link;
			delete ntop;
			ntop = top;
		}
	};

	///////////////////////////////////////////////////////////////////////////////

    void add(U a){
        Node* newEl = new Node;
        newEl->znachenie = a;
        newEl->link = NULL;

        if(!top){
            top = newEl;
        }
        else{
            Node* ntop = top;
            while(ntop->link){
                ntop = ntop->link;
            }
            ntop->link = newEl;
        }
        listSize++;
    }

	void deleteList(){
		Node* ntop = top;
		while(top){
			top = top->link;
			delete ntop;
			ntop = top;
		}
		listSize = 0;
	}

	void deleteElement(Node* El){
		if(!El)
			return;

		if(El == top){
			top = top->link;
			delete El;
			return;
		}

		Node* ntop = top->link;
		Node* ppv = top;
		while(ntop != El){
			ntop = ntop->link;
			ppv = ppv->link;
		}
		ppv->link = El->link;
		delete El;
		listSize--;
	}

	void deleteElement(U zn){
		Node* ppv = findElement(zn);
		//deleteElement(ppv);
		if (!ppv)
			return;
		Node* pv = ppv->link;

		if (pv){
			if (top->znachenie == zn)
				top = top->link;
			else
				ppv->link = pv->link;
			delete pv;
		}
		listSize--;
	}

	Node* findElement(U zn){
		Node* ntop = top;
		while (ntop){
			if (ntop->znachenie == zn)
				return ntop;
			ntop = ntop->link;
		}
		return NULL;
	}

	Node* findPreElement(U zn){
		Node* ntop = top;
		if (ntop->znachenie == zn)
				return ntop;
		while (ntop){
			if (ntop->link->znachenie == zn)
				return ntop;
			ntop = ntop->link;
		}
		return NULL;
	}

	bool zamena(List &L1, List &L2){
		Node* pL = top;
		Node* pL1 = L1.top;

		bool zacep = false;
        Node* enterPos = NULL;

        while(pL){
            if (pL->znachenie == pL1->znachenie){
                if (zacep == false){
                    zacep = true;
                    enterPos = pL;
                }
                pL1 = pL1->link;
                if (pL1 == NULL){
                    vstavka(enterPos, pL->link, L2);
                    return true;
                }
            }
            else{
                zacep = false;
                pL1 = L1.top;
            }
            pL = pL->link;
        }
        return false;
	}

	void vstavka(Node* enterPos, Node* exitPos, List &L){
	    Node* ntop = L.top;
		enterPos->znachenie = ntop->znachenie;

		while (enterPos->link != exitPos){
            deleteElement(enterPos->link);
		}

        enterPos->link = NULL;
        ntop = ntop->link;
        while (ntop){
			add(ntop->znachenie);
			ntop = ntop->link;
		}

		ntop = top;
		while (ntop->link)
            ntop = ntop->link;
        ntop->link = exitPos;
	}

	///////////////////////////////////////////////////////////////////////////////

    friend ostream& operator << (ostream& out, List &l){
        Node* ntop = l.top;
		if (l.listSize == 0)
			out << "empty";
        for(int i = 0; i < l.listSize; i++){
            out << ntop->znachenie << ' ';
            ntop = ntop->link;
        }
        out << '\n';
        return out;
    }
};

int main()
{
    char c[1000];

    cout << "Enter L: "; cin >> c;
    List <char> L(c);
    //cout << L;
    cout << "Enter L1: "; cin >> c;
    List <char> L1(c);
    //cout << L1;
    cout << "Enter L2: "; cin >> c;
	List <char> L2(c);
    //cout << L2;
	if (L.zamena(L1, L2))
        cout << L;
	else
        cout << "L1 don't exist in L\n";
    return 0;
}
