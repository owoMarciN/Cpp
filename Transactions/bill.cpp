#include "bill.h"

void Bill::Transfer(int day, int month, int year, std::string address, double amount){
    Transaction newTrans(day, month, year, address, amount);
    TransArray.push_back(newTrans);
    TotalAmount += amount;
}
void Bill::Transfer(int day, std::string M_name, int year, std::string address, double amount){
    Transaction newTrans(day, M_name, year, address, amount);
    TransArray.push_back(newTrans);
    TotalAmount += amount;
}

void Bill::Transfer(Date & date, std::string address, double amount){
    Transaction newTrans(date, address, amount);
    TransArray.push_back(newTrans);
    TotalAmount += amount;
}

void Bill::Transfer(Transaction & Trans){
    TransArray.push_back(Trans);
    TotalAmount += Trans.Amount;
}

void Bill::printMoney(){
        std::cout << "Account status: " << TotalAmount << std::endl;
}

void Bill::printHistory(){
    std::cout << "Transaction history:" << std::endl;
    if(TransArray.size() == 0)
        std::cout << "There's no transactions archived!" << std::endl;
    else{
        for(int i = 0; i < TransArray.size(); i++){
            TransArray[i].print_first();
            std::cout << "Amount: " << TransArray[i].Amount << std::endl;
        }
    }
}

