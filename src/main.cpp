#include <stdio.h>

#include "test.h"
#include "input_output.h"
#include "solution.h"

int main ()
{
    printf ("Привет!\n"
           "Я программа для нахождения корней квадратного уравнения вида ax^2+bx+c=0\n"
           "Введи коэффициенты:\n\n");

    double A = NAN, B = NAN, C = NAN;
    double X1 = NAN, X2 = NAN;

    QuantityRoots NSolve = NOT_INITIALIZED;
    int AnsUser = -1;

    while (AnsUser != 0)
    {
        if (InputCoefficients (&A, &B, &C) == EOF)
        {
            printf ("\nПока!\n\n");
            return EOF;
        }

        NSolve = SolveEquation (A, B, C, &X1, &X2);
        PrintNumberRoots (NSolve);
        PrintRoots (NSolve, X1, X2);

        printf (" Нажми 1, чтобы решить ёще уравнение или нажми 0, чтобы закончить\n");
        if (AskUserIntention (&AnsUser) == EOF)
        {
            printf ("\nПока!\n\n");
            return EOF;
        }
    }

    printf (" Нажми 1, если хочешь запустить тесты или нажми 0, чтобы закончить выполнение программы\n");
    AskUserIntention (&AnsUser);
    if (AnsUser == 1)
    {
        Testing ();
        printf ("\nТестирование завершено!\n");
    }
    printf ("\nПока!\n\n");

    return 0;
}
