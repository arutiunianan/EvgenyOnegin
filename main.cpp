#include "ofile.h"
#include "qsort.h"
#include <stdlib.h>
#include <string.h>


int main( )
{

    OneginFile file = {};
    OneginFileCtor( &file);
    
    QSort( file.OneginsLines, 0, file.LineNumber - 1, CompareLastLet );
    Print( file );
    
    QSort( file.OneginsLines, 0, file.LineNumber - 1, CompareFirstLet );
    Print( file );

}