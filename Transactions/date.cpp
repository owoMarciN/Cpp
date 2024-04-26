#include "date.h"

Date::Date(int day, int month, int year){
    Day = day;
    Month = month;
    Year = year;
    Month_name = AddMonth_name(month);
}

Date::Date(int day, std::string month, int year){
    Day = day;
    Month = AddMonth_number(month);
    Year = year;
    Month_name = month;
}

std::string AddMonth_name(int month){
    month -= 1;
    if(month < 0 || month > 11){
        return "Invalid month";
    }
    return Months[month];
}

int AddMonth_number(std::string month){
    int i = 0;
    for(; i < 11; i++){
        if(month == Months[i]){
            i++;
            break;
        }
    }
    return i;
}