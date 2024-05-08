#include "date.h"

Date::Date(int sec){
    Time += sec;
}

Date::Date(int day, int month, int year, int hour, int min, int sec){
    int n = min*60 + hour*3600 + day*3600*24;
    int m = 0;
    for(int i = 0; i < month; i++){
        m += (MonthDay[i] * (3600*24));
    }
    int y = 0;
    for(int x = 0; x < year; x++){
        for(int i = 0; i < 12; i++){
            y += (MonthDay[i] * (3600*24));
        }
    }
    Time = Time + sec + n + m + y;
}

Date::Date(Date &d){
    this->Time = d.Time;
}

void Date::print() const{
    std::cout << Time << '\n';
}

void Date::AddSec(int sec){ Time += sec; }
void Date::AddMin(int min){ Time += (min*60); }
void Date::AddHour(int hour){ Time += (hour*3600); }
void Date::AddDay(int day){ Time += (day*24*3600); }

void Date::AddMonth(int month){
    //Creating dd::mm::yy type date from int
    int m = 0;
    for(int i = 0; i < month; i++){
        m += (MonthDay[i] * (3600*24));
    }
}

void Date::AddYear(int year){
    //same as above
}