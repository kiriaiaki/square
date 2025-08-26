#ifndef TEST_H
#define TEST_H

#include <assert.h>
#include <stdio.h>

#include "solution.h"
#include "auxiliary_function.h"

struct Test
{
    double A, B, C;
    int NSolve;
    double X1, X2;
};

void OneTest (Test test);

void Testing ();

#endif // TEST_H
