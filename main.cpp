#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "main.h"
#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"

int main()
{
    printf("Привет!\n"
           "Я программа для нахождения корней квадратного уравнения вида ax^2+bx+c=0\n"
           "Введи коэффициенты:\n\n");
    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;
    int nSolve = 3;
    int AnsUser = 1;
    while (AnsUser != 0)
    {
        if (InputValues(&a, &b, &c) == EOF)
        {
            break;
        }
        nSolve = Solve(a, b, c, &x1, &x2);
        PrintNumberRoots(nSolve);
        PrintRoots(nSolve, x1, x2);
        End(&AnsUser);
    }
    printf("Пока!\n\n");
    Testing();
    return 0;
}

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
