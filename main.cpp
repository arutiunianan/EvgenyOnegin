#include "ofile.h"
#include "qsort.h"
#include <stdlib.h>
#include <string.h>

int main( )
{
    OneginFile file = {};
    OneginFileCtor( &file);

    QSort( file.OneginLines, 0, file.LineNumber - 1, file );

    for (int i = 0; i < file.LineNumber; i++) 
    {
        printf("%s\n", file.OneginLines[i]);
    }

}