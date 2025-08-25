#ifndef SOLUTION_H
#define SOLUTION_H

enum Name {
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1,
    IMPOSSIBLE_ROOTS = -2
};

int SquareEquation (const double A, const double B, const double C,
    double* const X1, double* const X2);
int Solve (const double A, const double B, const double C,
    double* const X1, double* const X2);
int LinearEquation (const double B, const double C,
    double* const X1, double* const X2);

#endif
