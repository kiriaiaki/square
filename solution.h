#ifndef SOLUTION_H
#define SOLUTION_H

#include <assert.h>
#include <math.h>

#include "auxiliary_function.h"

enum QuantityRoots
{
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1,
    IMPOSSIBLE_ROOTS = -2,
    NOT_INITIALIZED = -3,
};

QuantityRoots SolveSquareEquation (const double A, const double B, const double C,
    double* const X1, double* const X2);

QuantityRoots SolveEquation (const double A, const double B, const double C,
    double* const X1, double* const X2);

QuantityRoots SolveLinearEquation (const double B, const double C,
    double* const X1, double* const X2);

#endif // SOLUTION_H
