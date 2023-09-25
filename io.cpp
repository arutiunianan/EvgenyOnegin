#include "io.h"


void OneginFileCtor(OneginFile *file)
{
    file->text = NULL;
    file->OneginLetters = NULL;
    file->FileSize = 0;
    file->LineNumber = 0;
    file->OneginLines = NULL;
}

void CreateBufferOfLetters( OneginFile *file )
{
    assert( file->text );

    file->FileSize = GetFileSize( file->text );
    file->OneginLetters = ( char* ) calloc ( file->FileSize, sizeof(char*) );
    fread( file->OneginLetters, sizeof(char), file->FileSize, file->text );

}

void CreateBufferOfLines( OneginFile *file )
{
    file->LineNumber = GetLineNumber( file->OneginLetters, file->FileSize );
    file->OneginLines = ( char** ) malloc( file->LineNumber );
    file->OneginLines[0] = file->OneginLetters;
    size_t line = 1;

    for( size_t i = 0; i < file->FileSize - 1; i++ )
    {

        if( file->OneginLetters[i] == '\n' )
        {
            // OneginLines[i].str = ...;
            // OneginLines[i].len = ...;
            file->OneginLines[line++] =  &(file->OneginLetters[i+1]);
            file->OneginLetters[i] = '\0';
        }

    }

}


size_t GetFileSize(FILE *text)
{
    fseek( text, 0, SEEK_END );
    size_t LetterNumber = ftell( text );
    fseek( text, 0, SEEK_SET );
    return LetterNumber;
}

size_t GetLineNumber( char* OneginLetters, size_t LetterNumber )
{
    size_t LineNumber = 1;
    for( size_t i = 0; i < LetterNumber; i++ )
    {

        if ( OneginLetters[i] == '\n' )
            LineNumber++;

    }
    return LineNumber;
}