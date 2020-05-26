//
//  main.cpp
//  7.7
//
//  Created by Danila Bernat on 5/21/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct Tree{
    int a;
    Tree* left;
    Tree* right;
};

Tree* srchPos(Tree* top, int a){
    Tree* ppv = top;
    while (top){
        ppv = top;
        if (a < top->a)
            top = top->left;
        else
            top = top->right;
    }
    return ppv;
}

void add(Tree* &top, int a){
    Tree* pn = new Tree;
    pn->a = a;
    pn->left = NULL;
    pn->right = NULL;

    if (!top){
        top =  pn;
    }
    else{
        Tree* ppv;
        ppv = srchPos(top, a);
        if (a < ppv->a)
            ppv->left = pn;
        else
            ppv->right = pn;
    }
}

void print_treeL(Tree* top){
    if (top){
        print_treeL(top->left);
        cout << top->a << ' ';
        print_treeL(top->right);
    }
}

void print_treeR(Tree* top){
    if (top){
        print_treeR(top->right);
        cout << top->a << ' ';
        print_treeR(top->left);
    }
}

void print_tree_level(Tree* top, int level){
    if (top){
        print_tree_level(top->right, level + 1);

        for (int i = 0; i < level; i++)
            cout << '\t';
        cout << top->a << '\n';
        print_tree_level(top->left, level + 1);
    }
}

void print_tree_level(Tree* top){
    print_tree_level(top, 0);
}

bool susch(Tree* top, int a){
    while (top){
        if (top->a == a)
            return true;
        if (a < top->a)
            top = top->left;
        else
            top = top->right;
    }
    return false;
}

int branchNum(Tree* top, int a){
    int n = 0;
    if (susch(top, a)){
        while (top){
            cout << top->a << ' ';
            if (top->a == a)
                return n;
            if (a < top->a)
                top = top->left;
            else
                top = top->right;
            n++;
        }
    }
    cout << "not found";
    return -1;
}

int main()
{
    int n;
    cout<<"Number of elements: ";
    cin >> n;

    Tree* tree = NULL;

    cout<<"Print elements:\n";
    int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        add(tree, a);
    }

    print_treeL(tree);
    cout << '\n';
    print_treeR(tree);
    cout << '\n';
    cout << "\n-----------------------------------------------------\n";
    print_tree_level(tree);
    cout << "\n-----------------------------------------------------\n";

    cout<<"\nSearch element: ";
    cin >> n;
    n = branchNum(tree, n);
    if(n == -1) cout << '\n' << n;

    return 0;
}
