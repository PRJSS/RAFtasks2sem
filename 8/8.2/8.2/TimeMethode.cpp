#include "TimeClass.h"

void Time::stabilize(){
    minutes += seconds / t;
    hours += minutes / t;
    seconds %= t;
    minutes %= t;
    hours %= 24;
}

int Time::toSeconds(){
    return hours * t * t + minutes * t + seconds;
}

int Time::different(Time tm){
    return abs(toSeconds() - tm.toSeconds());
}

#pragma mark -===================-

Time& Time::operator = (Time &tm){
    hours = tm.hours;
    minutes = tm.minutes;
    seconds = tm.seconds;
    return *this;
}

Time Time::operator + (Time &tm){
    Time ntm(hours + tm.hours, minutes + tm.minutes, seconds + tm.seconds);
    ntm.stabilize();
    return ntm;
}

Time Time::operator += (Time &tm){
    hours += tm.hours;
    minutes += tm.minutes;
    seconds += tm.seconds;
    stabilize();
    return *this;
}

Time Time::operator -= (Time &tm){
    seconds -= tm.seconds;
    if (seconds < 0){
        seconds += t;
        minutes--;
    }
    minutes -= tm.minutes;
    if (minutes < 0){
        minutes += t;
        hours--;
    }
    hours = hours - tm.hours + 24;
    stabilize();
    return *this;
}

#pragma mark -===================-

Time Time::operator + (int s){
    Time tm(hours, minutes, seconds + s);
    cout << tm;
    tm.stabilize();
    return tm;
}

Time Time::operator += (int s){
    seconds += s;
    stabilize();
    return *this;
}

Time Time::operator -= (int s){
    Time tm(0, 0, s);
    tm.stabilize();
    *this -= tm;
    return *this;
}

#pragma mark -===================-

istream& operator >> (istream& in, Time &tm){
    in >> tm.hours >> tm.minutes >> tm.seconds;
    tm.stabilize();
    return in;
}

ostream& operator << (ostream& out, Time &tm){
    if (tm.hours < 10)
        out << 0;
    out << tm.hours << ':';
    if (tm.minutes < 10)
        out << 0;
    out << tm.minutes << ':';
    if (tm.seconds < 10)
        out << 0;
    out << tm.seconds << '\n';
    return out;
}
