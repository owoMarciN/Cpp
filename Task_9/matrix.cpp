#include "matrix.h"

Matrix::Matrix(int n, int m, double i){
    this->n = n;
    this->m = m;
    for(int j = 0; j < n; j++){
        A.push_back(std::vector<double>());
        for(int k = 0; k < m; k++){
            A[j].push_back(i);
        }
    }
}

Matrix::Matrix(std::vector<std::vector<double>> & M){
    this->n = M.size();
    this->m = M[0].size();
    for(int i = 0; i < M.size(); i++){
        A.push_back(std::vector<double>());
        for(int j = 0; j < M[i].size(); j++){
            A[i].push_back(M[i][j]);
        }
    }
}

Matrix::Matrix(Matrix &M){
    this->n = M.n;
    this->m = M.m;
    this->A = M.A;
}

void Matrix::print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }
}