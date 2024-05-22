#include "classes.h"

Complex::Complex():Rel(0), Im(0){};

Complex::Complex(double r, double i){
    this->Rel = r;
    this->Im = i;
}

Complex::Complex(double abs_z, double angle, bool polar){
    this->Rel = abs_z*cos(angle);
    this->Im = abs_z*sin(angle);
}

Complex::~Complex(){

}

double Complex::Abs(){
    return sqrt((Rel*Rel) + (Im*Im));
}

double Complex::Alpha(){
    return 0; //dokończyc chodzi o kąt
}

Triangle::Triangle() : A(6), B(6), C(6), Alpha(60), Beta(60), Gamma(60){};

Triangle::Triangle(int a, int b, int c){
    A = a;
    B = b;
    C = c;
    Alpha = acos(((a*a) + (b*b) - (c*c))/2*a*b);
    Beta = acos(((b*b) + (c*c) - (a*a))/2*b*c);
    Gamma = 180 - Alpha - Gamma;
}

void Triangle::Print(){
    std::cout << Alpha << ' ' << Beta << ' ' << Gamma << '\n';
}

Triangle::Triangle(double al, double be, double ga){
    Alpha = al;
    Beta = be;
    Gamma = ga;
}

Triangle::~Triangle(){

}

Event::Event(double x_0, double t_0){
    this->x = x_0;
    this->t = t_0;
}

Event::~Event(){

}

// Event::operator<(Event &T1, Event &T2){

// }

// Event::operator>(Event &T1, Event &T2){

// }