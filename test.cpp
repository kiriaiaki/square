#include "exampl.h"
#include "test.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

void Testing()
{
    //Нужно вводить корни в порядке убывания;(
    OneTest( 1, -5,  6, 2, 2,  3);
    OneTest( 1,  0, -4, 2, 2, -2);
    OneTest( 1,  0, -4, 2, -2, 2);
}

void OneTest(const double Definite_a, const double Definite_b, const double Definite_c,
    const int Correct_nRoots, const double Correct_x1, const double Correct_x2)
{
    double Empty_x1 = 0, Empty_x2 = 0;
    int nRoots = 0;
    assert(isfinite(Definite_a));
    assert(isfinite(Definite_b));
    assert(isfinite(Definite_c));
    assert(isfinite(Correct_x1));
    assert(isfinite(Correct_x2));
    nRoots=Solve( Definite_a, Definite_b, Definite_c, &Empty_x1, &Empty_x2);
    if (!( ComparisonDouble(Empty_x1, Correct_x1) && ComparisonDouble(Empty_x2, Correct_x2) && nRoots == Correct_nRoots))
    {
        printf("Ошибка в тесте!\n"
               "Коэффициенты уравнения: %lg, %lg, %lg \n"
               "Сколько должно было получиться корней: %d \n"
               "Сколько программа получила корней: %d \n"
               "Какие корни должны были получиться: %lg, %lg \n"
               "Какие корни получила программа: %lg, %lg \n\n",
               Definite_a, Definite_b, Definite_c,
               Correct_nRoots, nRoots, Correct_x1,
               Correct_x2, Empty_x1, Empty_x2);
    }

}
