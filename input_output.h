#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <assert.h>
#include <stdio.h>

#include "solution.h"
#include "auxiliary_function.h"

void PrintRoots (const QuantityRoots NSolve, const double X1, const double X2);

int InputCoefficients (double* const A, double* const B, double* const C);

int InputOnlyCoefficient (double* const Coefficient, const char Symbol);

void PrintNumberRoots (const QuantityRoots NSolve);

int InputIntentionChecked (int* const AnsUser);

int AskUserIntention (int* const AnsUser);

int InputBufferClean ();


#endif // INPUT_OUTPUT_H
