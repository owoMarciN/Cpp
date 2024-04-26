#include "transaction.h"

int Days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Transaction::Transaction(int day, int month, int year, std::string address, double amount){
    Day = day;
    Month = month;
    Year = year;
    Address = address;
    Amount = amount;
    Month_name = AddMonth_name(month);
    isYearLeap = checkYearLeap(year);
}

Transaction::Transaction(int day, std::string M_name, int year, std::string address, double amount){
    Day = day;
    Month = AddMonth_number(M_name);
    Month_name = M_name;
    Year = year;
    Address = address;
    Amount = amount;
    isYearLeap = checkYearLeap(year);
}

Transaction::Transaction(Date & date, std::string address, double amount){
    Day = date.Day;
    Month = date.Month;
    Year = date.Year;
    Month_name = date.Month_name;
    Address = address;
    Amount = amount;
}

// Transaction::~Transaction(){
//     std::cout << "Object was removed!" << std::endl;
// }

void Transaction::print_first(){
    std::cout << Day << "/" << Month << "/" << Year << std::endl;
}

void Transaction::print_second(){
    std::cout << Day << " " << Month_name << " " << Year << " " << Address << " " << Amount << std::endl;
}

void Transaction::AddDays(int numberDays){
    if(isYearLeap == 1) Days[1]++;
    int Max = Days[Month-1];
    Day += numberDays;
    while(Day > Max){
        Day -= Max;
        Month++;
        while(Month > 12){
            Month -= 12;
            Year++;
        }
        isYearLeap = checkYearLeap(Year);
        if(isYearLeap == 1) Days[1] = 29;
        else Days[1] = 28;
        Max = Days[Month-1];
        Month_name = AddMonth_name(Month);
    }
}

bool checkYearLeap(int year){
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        return 1;
    }
    else{
        return 0;
    }
}


