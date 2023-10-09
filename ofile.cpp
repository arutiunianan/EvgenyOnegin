#include "ofile.h"

static size_t GetFileSize( FILE *text )
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
    file->OneginLetters = ( char* ) calloc ( file->FileSize, sizeof(char) );
    fread( file->OneginLetters, sizeof( char ), file->FileSize, file->text );

}

static void CreateBufferOfLines( OneginFile *file )
{
    file->LineNumber = GetLineNumber( file->OneginLetters, file->FileSize );
    size_t line = 1;

    size_t len = 0;
    file->OneginsLines = ( String* ) calloc ( file->LineNumber, sizeof( String ) );
    file->OneginsLines[0].str = file->OneginLetters;

    for( size_t i = 0; i < file->FileSize - 1; i++ )
    {

        if( file->OneginLetters[i] == '\n' )
        {
            file->OneginsLines[line - 1].len = len;
            file->OneginsLines[line++].str = &( file->OneginLetters[i+1] );
            len = 0;

            file->OneginLetters[i] = '\0';
        }
        else
        {
            len++;
        }

    }
    file->OneginsLines[line - 1].len = len + 1;

}

void OneginFileCtor( OneginFile *file )
{
    //file->text = fopen( "evgenionegin.txt", "r" );
    //file->text = fopen( "xz3.txt", "r" );
    file->text = fopen( "eo.txt", "r" );

    CreateBufferOfLetters( file );
    CreateBufferOfLines( file );
}

void OneginFileDtor( OneginFile *file )
{

    assert( file );
    free( file->OneginLetters );
    file->OneginLetters = NULL;
    free( file->OneginsLines );
    file->OneginsLines = NULL;
    file->text = NULL;
    file->FileSize = -1;
    file->LineNumber = -1;

}
