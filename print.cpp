#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

void PrintRoots (const int NSolve, const double X1, const double X2)
{
    if (NSolve == 2)
    {
        assert(isfinite(X1));
        assert(isfinite(X2));
        printf("x1 = %lg;   x2 = %lg\n\n", X1, X2);
    }
    if (NSolve == 1)
    {
        assert(isfinite(X1));
        assert(ComparisonDouble(X1, X2));
        printf("x1 = %lg\n\n", X1);
    }
}

void PrintNumberRoots (const int NSolve)
{
    if (NSolve == INFINITE_ROOTS)
    {
        printf("\n Уравнение имеет бесконечно много корней!\n\n");
    }
    if (NSolve == IMPOSSIBLE_ROOTS)
    {
        printf("\n Уравнение невозможно!\n\n");
    }
    if (NSolve == ONE_ROOT)
    {
        printf("\n Уравнение имеет одно решение!\n\n");
    }
    if (NSolve == TWO_ROOTS)
    {
        printf("\n Уравнение имеет два решения!\n\n");
    }
    if (NSolve == ZERO_ROOTS)
    {
        printf("\n Уравнение не имеет рациональных решений!\n\n");
    }
}

void End(int* const AnsUser)
{
    assert(AnsUser != NULL);
    printf(" Нажми 1, чтобы решить ёще уравнение или нажми 0, чтобы закончить\n");
    scanf("%d", AnsUser);
}
