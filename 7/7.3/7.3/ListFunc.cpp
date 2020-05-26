#include  "ListStruct.h"
#include <string.h>
#include <math.h>
double const razb = 0.000001;

bool sravnenieStudent(Student &A, Student &B){
    int la, lb;
    la = strlen(A.snp.surname);
    lb = strlen(B.snp.surname);
    for (int i = 0; i < la && i < lb; i++){
        if (A.snp.surname[i] < B.snp.surname[i]){
            return true;
        }
        if (A.snp.surname[i] > B.snp.surname[i]){
            return false;
        }
    }
    if(la < lb){
        return true;
    }
    return false;
}

void findPos(Node *top, Student student, Node *&ppv){
    Node *pv = top;
    ppv = top;
    while(pv && sravnenieStudent(pv->student, student)){
        ppv = pv;
        pv = pv->link;
    }
}

void add(Node *&top, Student student){
    Node *nv, *ppv = NULL;
    nv = new Node;
    nv->student = student;
    nv->link = NULL;

    if (!top){
        top = nv;
    }
    else{
        if(sravnenieStudent(student, top->student)){
            nv->link = top;
            top = nv;
        }
        else{
            findPos(top, student, ppv);
            nv->link = ppv->link;
            ppv->link = nv;
        }
    }
}

void print(Node *top){
    while (top){
        top->student.print();
        top = top->link;
    }
}

void del(Node *&top, Node *&ppv){
    Node *pv = top;
    top = top->link;
    if (ppv != NULL){
        ppv->link = top;
    }
    delete pv;
}

void BestStudents(Node *&top, Node *&BS, double avarageMark){
    Node *ppv = NULL;
    Node *ntop = top;
    while (ntop){
        if (ntop->student.mark >= avarageMark || fabs(ntop->student.mark - avarageMark) <= razb){
            add(BS, ntop->student);
            if (ppv == NULL){
                del(top, ppv);
                ntop = top;
            }
            else del(ntop, ppv);
        }else{
            ppv = ntop;
            ntop = ntop->link;
        }
    }
}
