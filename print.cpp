#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

void PrintRoots (const QuantityRoots NSolve, const double X1, const double X2)
{
    switch (NSolve)
    {
        case TWO_ROOTS:
        {
            assert(isfinite(X1));
            assert(isfinite(X2));
            printf("x1 = %lg;   x2 = %lg\n\n", X1, X2);
            break;
        }
        case ONE_ROOT:
        {
            assert(isfinite(X1));
            assert(ComparisonDouble(X1, X2));
            printf("x1 = %lg\n\n", X1);
            break;
        }
        case INFINITE_ROOTS:
        case IMPOSSIBLE_ROOTS:
        case ZERO_ROOTS:
        case NOT_INITIALIZED:
        default: break;
    }
}

void PrintNumberRoots (const QuantityRoots NSolve)
{
    switch (NSolve)
    {
        case INFINITE_ROOTS: printf("\n Уравнение имеет бесконечно много корней!\n\n"); break;
        case IMPOSSIBLE_ROOTS: printf("\n Уравнение невозможно!\n\n"); break;
        case ONE_ROOT: printf("\n Уравнение имеет одно решение!\n\n"); break;
        case TWO_ROOTS: printf("\n Уравнение имеет два решения!\n\n"); break;
        case ZERO_ROOTS: printf("\n Уравнение не имеет рациональных решений!\n\n"); break;
        case NOT_INITIALIZED:
        default: break;
    }
}

// AskUserIntention
int AskIntention(int* const AnsUser)
{
    assert(AnsUser != NULL);
    printf(" Нажми 1, чтобы решить ёще уравнение или нажми 0, чтобы закончить\n");
    if (CheckAnsUser (AnsUser) == EOF)
    {
        return EOF;
    }
    else
    {
        return SUCCESS;
    }
}
