#include "input_output.h"

int InputCoefficients (double* const A, double* const B, double* const C)
{
    assert (A != NULL);
    assert (B != NULL);
    assert (C != NULL);

    if (InputOnlyCoefficient (A, 'a') == EOF)
    {
        return EOF;
    }

    if (InputOnlyCoefficient (B, 'b') == EOF)
    {
        return EOF;
    }

    if (InputOnlyCoefficient (C, 'c') == EOF)
    {
        return EOF;
    }

    return SUCCESS;
}

int InputOnlyCoefficient (double* const Coefficient, const char Symbol)
{
    assert (Coefficient != NULL);

    printf ("%c: ", Symbol);

    while (scanf ("%lf", Coefficient) != 1)
    {
        if (InputBufferClean () == EOF)
        {
            return EOF;
        }

        printf ("Можно вводить только цифры, попробуй ещё раз\n%c: ", Symbol);
    }
    return SUCCESS;
}

int InputBufferClean ()
{
    while (1)
    {
        int Symbol = getchar ();

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

int InputIntentionChecked (int* const AnsUser)
{
    assert (AnsUser != NULL);

    while (1)
    {
        if (scanf ("%d", AnsUser) != 1)
        {
            if (InputBufferClean () == EOF)
            {
                return EOF;
            }

            printf ("Введи 0 или 1, попробуй ещё раз\n");
        }

        else
        {
            if (*AnsUser == 1 || *AnsUser == 0)
            {
                return SUCCESS;
            }

            else
            {
                printf ("Введи 0 или 1, попробуй ещё раз\n");
            }
        }
    }
    return SUCCESS;
}

void PrintRoots (const QuantityRoots NSolve, const double X1, const double X2)
{
    switch (NSolve)
    {
        case TWO_ROOTS:
        {
            assert (isfinite (X1));
            assert (isfinite (X2));

            printf ("x1 = %lg;   x2 = %lg\n\n", X1, X2);
            break;
        }
        case ONE_ROOT:
        {
            assert (isfinite (X1));
            assert (CompareDouble (X1, X2));

            printf ("x1 = %lg\n\n", X1);
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
        case INFINITE_ROOTS:
            printf ("\n Уравнение имеет бесконечно много корней!\n\n");
            break;

        case IMPOSSIBLE_ROOTS:
            printf ("\n Уравнение невозможно!\n\n");
            break;

        case ONE_ROOT:
            printf ("\n Уравнение имеет одно решение!\n\n");
            break;

        case TWO_ROOTS:
            printf ("\n Уравнение имеет два решения!\n\n");
            break;

        case ZERO_ROOTS:
            printf ("\n Уравнение не имеет рациональных решений!\n\n");
            break;

        case NOT_INITIALIZED:

        default:
            break;
    }
}

int AskUserIntention (int* const AnsUser)
{
    assert (AnsUser != NULL);

    if (InputIntentionChecked (AnsUser) == EOF)
    {
        return EOF;
    }

    else
    {
        return SUCCESS;
    }
}
