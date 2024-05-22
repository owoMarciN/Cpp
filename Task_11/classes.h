#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>
#include <cmath>

class Complex{
public:

    double Rel;
    double Im;
    bool polar;

public:

    Complex();
    Complex(double r, double i);
    Complex(double abs_z, double angle, bool polar);
    ~Complex();

    double Abs();
    double Alpha();

};

class Triangle{
private:

    int A;
    int B;
    int C;

    double Alpha;
    double Beta;
    double Gamma;

public:

    Triangle();
    Triangle(int a, int b, int c);
    Triangle(double al, double be, double ga);
    ~Triangle();
    void Print();

};

class Event{
public:

    double x;
    double t;

public:

    Event():x(0), t(0){};
    Event(double x_0, double t_0);
    ~Event();

    // operator<(Event &T1, Event &T2);
    // operator>(Event &T1, Event &T2);

};

#endif