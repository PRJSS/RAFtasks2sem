#include <iostream>
using namespace std;


struct Node{
    double a;
    Node* pred;
    Node* next;
};

void add(Node* &top, double a){
    Node* nv = new Node;
    nv->a = a;
    nv->pred = NULL;
    nv->next = NULL;

    if (!top){
        top = nv;
        nv->pred = nv;
        nv->next = nv;
    }
    else{
        nv->next = top;
        nv->pred = top->pred;
        top->pred->next = nv;
        top->pred = nv;
    }
}

void print(Node* top){
    Node* ntop = top;
    do{
        cout << top->a << ' ';
        top = top->next;
    }while(top != ntop);
    cout << '\n';
}

void printRevers(Node* top){
    top = top->pred;
    Node* ntop = top;
    do{
        cout << top->a << ' ';
        top = top->pred;
    }while(top != ntop);
    cout << '\n';
}

double maxSum(Node* top){
    Node* bot = top->pred;
    double maxS = top->a + bot->a;
    do{
        top = top->next;
        bot = bot->pred;
        if(top->a + bot->a > maxS) maxS = top->a + bot->a;
    }while(top->next != bot);
    return maxS;
}
