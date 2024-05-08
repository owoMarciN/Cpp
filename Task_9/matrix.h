#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>

class Matrix{
private:

    int n, m;
    std::vector<std::vector<double>> A;

public:

    Matrix();
    Matrix(int n, int m, double i);
    Matrix(std::vector<std::vector<double>> & M);
    Matrix(Matrix &M);
    Matrix &operator=(Matrix &M);

public:
    
    double Trace();
    void Transpose();
    void print();

    Matrix operator +(const Matrix &M);
    Matrix operator *(const Matrix &M);

};

#endif