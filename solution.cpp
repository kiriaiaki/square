#include "solution.h"

QuantityRoots SolveEquation (const double A, const double B, const double C,
    double* const X1, double* const X2)
{
    assert(isfinite(A));
    assert(isfinite(B));
    assert(isfinite(C));
    assert(X1 != NULL);
    assert(X2 != NULL);
    if (CompareDouble (A, 0))
    {
        if (CompareDouble (B, 0))
        {
            if (CompareDouble (C, 0))
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
            return SolveLinearEquation (B, C, X1, X2);
        }
    }
    else
    {
        return SolveSquareEquation (A, B, C, X1, X2);

    }
}

QuantityRoots SolveSquareEquation (const double A, const double B, const double C,
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
    if (CompareDouble (D, 0))
    {
        *X1 = *X2 = -B / (2*A);
        return ONE_ROOT;
    }
    else
    {
        return ZERO_ROOTS;
    }
}

QuantityRoots SolveLinearEquation (const double B, const double C,
    double* const X1, double* const X2)
{
    assert(isfinite(B));
    assert(isfinite(C));
    assert(X1 != NULL);
    assert(X2 != NULL);
    *X1 = *X2 = -C / B;
    return ONE_ROOT;
}
