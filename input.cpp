#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "example.h"
#include "test.h"
#include "input.h"

int InputValues (double* const a, double* const b, double* const c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    printf("a: ");
    if (CheckInput(a, 'a') == EOF)
    {
        return EOF;
    }
    printf("b: ");
    if (CheckInput(b, 'b') == EOF)
    {
        return EOF;
    }
    printf("c: ");
    if (CheckInput(c, 'c') == EOF)
    {
        return EOF;
    }
    return SUCCESS;
}

int CheckInput(double* const Coefficient, const char c)
{
    assert(Coefficient != NULL);
    while (scanf("%lf", Coefficient) != 1)
    {
        if (BufferCleaning () == EOF)
        {
            return EOF;
        }
        printf("Можно вводить только цифры, попробуй ещё раз\n%c: ", c);
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
