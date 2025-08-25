#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "main.h"
#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"

int Solve(const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    if (ComparisonDouble(a, 0))
    {
        if (ComparisonDouble(b, 0))
        {
            if (ComparisonDouble(c, 0))
            {
                return -1;
            }
            else
            {
                return -2;
            }
        }
        else
        {
            return LinearEquation(b, c, x1, x2);
        }
    }
    else
    {
        return SquareEquation(a, b, c, x1, x2);

    }
}

int SquareEquation (const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    double D;
    D = b*b - 4*a*c;
    if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2*a);
        *x2 = (-b - sqrt(D)) / (2*a);
        return 2;
    }
    if (ComparisonDouble(D, 0))
    {
        *x1 = *x2 = -b / 2*a;
        return 1;
    }
    else
    {
        return 0;
    }
}

int LinearEquation (const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    *x1 = *x2 = -c / b;
    return 1;
}
