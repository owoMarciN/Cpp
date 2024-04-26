#include "bill.h"

//How to compile: g++ main.cpp date.cpp transaction.cpp bill.cpp


int main(){
    Transaction trans1(30, "September", 2024, "AGH", -3600);
    trans1.print_second();
    Transaction trans2(10, 8, 2024, "AGH", 1400);
    trans2.print_second();
    Date date_of_trans3(24, "April", 2024);
    Transaction trans3(date_of_trans3, "AGH", -200);
    trans3.print_second();
    std::cout << std::endl;
    
    // CREATING NEW BILL //
    Bill newBill = {"Marcin", "Basisty", 30000};
    newBill.printMoney();

    newBill.Transfer(1, 1, 2025, "GMG", -12000);
    newBill.Transfer(10, 8, 2024, "AGH", 1400);
    newBill.Transfer(24, "September", 2024, "AGH", -3600);
    newBill.Transfer(date_of_trans3, "Leśna-314", 20000);
    newBill.Transfer(trans3);

    newBill.printHistory();
    newBill.printMoney();
    
    return 0;
}
