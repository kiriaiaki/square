#include <assert.h>
#include <stdio.h>
#include <math.h>

int Solve(double a, double b, double c, double* x1, double* x2);
int LinearEquation (double b, double c, double* x1, double* x2);
int SquareEquation (double a, double b, double c, double* x1, double* x2);
int OneTest( double Definite_a, double Definite_b, double Definite_c, int Correct_nRoots, double Correct_x1, double Correct_x2);
void PrintNumberRoots (int nSolve);
void InputValues (double* a, double* b, double* c);
void End (int* AnsUser);
void PrintRoots (int nSolve, double x1, double x2);
void CheckInput(double* Coefficient, char c);
void BufferCleaning ();
void Testing();

int TWO_ROOTS = 2;
int ONE_ROOTS = 1;
int ZERO_ROOTS = 0;
int INFINITE_ROOTS = -1;
int IMPOSSIBLE_ROOTS = -2;
double EPSILON = 1e-7;

int main()
{
    printf("Привет!\n Я программа для нахождения корней квадратного уравнения вида ax^2+bx+c=0\n Введи коэффициенеты:\n\n");
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int nSolve;
    int AnsUser=1;
    while (AnsUser != 0)
    {
        InputValues(0, &b, &c);
        nSolve = Solve(a, b, c, &x1, &x2);
        PrintNumberRoots(nSolve);
        PrintRoots(nSolve, x1, x2);
        End(&AnsUser);
    }
    printf("Пока!\n");
    return 0;
}

void PrintRoots (int nSolve, double x1, double x2)
{
    if (nSolve == 2)
    {
        printf("x1 = %lg x2 = %lg\n\n", x1, x2);
    }
    if (nSolve == 1)
    {
        printf("x1 = %lg\n\n", x1);
    }
}

void InputValues (double* a, double* b, double* c)
{
    // assert(a != 0);
    printf("a: ");
    CheckInput(a, 'a');
    printf("b: ");
    CheckInput(b, 'b');
    printf("c: ");
    CheckInput(c, 'c');
}

void CheckInput(double* Coefficient, char c)
{
    while (scanf("%lf", Coefficient) != 1)
    {
        BufferCleaning ();
        printf("Можно вводить только цифры, попробуй ещё раз\n%c: ", c);
    }
}

void BufferCleaning ()
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void PrintNumberRoots (int nSolve)
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

void End(int* AnsUser)
{
    printf(" Нажми 1, чтобы решить ёще уравнение или нажми 0, чтобы закончить\n");
    scanf("%d", AnsUser);
}

void Testing()
{
    printf("%d\n", OneTest( 1, -5, 6, 2, 3, 2));
    printf("%d\n", OneTest( 1, 0, -4, 2, 2, -2));
}

int OneTest( double Definite_a, double Definite_b, double Definite_c, int Correct_nRoots, double Correct_x1, double Correct_x2)
{
    double Empty_x1 = 0, Empty_x2 = 0;
    int nRoots = 0;
    nRoots=Solve( Definite_a, Definite_b, Definite_c, &Empty_x1, &Empty_x2);
    if ( fabs(Empty_x1 - Correct_x1) < EPSILON && fabs(Empty_x2 - Correct_x2) < EPSILON && nRoots == Correct_nRoots)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int Solve( double a, double b, double c, double* x1, double* x2)
{
    if (fabs(a) < EPSILON)
    {
        if (fabs(b) < EPSILON)
        {
            if (fabs(c) < EPSILON)
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

int SquareEquation (double a, double b, double c, double* x1, double* x2)
{
    double D;
    D = b*b - 4*a*c;
    if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2*a);
        *x2 = (-b - sqrt(D)) / (2*a);
        return 2;
    }
    if (fabs(D) < EPSILON)
    {
        *x1 = *x2 = -b / 2*a;
        return 1;
    }
    else
    {
        return 0;
    }
}

int LinearEquation (double b, double c, double* x1, double* x2)
{
    *x1 = *x2 = -c / b;
    return 1;
}

