#ifndef IO_H_
#define IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// onegin_file.h

struct OneginFile
{
    FILE* text;
    char *OneginLetters;
    size_t FileSize;
    size_t LineNumber;
    char **OneginLines;
};

void OneginFileCtor(OneginFile *file);
void CreateBufferOfLetters( OneginFile *file );
void CreateBufferOfLines( OneginFile *file );
size_t GetFileSize( FILE *text );
size_t GetLineNumber( char* OneginLetters, size_t LetterNumber );

#endif // #define IO_H_