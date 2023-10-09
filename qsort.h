#ifndef QSORT_H_
#define QSORT_H_

#include "ofile.h"

void QSort( String* file, int left, int right, int Comparator( String* lhs, String* rhs ) );
int Partition( String* file, int left, int right, int Comparator( String* lhs, String* rhs ) );
int CompareFirstLet( String* lhs, String* rhs );
int CompareLastLet( String* lhs, String* rhs );
void Swap( String* lhs, String* rhs);
size_t min( size_t lLen, size_t rLen );
void Print( OneginFile file );

#endif // #define QSORT_H_