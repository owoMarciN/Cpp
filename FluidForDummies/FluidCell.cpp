#include "FluidCell.hpp"

void FluidCell::addDensity(int x, int y, double amount) {
    if (x >= 0 && y >= 0 && x < this->size && y < this->size) {
        int index = this->ix(x, y);
        this->density[index] += amount;
    }
}

void FluidCell::addVelocity(int x, int y, double amountX, double amountY){
    if (x >= 0 && y >= 0 && x < this->size && y < this->size) {
        int index = this->ix(x, y);
        this->Vx[index] += amountX;
        this->Vy[index] += amountY;
    }
}

void FluidCell::set_bounds(int b, double *x) {
    int N = this->size;
    for (int i = 1; i < N-1; i++) {
        x[this->ix(i, 0)] = (b == 2) ? -x[this->ix(i, 1)] : x[this->ix(i, 1)];
        x[this->ix(i, N - 1)] = (b == 2) ? -x[this->ix(i, N - 2)] : x[this->ix(i, N - 2)];
    }

    for (int j = 1; j < N-1; j++) {
        x[this->ix(0, j)] = (b == 1) ? -x[this->ix(1, j)] : x[this->ix(1, j)];
        x[this->ix(N - 1, j)] = (b == 1) ? -x[this->ix(N - 2, j)] : x[this->ix(N - 2, j)];
    }
            
    x[this->ix(0, 0)] = 0.5 * (x[this->ix(1, 0)] + x[this->ix(0, 1)]);
    x[this->ix(0, N-1)] = 0.5 * (x[this->ix(1, N-1)] + x[this->ix(0, N-2)]);
    x[this->ix(N-1, 0)] = 0.5 * (x[this->ix(N-2, 0)] + x[this->ix(N-1, 1)]);
    x[this->ix(N-1, N-1)] = 0.5 * (x[this->ix(N-2, N-1)] + x[this->ix(N-1, N-2)]);
}

void FluidCell::lin_solve(int b, double *x, double *x0, double a, double c) {
    // Solve linear system using Gauss-Seidel iteration
    int N = this->size;
    double cRecip = 1.0 / c;

    for (int k = 0; k < iter_val; k++) {
        for (int j = 1; j < N-1; j++) {
            for (int i = 1; i < N-1; i++) {
                    x[this->ix(i, j)] = (x0[this->ix(i, j)] + a * (
                    x[this->ix(i+1, j)] +
                    x[this->ix(i-1, j)] +
                    x[this->ix(i, j+1)] +
                    x[this->ix(i, j-1)]
                )) * cRecip;
               }
        }
        this->set_bounds(b, x);
    }                
}

void FluidCell::diffuse(int b, double *x, double *x0, double diff, double dt) {
    int N = this->size;
    double a = dt * diff * (N - 2) * (N - 2);
    this->lin_solve(b, x, x0, a, 1 + 4 * a);
}

void FluidCell::project(double *velX, double *velY, double *p, double *div) {
    int N = this->size;
    for (int j = 1; j < N-1; j++) {
        for (int i = 1; i < N-1; i++) {
            div[this->ix(i, j)] = -0.5 * (
                    velX[this->ix(i+1, j)]
                    -velX[this->ix(i-1, j)]
                    +velY[this->ix(i, j+1)]
                    -velY[this->ix(i, j-1)]
                ) / N;
            p[this->ix(i, j)] = 0;
        }
    }

    this->set_bounds(0, div);
    this->set_bounds(0, p);
    this->lin_solve(0, p, div, 1, 4);

    for (int j = 1; j < N-1; j++) {
        for (int i = 1; i < N-1; i++) {
            velX[this->ix(i, j)] -= 0.5 * (p[this->ix(i+1, j)]
                                        -p[this->ix(i-1, j)]) * N;
            velY[this->ix(i, j)] -= 0.5 * (p[this->ix(i, j+1)]
                                        -p[this->ix(i, j-1)]) * N;
        }
    }

    this->set_bounds(1, velX);
    this->set_bounds(2, velY);
}

void FluidCell::advect(int b, double *d, double *d0, double *velX, double *velY, double dt) {
    int N = this->size;
    double dtx = dt * (N - 2);
    double dty = dt * (N - 2);
    for (int j = 1; j < N-1; j++) {
        for (int i = 1; i < N-1; i++) {
            double x = i - dtx * velX[this->ix(i, j)];
            double y = j - dty * velY[this->ix(i, j)];
                
            if (x < 0.5) x = 0.5;
            if (x > float(N) - 1.5) x = float(N) - 1.5;
            if (y < 0.5) y = 0.5;
            if (y > float(N) - 1.5) y = float(N) - 1.5;
            
            int i0 = static_cast<int>(x);
            int i1 = i0 + 1;
            int j0 = static_cast<int>(y);
            int j1 = j0 + 1;

            double s1 = x - i0;
            double s0 = 1.0 - s1;
            double t1 = y - j0;
            double t0 = 1.0 - t1;
                
            d[this->ix(i, j)] = (
                s0 * (t0 * d0[this->ix(i0, j0)] + t1 * d0[this->ix(i0, j1)]) + 
                s1 * (t0 * d0[this->ix(i1, j0)] + t1 * d0[this->ix(i1, j1)])
            );
        }
    }
    this->set_bounds(b, d);
}     
    
void FluidCell::step() {
    this->diffuse(1, this->Vx0, this->Vx, this->visc, this->dt);
    this->diffuse(2, this->Vy0, this->Vy, this->visc, this->dt);
    
    this->project(this->Vx0, this->Vy0, this->Vx, this->Vy);
    
    this->advect(1, this->Vx, this->Vx0, this->Vx0, this->Vy0, this->dt);
    this->advect(2, this->Vy, this->Vy0, this->Vx0, this->Vy0, this->dt);
    
    this->project(this->Vx, this->Vy, this->Vx0, this->Vy0);
    
    this->diffuse(0, this->s, this->density, this->diff, this->dt);
    this->advect(0, this->density, this->s, this->Vx, this->Vy, this->dt);
}  

void FluidCell::fadeDensity(double amount=0.02) {
    int N = this->size;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            int index = this->ix(i, j);
            this->density[index] = std::clamp(this->density[index] - amount, 0.0, 255.0);
        }
    }
}

FluidCell::FluidCell(int N, double dt, double diff, double visc) {
    this->size = N;
    this->dt = dt;
    this->diff = diff;
    this->visc = visc;

    this->s = new double[N * N];
    this->density = new double[N * N];

    this->Vx = new double[N * N];
    this->Vy = new double[N * N];

    this->Vx0 = new double[N * N];
    this->Vy0 = new double[N * N];

    std::fill(this->s, this->s + N * N, 0.0);
    std::fill(this->density, this->density + N * N, 0.0);
    std::fill(this->Vx, this->Vx + N * N, 0.0);
    std::fill(this->Vy, this->Vy + N * N, 0.0);
    std::fill(this->Vx0, this->Vx0 + N * N, 0.0);
    std::fill(this->Vy0, this->Vy0 + N * N, 0.0);
}

FluidCell::~FluidCell() {
    delete[] s;
    delete[] density;
    delete[] Vx;
    delete[] Vy;
    delete[] Vx0;
    delete[] Vy0;
}