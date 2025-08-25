#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "exampl.h"
#include "test.h"


int TWO_ROOTS = 2;
int ONE_ROOTS = 1;
int ZERO_ROOTS = 0;
int INFINITE_ROOTS = -1;
int IMPOSSIBLE_ROOTS = -2;
int SUCCESS = 3;
double EPSILON = 1e-7;

int main()
{
    printf("Привет!\n"
           "Я программа для нахождения корней квадратного уравнения вида ax^2+bx+c=0\n"
           "Введи коэффициенты:\n\n");
    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;
    int nSolve;
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

int Solve(const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    if (ComparisonDouble(a, 0))
    {
        if (ComparisonDouble(b, 0))
        {
            if (ComparisonDouble(c, 0))
            {
                return -1;
            }
            else
            {
                return -2;
            }
        }
        else
        {
            return LinearEquation(b, c, x1, x2);
        }
    }
    else
    {
        return SquareEquation(a, b, c, x1, x2);

    }
}

int SquareEquation (const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    double D;
    D = b*b - 4*a*c;
    if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2*a);
        *x2 = (-b - sqrt(D)) / (2*a);
        return 2;
    }
    if (ComparisonDouble(D, 0))
    {
        *x1 = *x2 = -b / 2*a;
        return 1;
    }
    else
    {
        return 0;
    }
}

int LinearEquation (const double b, const double c, double* const x1, double* const x2)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    *x1 = *x2 = -c / b;
    return 1;
}
