#include "io.h"
#include "qsort.h"
#include <stdlib.h>
#include <string.h>

int main( )
{
    OneginFile file = {};
    OneginFileCtor( &file);

    file.text = fopen( "evgenionegin.txt", "r" );
    //file.text = fopen( "xz.txt", "r" );

    CreateBufferOfLetters( &file );
    CreateBufferOfLines( &file );


    QSort( file.OneginLines, 0, file.LineNumber - 1 );

    for (int i = 0; i < file.LineNumber; i++) 
    {
        printf("%s\n", file.OneginLines[i]);
    }

}