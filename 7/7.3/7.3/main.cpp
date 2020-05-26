#include <iostream>
#include  "ListStruct.h"
#include <fstream>




using namespace std;



int main()
{
    int n=30; cout<<"Enter number of students\n";
    cin>>n;

    Node *top = NULL;
    Student stud;
    
    double sumMark = 0;
    for (int i = 0; i < n; i++){
        stud.enter();
        sumMark += stud.mark;
        add(top, stud);
    }

    Node *bestStudents = NULL;

    BestStudents(top, bestStudents, sumMark / n);

    cout << "----------------------------\n";
    print(top);
    cout << "----------------------------\n";
    print(bestStudents);

    return 0;
}
