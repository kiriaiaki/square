#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "print.h"
#include "solution.h"
#include "auxiliary_function.h"

void Testing()
{
    // TODO: добавить больше тестов и структуры
    OneTest( 1, -5,  6, 2, 3,  2);
    OneTest( 1,  0, -4, 2, 2, -2);
}

void OneTest(const double Definite_A, const double Definite_B, const double Definite_C,
    const int Correct_NRoots, const double Correct_X1, const double Correct_X2)
{
    double Empty_X1 = 0, Empty_X2 = 0;
    int NRoots = 0;
    assert(isfinite(Definite_A));
    assert(isfinite(Definite_B));
    assert(isfinite(Definite_C));
    assert(isfinite(Correct_X1));
    assert(isfinite(Correct_X2));
    NRoots=Solve( Definite_A, Definite_B, Definite_C, &Empty_X1, &Empty_X2);
    if (!( ComparisonDouble(Empty_X1, Correct_X1)
        && ComparisonDouble(Empty_X2, Correct_X2)
        && NRoots == Correct_NRoots))
    {
        printf("Ошибка в тесте!\n"
               "Коэффициенты уравнения: %lg, %lg, %lg \n"
               "Сколько должно было получиться корней: %d \n"
               "Сколько программа получила корней: %d \n"
               "Какие корни должны были получиться: %lg, %lg \n"
               "Какие корни получила программа: %lg, %lg \n\n",
               Definite_A, Definite_B, Definite_C,
               Correct_NRoots, NRoots,
               Correct_X1, Correct_X2, Empty_X1, Empty_X2);
    }

}
