#ifndef QSORT_H_
#define QSORT_H_

#include "io.h"

void QSort( char** data, int left, int right );
int Compare( char* a, char* b );
void Swap(char** lhs, char** rhs);
size_t min( size_t lLen, size_t rLen);
int IsAlpha( int sym);
int ToLower( int sym);

#endif // #define QSORT_H_