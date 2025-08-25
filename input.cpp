#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

int InputValues (double* const A, double* const B, double* const C)
{
    assert(A != NULL);
    assert(B != NULL);
    assert(C != NULL);
    if (CheckInput(A, 'a') == EOF)
    {
        return EOF;
    }
    if (CheckInput(B, 'b') == EOF)
    {
        return EOF;
    }
    if (CheckInput(C, 'c') == EOF)
    {
        return EOF;
    }
    return SUCCESS;
}

int CheckInput(double* const Coefficient, const char Symbol)
{
    assert(Coefficient != NULL);
    printf("%c: ", Symbol);
    while (scanf("%lf", Coefficient) != 1)
    {
        if (BufferCleaning () == EOF)
        {
            return EOF;
        }
        printf("Можно вводить только цифры, попробуй ещё раз\n%c: ", Symbol);
    }
    return SUCCESS;
}

int BufferCleaning ()
{
    while (1)
    {
        int Symbol = getchar();
        if (Symbol == -1)
        {
            return EOF;
        }
        else if (Symbol == int('\n'))
        {
            return SUCCESS;
        }
    }
}
