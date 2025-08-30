/**
 * @file test.h
 * @author kiriaiaki@domain.com
 * @brief Заголовочный файл с функциями тестирования программы
 */

#ifndef TEST_H
#define TEST_H

#include <assert.h>
#include <stdio.h>

#include "solution.h"
#include "auxiliary_function.h"

/// Структура для ввода тестируемых значений
struct Test
{
    double A, B, C; ///< Коэффициенты квадратного уравнения
    int NSolve; ///< Количество корней, которое должна получить программе при данных коэффициентах
    double X1, X2; ///< Корни, которые должна получить программа при данных коэффициентах
};

/**
 * @brief Функция для тестирования одного набора значений, вызывается о структуры значений
 *
 * @param test структура Test, содержащая коэффициенты и решения квадратного уравнения
 */
void OneTest (Test test);

/**
 * @brief Функция для множественного вызова функции OneTest
 */
void Testing ();

#endif // TEST_H
