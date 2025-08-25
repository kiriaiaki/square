#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

// InputCoefficients
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

// InputOnlyCoefficient
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

// InputBufferClean
int BufferCleaning ()
{
    while (1)
    {
        int Symbol = getchar();
        if (Symbol == EOF)
        {
            return EOF;
        }
        else if (Symbol == (int)'\n')
        {
            return SUCCESS;
        }
    }
}

// InputIntentionChecked
int CheckAnsUser (int* const AnsUser)
{
    assert(AnsUser != NULL);
    while (1)
    {
        if (scanf("%d", AnsUser) != 1)
        {
            if (BufferCleaning () == EOF)
            {
                return EOF;
            }
            printf("Введи 0 или 1, попробуй ещё раз\n");
        }
        else
        {
            if (*AnsUser == 1 || *AnsUser == 0)
            {
                return SUCCESS;
            }
            else
            {
                printf("Введи 0 или 1, попробуй ещё раз\n");

            }
        }
          // if (scanf("%d", AnsUser) == 1)
        // {
        //     printf("Введи 0 или 1, попробуй ещё раз\n");
        //     continue;
    }
    return SUCCESS;
}
