#ifndef DATE_H
#define DATE_H

// LIBRARIES //
#include <iostream>
#include <string>

// CONSTANT MONTH NAMES //
const std::string Months[] = {"January", "February", "March", "April", "May", 
                "June", "July", "August", "September", 
                "October", "November", "December"};

// CLASS //
class Date{
public:
    int Day;
    int Month;
    int Year;
    std::string Month_name;
    Date(int day, int month, int year);
    Date(int day, std::string month, int year);
};

// ADDITONAL FUNCTION DECLARATIONS //
std::string AddMonth_name(int month);
int AddMonth_number(std::string month);

#endif