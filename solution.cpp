#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

QuantityRoots Solve(const double A, const double B, const double C,
    double* const X1, double* const X2)
{
    assert(isfinite(A));
    assert(isfinite(B));
    assert(isfinite(C));
    assert(X1 != NULL);
    assert(X2 != NULL);
    if (ComparisonDouble(A, 0))
    {
        if (ComparisonDouble(B, 0))
        {
            if (ComparisonDouble(C, 0))
            {
                return INFINITE_ROOTS;
            }
            else
            {
                return IMPOSSIBLE_ROOTS;
            }
        }
        else
        {
            return LinearEquation(B, C, X1, X2);
        }
    }
    else
    {
        return SquareEquation(A, B, C, X1, X2);

    }
}

QuantityRoots SquareEquation (const double A, const double B, const double C,
    double* const X1, double* const X2)
{
    assert(isfinite(A));
    assert(isfinite(B));
    assert(isfinite(C));
    assert(X1 != NULL);
    assert(X2 != NULL);
    const double D = B*B - 4*A*C;
    if (D > 0)
    {
        const double SqrtD = sqrt(D);
        *X1 = (-B + SqrtD) / (2*A);
        *X2 = (-B - SqrtD) / (2*A);
        return TWO_ROOTS;
    }
    if (ComparisonDouble(D, 0))
    {
        *X1 = *X2 = -B / (2*A);
        return ONE_ROOT;
    }
    else
    {
        return ZERO_ROOTS;
    }
}

QuantityRoots LinearEquation (const double B, const double C,
    double* const X1, double* const X2)
{
    assert(isfinite(B));
    assert(isfinite(C));
    assert(X1 != NULL);
    assert(X2 != NULL);
    *X1 = *X2 = -C / B;
    return ONE_ROOT;
}
