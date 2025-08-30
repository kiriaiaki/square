/**
 * @file auxiliary_function.h
 * @author kiriaiaki@domain.com
 * @brief Заголовочный файл с вспомогательными функциями и константами
 */

#ifndef AUXILIARY_FUNCTION_H
#define AUXILIARY_FUNCTION_H

#include <assert.h>
#include <math.h>

/// @brief Константа равная примерной погрешности вычислений
const double EPSILON = 1e-7;
/// @brief Константа для функций возвращающих int, возвращаемая в случае успеха
const int SUCCESS = 3;

/**
 * @brief Функция смотрит равны ли два числа типа double в пределах погрешности, за погрешность взята константа EPSILON
 *
 * @param First Первое число
 * @param Twice Второе число
 * @return 0 - если числа не равны, 1 - если равны
 */
int CompareDouble (const double First, const double Twice);

#endif // AUXILIARY_FUNCTION_H

