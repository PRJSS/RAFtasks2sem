#include <iostream>
#include <fstream>
using namespace std;

void solution_txt(ifstream& f, ifstream& g, ofstream& out) {
    double a, b;
    f >> a;
    g >> b;

    if (a == b) {
        out << a << ' ';
        f >> a;
    }

    while (!f.eof() && !g.eof()) {
        while (a > b && !g.eof()) {
            g >> b;
        }
        if (a == b) {
            out << a << ' ';
            f >> a;
        }
        while (b > a && !f.eof()) {
            f >> a;
        }
        if (a == b) {
            out << a << ' ';
            f >> a;
        }
    }
}

void solution_bin(ifstream& f, ifstream& g, ofstream& out) {
    double a, b;
    f.read(reinterpret_cast<char*> (&a), sizeof(double));
    g.read(reinterpret_cast<char*> (&b), sizeof(double));

    if (a == b) {
        out.write(reinterpret_cast<char*> (&a), sizeof(double));
        f.read(reinterpret_cast<char*> (&a), sizeof(double));
    }

    while (!f.eof() && !g.eof()) {
        while (a > b && !g.eof()) {
            g.read(reinterpret_cast<char*> (&b), sizeof(double));
        }
        if (a == b) {
            f.read(reinterpret_cast<char*> (&a), sizeof(double));
            f.read(reinterpret_cast<char*> (&a), sizeof(double));
        }
        while (b > a && !f.eof()) {
            f.read(reinterpret_cast<char*> (&a), sizeof(double));
        }
        if (a == b) {
            f.read(reinterpret_cast<char*> (&a), sizeof(double));
            f.read(reinterpret_cast<char*> (&a), sizeof(double));
        }
    }
}

int main() {

    ifstream f;
    ifstream g;
    ofstream out;

    f.open("/Users/bernat/RAFtasks2sem/Random/6.2 (8В)/6.2 (8В)/f.txt");
    g.open("/Users/bernat/RAFtasks2sem/Random/6.2 (8В)/6.2 (8В)/g.txt");
    out.open("/Users/bernat/RAFtasks2sem/Random/6.2 (8В)/6.2 (8В)/answer.txt");
    solution_txt(f, g, out);
    f.close();
    g.close();
    out.close();

    f.open("f.bin", ios::binary);
    g.open("g.bin", ios::binary);
    out.open("out.bin", ios::binary);
    solution_bin(f, g, out);
    f.close();
    g.close();
    out.close();

    return 0;
}
