#include <iostream>
#include <string>

using namespace std;

bool simple(string);

int main()
{
    string s, otvet;
    cout << "Enter string: "; getline(cin, s);

    s += ' ';
    unsigned int lpos = 0;
    unsigned int rpos;
    int l = s.size();
    string cs;
    do{
        rpos = s.find(' ', lpos);
        cs.assign(s, lpos, rpos - lpos);
        if(simple(cs)) otvet += cs + ' ';
        lpos = rpos + 1;
    }while(rpos < l);

    cout << otvet;

    return 0;
}

bool simple(string s){
    int l = s.size();
    for (int i = 0; i < l; i++){
        for (int j = i + 1; j < l; j++){
            if (s[i] == s[j]) return false;
        }
    }
    return true;
}
