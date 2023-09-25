#include "ofile.h"

static size_t GetFileSize(FILE *text)
{
    fseek( text, 0, SEEK_END );
    size_t LetterNumber = ftell( text );
    fseek( text, 0, SEEK_SET );
    return LetterNumber;
}

static size_t GetLineNumber( char* OneginLetters, size_t LetterNumber )
{
    size_t LineNumber = 1;
    for( size_t i = 0; i < LetterNumber; i++ )
    {

        if ( OneginLetters[i] == '\n' )
            LineNumber++;

    }
    return LineNumber;
}

static void CreateBufferOfLetters( OneginFile *file )
{
    assert( file->text );

    file->FileSize = GetFileSize( file->text );
    file->OneginLetters = ( char* ) calloc ( file->FileSize, sizeof(char*) );
    fread( file->OneginLetters, sizeof(char), file->FileSize, file->text );

}

static void CreateBufferOfLines( OneginFile *file )
{
    file->LineNumber = GetLineNumber( file->OneginLetters, file->FileSize );
    file->OneginLines = ( char** ) calloc ( file->LineNumber, sizeof(char**) );
    file->OneginLines[0] = file->OneginLetters;
    size_t line = 1;

    size_t len = 0;
    file->LineLen = ( size_t* ) calloc ( file->LineNumber, sizeof(size_t*) );

    for( size_t i = 0; i < file->FileSize - 1; i++ )
    {

        if( file->OneginLetters[i] == '\n' )
        {
            file->LineLen[line-1] = len;
            len = 0;
            file->OneginLines[line++] =  &(file->OneginLetters[i+1]);
            file->OneginLetters[i] = '\0';
        }
        else
            len++;

    }
    file->LineLen[line-1] = len + 1;

}

void OneginFileCtor(OneginFile *file)
{
    file->text = fopen( "evgenionegin.txt", "r" );
    //file.text = fopen( "xz.txt", "r" );

    CreateBufferOfLetters( file );
    CreateBufferOfLines( file );
}
