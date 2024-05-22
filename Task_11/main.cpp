#include "classes.h"

int main(){

    Complex newC1;
    Complex newC2(-12.4, -3.4);
    Complex newC3(3, 60, 1);

    std::cout << newC1.Rel << " " << newC1.Im << ' ' << newC1.Abs() <<'\n';
    std::cout << newC2.Rel << " " << newC2.Im << ' ' << newC2.Abs() << '\n';
    std::cout << newC3.Rel << " " << newC3.Im << '\n';

    Triangle Tri(6, 6, 6);
    Tri.Print();
    return 0;
}