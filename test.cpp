#include "test.h"

void Testing ()
{
    Test tests [6] =
    {
        {.A = 345,  .B = 2,          .C = 12,     .NSolve = ZERO_ROOTS,       .X1 = 0,          .X2 = 0             },
        {.A = 12.5, .B = 2345.87654, .C = 76.693, .NSolve = TWO_ROOTS,        .X1 = -0.0326984, .X2 = -187.6374248  },
        {.A = 3,    .B = 6,          .C = 3,      .NSolve = ONE_ROOT,         .X1 = -1,         .X2 = -1            },
        {.A = 1,    .B = -5,         .C = 6,      .NSolve = TWO_ROOTS,        .X1 = 3,          .X2 = 2             },
        {.A = 0,    .B = 0,          .C = 0,      .NSolve = INFINITE_ROOTS,   .X1 = 0,          .X2 = 0             },
        {.A = 0,    .B = 0,          .C = 4,      .NSolve = IMPOSSIBLE_ROOTS, .X1 = 0,          .X2 = 0             },
    };

    const int len = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < len; i++)
    {
        OneTest (tests[i]);
    }
}

void OneTest (const Test test)
{
    double Empty_X1 = 0, Empty_X2 = 0;
    QuantityRoots NRoots = NOT_INITIALIZED;

    assert (isfinite (test.A));
    assert (isfinite (test.B));
    assert (isfinite (test.C));
    assert (isfinite (test.X1));
    assert (isfinite (test.X2));

    NRoots = SolveEquation (test.A, test.B, test.C, &Empty_X1, &Empty_X2);

    // printf ("lala %lg\n", fabs (Empty_X1 - test.X1));
    // printf ("lala2 %lg\n", fabs (Empty_X2 - test.X2));

    if (!( CompareDouble (Empty_X1, test.X1)
        && CompareDouble (Empty_X2, test.X2)
        && NRoots == test.NSolve))
    {
        printf ("\nОшибка в тесте!\n"
               "Коэффициенты уравнения: %lg, %lg, %lg \n"
               "Сколько должно было получиться корней: %d \n"
               "Сколько программа получила корней: %d \n"
               "Какие корни должны были получиться: %lg, %lg \n"
               "Какие корни получила программа: %lg, %lg \n\n",
               test.A, test.B, test.C,
               test.NSolve, NRoots,
               test.X1, test.X2, Empty_X1, Empty_X2);
    }

}
