
#include <iostream>
#include <ostream>
#include <math.h>

using namespace std;

class Time{
    int hours;
    int minutes;
    int seconds;
    int const t = 60;
public:
    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h){
        hours = h;
        minutes = 0;
        seconds = 0;
        stabilize();
    }

    Time(int h, int m){
        hours = h;
        minutes = m;
        seconds = 0;
        stabilize();
    }

    Time(int h, int m, int s){
        hours = h;
        minutes = m;
        seconds = s;
        stabilize();
    }

    Time(Time &tm){
        hours = tm.hours;
        minutes = tm.minutes;
        seconds = tm.seconds;
    }

    ~Time() {};

    #pragma mark -===================-

    void stabilize();

    int toSeconds();

    int different(Time tm);

    #pragma mark -===================-

    Time& operator = (Time &tm);

    Time operator + (Time &tm);

    Time operator += (Time &tm);

    Time operator -= (Time &tm);

    #pragma mark -===================-

    Time operator + (int s);

    Time operator += (int s);

    Time operator -= (int s);

    #pragma mark -===================-

    friend istream& operator >> (istream& in, Time &tm);

    friend ostream& operator << (ostream& out, Time &tm);
};

