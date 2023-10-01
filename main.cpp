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
    
    QSort( file.OneginLines, 0, file.LineNumber - 1, file.OneginsLines );
    
    for (size_t i = 0; i < file.LineNumber; i++) 
    {
        printf("%s\n", file.OneginLines[i]);
    }
    printf("\n");
    

}