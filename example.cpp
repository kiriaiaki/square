#include <assert.h>
#include <stdio.h>
#include <math.h>

int Solve( const double a, const double b, const double c, double* x1, double* x2);
int LinearEquation ( const double b, const double c, double* x1, double* x2);
int SquareEquation ( const double a, const double b, const double c, double* x1, double* x2);
int ComparisonDouble( const double First, const double Twice);
void OneTest( const double Definite_a, const double Definite_b, const double Definite_c, const int Correct_nRoots, const double Correct_x1, const double Correct_x2);
void PrintNumberRoots ( const int nSolve);
void InputValues ( double* a, double* b, double* c);
void End (int* AnsUser);
void PrintRoots ( const int nSolve, const double x1, const double x2);
void CheckInput( double* Coefficient, char c);
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
        InputValues(&a, &b, &c);
        nSolve = Solve(a, b, c, &x1, &x2);
        PrintNumberRoots(nSolve);
        PrintRoots(nSolve, x1, x2);
        End(&AnsUser);
    }
    printf("Пока!\n\n");
    return 0;
}

void PrintRoots ( const int nSolve, const double x1, const double x2)
{
    if (nSolve == 2)
    {
        printf("x1 = %lg;   x2 = %lg\n\n", x1, x2);
    }
    if (nSolve == 1)
    {
        printf("x1 = %lg\n\n", x1);
    }
}

void InputValues ( double* a, double* b, double* c)
{
    // assert(a != 0);
    printf("a: ");
    CheckInput(a, 'a');
    printf("b: ");
    CheckInput(b, 'b');
    printf("c: ");
    CheckInput(c, 'c');
}

void CheckInput( double* Coefficient, char c)
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

void End(int* AnsUser)
{
    printf(" Нажми 1, чтобы решить ёще уравнение или нажми 0, чтобы закончить\n");
    scanf("%d", AnsUser);
}

void Testing()
{
    //Нужно вводить корни в порядке убывания;(
    OneTest( 1, -5, 6, 2, 3, 2);
    OneTest( 1, 0, -4, 2, 2, -2);
}

void OneTest( const double Definite_a, const double Definite_b, const double Definite_c, const int Correct_nRoots, const double Correct_x1, const double Correct_x2)
{
    double Empty_x1 = 0, Empty_x2 = 0;
    int nRoots = 0;
    nRoots=Solve( Definite_a, Definite_b, Definite_c, &Empty_x1, &Empty_x2);
    if (!( ComparisonDouble( Empty_x1, Correct_x1) == 1 && ComparisonDouble( Empty_x2, Correct_x2) == 1 && nRoots == Correct_nRoots))
    {
        printf("Ошибка в тесте!\nКоэффициенты уравнения: %lg, %lg, %lg \nСколько должно было получиться корней: %d \nСколько программа получила корней: %d \nКакие корни должны были получиться: %lg, %lg \nКакие корни получила программа: %lg, %lg \n\n", Definite_a, Definite_b, Definite_c, Correct_nRoots, nRoots, Correct_x1, Correct_x2, Empty_x1, Empty_x2);
    }

}

int ComparisonDouble( const double First, const double Twice)
{
    if (fabs(First - Twice) < EPSILON)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Solve( const double a, const double b, const double c, double* x1, double* x2)
{
    if (ComparisonDouble( a, 0) == 1)
    {
        if (ComparisonDouble( b, 0) == 1)
        {
            if (ComparisonDouble( c, 0) == 1)
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

int SquareEquation ( const double a, const double b, const double c, double* x1, double* x2)
{
    double D;
    D = b*b - 4*a*c;
    if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2*a);
        *x2 = (-b - sqrt(D)) / (2*a);
        return 2;
    }
    if (ComparisonDouble( D, 0) == 1)
    {
        *x1 = *x2 = -b / 2*a;
        return 1;
    }
    else
    {
        return 0;
    }
}

int LinearEquation ( const double b, const double c, double* x1, double* x2)
{
    *x1 = *x2 = -c / b;
    return 1;
}

