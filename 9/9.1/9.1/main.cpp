
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void existance(ifstream &, vector <bool> &);

void fillV(vector <int> &, vector <bool> &);

int main()
{
    vector <int> vect;
    vector <bool> is_exist(10001, false);
    //Читает числа из Chisla.txt
    ifstream fin("Chisla.txt");
    existance(fin, is_exist);
    fillV(vect, is_exist);
    for (vector<int>::iterator p = vect.begin(); p != vect.end(); p++)
        cout << *p << ' ';
}

void existance(ifstream &in, vector <bool> &vect) {
    int val;
    int i = 0;
    while (in >> val)
        if (vect[val] == false)
            vect[val] = true;
        
}

void fillV(vector <int> &vect, vector <bool> &exist) {
    int i = 1;
    for (vector<bool>::iterator p = exist.begin(); p != exist.end(); p++) {
        if (*p == true)
            vect.push_back(i);
        i++;
    }
}
