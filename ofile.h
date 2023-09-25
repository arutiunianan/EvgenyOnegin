#ifndef OFILE_H_
#define OFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// onegin_file.h

struct OneginFile
{
    FILE *text;
    char *OneginLetters;
    size_t FileSize;
    size_t LineNumber;
    char **OneginLines;
    size_t *LineLen;
};

void OneginFileCtor(OneginFile *file);

#endif // #define OFILE_H_