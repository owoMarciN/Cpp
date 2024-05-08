#ifndef CLASS_H_
#define CLASS_H_

#include <time.h>
#include <iostream>

const int MonthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

class Date{

private:

    int Time;

public:

    Date(){
        Time = 0;
    }

    Date(int sec);

    Date(int day, int month, int year, int hour, int min, int sec);

    Date(Date &d);

    Date &operator=(Date &d){
        Time = d.Time;
        return *this;
    }

public:

    void AddSec(int sec);
    void AddMin(int min);
    void AddHour(int hour);
    void AddDay(int day);
    void AddMonth(int month);
    void AddYear(int year);

    void print() const;

};

#endif