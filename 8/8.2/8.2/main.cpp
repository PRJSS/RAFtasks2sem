#include "TimeClass.h"

using namespace std;

int main()
{
    Time a;
    cout << "a = " << a;
    Time b(10, 10, 10);
    cout << "b = " << b;
    Time c(b);
    cout << "c = " << c;
    
    cout<<"\n";
    cout<<"a = c:  ";
    a = c;
    cout << "a = " << a;
    cout<<"\n\n";
    
    a += 10;
    cout << "a += 10: " << a;
    c -= 20;
    cout << "c -= 20: " << c;
    b += c;
    cout << "b += c: " << b;
    b -= a;
    cout << "b -= a: " << b;
    
    
    cout<<"\n";
    cout << "Different a and c: " << a.different(c);


    cout<<"\n\n";
    return 0;
}
