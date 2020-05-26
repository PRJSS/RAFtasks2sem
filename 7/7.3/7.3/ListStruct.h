#include <fstream>

int const MAX = 60;

struct SNP{
    char surname[MAX];
    char name[MAX];
    char patronymic[MAX];
};

struct Birthday{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Student{
    SNP snp;
    Birthday birthday;
    unsigned short kurs;
    double mark;

    void enter();
    void print();
};


struct Node{
    Student student;
    Node *link;
};

bool sravnenieStudent(Student &A, Student &B);
void findPos(Node *top, Student student, Node *&ppv);
void add(Node *&top, Student student);
void print(Node *top);
void del(Node *&top, Node *&ppv);
void BestStudents(Node *&top, Node *&BS, double avarageMark);


