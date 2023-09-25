#ifndef QSORT_H_
#define QSORT_H_

#include "io.h"

void QSort( char** data, int left, int right );
int Compare( char* a, char* b );
void Swap(char** lhs, char** rhs);

#endif // #define QSORT_H_