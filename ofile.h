#ifndef OFILE_H_
#define OFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// onegin_file.h

struct String
{ 
    char* str; 
    int len; 
};

struct OneginFile
{
    FILE *text;
    char *OneginLetters;
    size_t FileSize;
    size_t LineNumber;
    String* OneginsLines;
};


void OneginFileCtor(OneginFile *file);
void DebugPrint(char* data[], int left, int right, int size, int mid);

#endif // #define OFILE_H_