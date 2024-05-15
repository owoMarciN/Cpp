#include "member.h"

int main(){

    Member newM(2010, "Ania");
    newM.YearChange(2020);
    Member newM2;
    newM2 = newM;
    newM2.printName("Moris");
    std::cout << '\n';
    Member newM3(newM2);

    Population Popek;
    Popek.Add(newM);
    Popek.Add(newM2);
    Popek.Add(newM3);

    Popek.YearChange(2030);
    PrintPop(Popek);
    return 0;
}