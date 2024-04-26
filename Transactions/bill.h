#ifndef BILL_H
#define BILL_H

// FILE WITH DEFINITION OF TRANSACTION CLASS //
#include "transaction.h"
#include <vector>

// CLASS //
class Bill{
public:
    std::string Name;
    std::string Surname;
    double TotalAmount;
    std::vector<Transaction> TransArray;

    // FOUR DIFFERENT TRANSFER FUNCTIONS //
    void Transfer(int day, int month, int year, std::string address, double amount);
    void Transfer(int day, std::string M_name, int year, std::string address, double amount);
    void Transfer(Date & date, std::string address, double amount);
    void Transfer(Transaction & Trans);

    void printMoney();
    void printHistory();
};

#endif