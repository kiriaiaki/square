#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "main.h"
#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"

void PrintRoots (const int nSolve, const double x1, const double x2)
{
    assert(isfinite(x1));
    assert(isfinite(x2));
    if (nSolve == 2)
    {
        printf("x1 = %lg;   x2 = %lg\n\n", x1, x2);
    }
    if (nSolve == 1)
    {
        printf("x1 = %lg\n\n", x1);
    }
}

void PrintNumberRoots (const int nSolve)
{
    if (nSolve == INFINITE_ROOTS)
    {
        printf("\n Уравнение имеет бесконечно много корней!\n\n");
    }
    if (nSolve == IMPOSSIBLE_ROOTS)
    {
        printf("\n Уравнение невозможно!\n\n");
    }
    if (nSolve == ONE_ROOTS)
    {
        printf("\n Уравнение имеет одно решение!\n\n");
    }
    if (nSolve == TWO_ROOTS)
    {
        printf("\n Уравнение имеет два решения!\n\n");
    }
    if (nSolve == ZERO_ROOTS)
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
