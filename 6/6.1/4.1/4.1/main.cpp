//
//  main.cpp
//  4.1
//
//  Created by Danila Bernat on 3/11/20.
//  Copyright © 2020 Danila Bernat. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <cstddef>

using namespace std;

void check(string str){
    bool Num=0, Let=0;
    for (int i=0; i<str.length(); i++){
        
        if (('a' <= str[i] && str[i] <=  'z') ||
        ('A' <= str[i] && str[i] <= 'Z') ||
            str[i] == '_'){Let=1;}
        
        if ('0' <= str[i] && str[i] <= '9'){Num=1;}
    }
    
    
    if (Num==0 && Let==0){cout<<"Другой вариант";}else{
        if (Num==1 && Let==1){cout<<"Индефикатор";}else{
            if (Num==1){cout<<"Число";}else{
                if (Let==1){cout<<"Индефикатор";}
            }
        }
    }
}

int main()
{
    string c;
    
    cout << "Enter text: ";
    cin >> c;

    check(c);
    
    cout<<"\n\n\n";
}
