#ifndef FLUID_CELL_H_
#define FLUID_CELL_H_

#include <cmath>
#include <iostream>
#include <algorithm>

// --- Always check ---
// width / N = SCALE

// --- Here ---
// 640 / 128 = 5
static const int width = 640, height = 640;
static const int N = 128;
static const int SCALE = 5;
static const int iter_val = 4;

class FluidCell {
    public:

        int size;
        double dt;
        double diff;
        double visc;

        double *s;
        double *density;

        double *Vx;
        double *Vy;

        double *Vx0;
        double *Vy0;

    public:

        inline int ix(int x, int y) const {
            return (x + (y * this->size));
        }

        void addDensity(int x, int y, double amount);

        void addVelocity(int x, int y, double amountX, double amountY);

        void set_bounds(int b, double *x);

        void lin_solve(int b, double *x, double *x0, double a, double c);

        void diffuse(int b, double *x, double *x0, double diff, double dt);

        void project(double *velX, double *velY, double *p, double *div);

        void advect(int b, double *d, double *d0, double *velX, double *velY, double dt);
            
        void step();
        
        void fadeDensity(double amount);

        FluidCell(int N, double dt, double diff, double visc);

        ~FluidCell();
};


#endif
