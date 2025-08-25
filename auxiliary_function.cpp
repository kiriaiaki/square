#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

int ComparisonDouble(const double First, const double Twice)
{
    assert(isfinite(First));
    assert(isfinite(Twice));
    if (fabs(First - Twice) < EPSILON)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
