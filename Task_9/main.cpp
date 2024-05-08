#include "date.h"
#include "matrix.h"

int main(){

    Date d1;
    d1.print();

    Date d2(123);
    d2.print();

    Date d3(12, 2, 12, 15, 45, 34);
    d3.print();

    Date d4(d2);
    d4.print();

    d1 = d2;
    d1.print();

    // Matrix M1;
    // M1.print();

    Matrix M2(3, 3, 4.5);
    M2.print();

    Matrix M3({{1, 3}, {1, 3}});
    M3.print();

    return 0;
}