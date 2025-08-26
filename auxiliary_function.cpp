#include "auxiliary_function.h"

int CompareDouble (const double First, const double Twice)
{
    assert(isfinite(First));
    assert(isfinite(Twice));
    return fabs (First - Twice) < EPSILON;
}
