#include "ofile.h"
#include "qsort.h"
#include <stdlib.h>
#include <string.h>

/*int comparator(char** str1, char** str2)
{
    return strcmp(*str1, *str2);
}
*/
// int array;
// comparator(int* lhs, int* rhs)
// qsort(array)

int main( )
{

    OneginFile file = {};
    OneginFileCtor( &file);
    
    QSort( file.OneginsLines, 0, file.LineNumber - 1, CompareLastLet );
    Print( file );
    
    QSort( file.OneginsLines, 0, file.LineNumber - 1, CompareFirstLet );
    Print( file );

}