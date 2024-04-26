#ifndef TRANSACTION_H
#define TRANSACTION_H

// FILE WITH DATE CLASS DEFINITION //
#include "date.h"

// CLASS //
class Transaction{
public:
    int Day;
    int Month;
    int Year;
    std::string Month_name;
    double Amount;

    // TREE TYPES OF CONSTRUCTORS //
    Transaction(int day, int month, int year, std::string address, double amount);
    Transaction(int day, std::string M_name, int year, std::string address, double amount);
    Transaction(Date & date, std::string address, double amount);

    void AddDays(int numberDays);
    void print_first();
    void print_second();
    //~Transaction();
private:
    bool isYearLeap;
    std::string Address;
};

// ADDITIONAL FUNCTION DECLARATION //
bool checkYearLeap(int year);

#endif