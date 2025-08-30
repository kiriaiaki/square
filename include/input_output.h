/**
 * @file input_output.h
 * @author kiriaiaki@domain.com
 * @brief Заголовочный файл с функциями ввода и вывода
 */

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <assert.h>
#include <stdio.h>

#include "solution.h"
#include "auxiliary_function.h"

/**
 * @brief  Функция для вывода корней квадратного уравнения, если корень всего один, то функция выведет один корень, если корней нет, функция ничего не выведет

 *
 * @param NSolve Количество корней квадратного уравнения
 * @param X1 Первый корень квадратного уравнения X1
 * @param X2 Второй корень квадратного уравнения X2
 */
void PrintRoots (const QuantityRoots NSolve, const double X1, const double X2);

/**
 * @brief  Функция для ввода коэффициентов a, b и c квадратного уравнения
 *
 * @param A Указатель на ячейку памяти, где хранится переменная A - параметр квадратного уравнения при x^2
 * @param B Указатель на ячейку памяти, где хранится переменная B - параметр квадратного уравнения при x
 * @param C Указатель на ячейку памяти, где хранится переменная C - свободный член квадратного уравнения (при x^0)
 * @return EOF в случае ошибки или SUCCESS в случае успешного ввода
 */
int InputCoefficients (double* const A, double* const B, double* const C);

/**
 * @brief Функция для проверки ввода коэффициентов, что бы пользователь вводил только численные значения коэффициентов (а не буквы и прочие символы),
 в ином случае функция попросит заново ввести коэффициент
 *
 * @param Coefficient Указатель на ячейку памяти, где хранится переменная Coefficient - коэффициент квадратного уравнения
 * @param Symbol Переменная означающая название коэффициента, который сейчас вводит пользователь
 * @return EOF в случае ошибки или SUCCESS в случае успешного ввода
*/
int InputOnlyCoefficient (double* const Coefficient, const char Symbol);

/**
 * @brief  Функция для вывода количества корней квадратного уравнения
 *
 * @param NSolve Переменная NSolve - количество корней квадратного уравнения
 */
void PrintNumberRoots (const QuantityRoots NSolve);

/**
 * @brief Функция для проверки ввода ответа пользователя, что бы ответ был 1 или 0,
 в ином случае, функция попросит заново ввести ответ
 *
 * @param AnsUser Указатель на переменную AnsUser - содержащую ответ пользователя
 * @return EOF в случае ошибки или SUCCESS в случае успешного ввода

 */
int InputIntentionChecked (int* const AnsUser);

/**
 * @brief Функция для вызова ввода ответа пользователя
 *
 * @param AnsUser Указатель на переменную AnsUser - содержащую ответ пользователя
 * @return EOF в случае ошибки или SUCCESS в случае успешного ввода
 */
int AskUserIntention (int* const AnsUser);

/**
 * @brief Функция для очистки буфера ввода в случае неправильного ввода
 *
 * @return EOF в случае ошибки или SUCCESS в случае успешного ввода
 */
int InputBufferClean ();

#endif // INPUT_OUTPUT_H
