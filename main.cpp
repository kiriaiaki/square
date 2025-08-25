#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

int main()
{
    printf("Привет!\n"
           "Я программа для нахождения корней квадратного уравнения вида ax^2+bx+c=0\n"
           "Введи коэффициенты:\n\n");
    double A = NAN, B = NAN, C = NAN;
    double X1 = NAN, X2 = NAN;
    int NSolve = INITIALIZATIONNSOLVE;
    int AnsUser = 1;
    while (AnsUser != 0)
    {
        if (InputValues(&A, &B, &C) == EOF)
        {
            break;
        }
        NSolve = Solve(A, B, C, &X1, &X2);
        PrintNumberRoots(NSolve);
        PrintRoots(NSolve, X1, X2);
        End(&AnsUser);
    }
    printf(" Нажми 1, если хочешь запустить тесты или нажми 0, чтобы закончить выполнение программы\n");
    scanf("%d", &AnsUser);
    if (AnsUser == 1)
    {
        Testing();
    }
    printf("\nПока!\n\n");
    return 0;
}
