#ifndef QSORT_H_
#define QSORT_H_

#include "ofile.h"

void QSort( char** data, int left, int right, String* OneginsLines );
int Partition( char** data, int left, int right, String* file );
int Compare( String* lhs, String* rhs );
void Swap( char** lhs, char** rhs );
void Swap( String* lhs, String* rhs);
size_t min( size_t lLen, size_t rLen );
int IsAlpha( int sym );
int ToLower( int sym );

#endif // #define QSORT_H_