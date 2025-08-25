#ifndef SOLUTION_H
#define SOLUTION_H

enum QuantityRoots {
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1,
    IMPOSSIBLE_ROOTS = -2,
    NOT_INITIALIZED = -3,
};

// SolveSquareEquation
QuantityRoots SquareEquation (const double A, const double B, const double C,
    double* const X1, double* const X2);
// SolveEquation
QuantityRoots Solve (const double A, const double B, const double C,
    double* const X1, double* const X2);
// SolveLinearEquation
QuantityRoots LinearEquation (const double B, const double C,
    double* const X1, double* const X2);

#endif
