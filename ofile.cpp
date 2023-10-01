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
    file->OneginLetters = ( char* ) calloc ( file->FileSize, sizeof(char) );
    fread( file->OneginLetters, sizeof(char), file->FileSize, file->text );

}

static void CreateBufferOfLines( OneginFile *file )
{
    file->LineNumber = GetLineNumber( file->OneginLetters, file->FileSize );
    file->OneginLines = ( char** ) calloc ( file->LineNumber, sizeof(char*) );
    file->OneginLines[0] = file->OneginLetters;
    size_t line = 1;

    size_t len = 0;
    file->OneginsLines = ( String* ) calloc ( file->LineNumber, sizeof(String) );
    file->OneginsLines[0].str = file->OneginLetters;

    for( size_t i = 0; i < file->FileSize - 1; i++ )
    {

        if( file->OneginLetters[i] == '\n' )
        {
            file->OneginsLines[line - 1].len = len;
            file->OneginsLines[line].str = &(file->OneginLetters[i+1]);
            len = 0;

            file->OneginLines[line++] =  &(file->OneginLetters[i+1]);
            file->OneginLetters[i] = '\0';
        }
        else
        {
            len++;
        }

    }
    file->OneginsLines[line - 1].len = len + 1;

}

void OneginFileCtor(OneginFile *file)
{
    //file->text = fopen( "evgenionegin.txt", "r" );
    //file->text = fopen( "xz3.txt", "r" );
    file->text = fopen( "eo.txt", "r" );

    CreateBufferOfLetters( file );
    CreateBufferOfLines( file );
}


void DebugPrint(char* data[], int left, int right, int size, int mid) 
{
	int flag = 0;
	for (int i = 0; i < (size); i++) {
		if (i == left) {
			printf("<\n");
            printf("%d %s \n", data[i][0],data[i]);
		}
		else if (i == (right + 1)) {
            printf("%d %s \n", data[i][0],data[i]);
			printf(">\n");
			flag++;
		}
        else
		    printf("%d %s \n", data[i][0],data[i]);
	}
	if (!flag) printf(">");
	printf("\nleft = %d right = %d mid = %d, data[mid] = %s", left, right, mid, data[mid]);
	printf("\n\n\n");
}