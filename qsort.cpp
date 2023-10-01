#include "qsort.h"
#include <string.h>
#include <ctype.h>

int Partition( char** data, int left, int right, String* file )
{

    assert( data );
    int mid = ( left - right ) / 2 + right;
    assert(0 <= mid <= 7 );
    char* pivot = data[mid];
    printf("\n\n----------start--------------\n\n");
    DebugPrint(data, left, right, 8, mid);
    printf("----------end--------------\n\n");    

    while( left < right )
    {
        printf("мяу");
        
        while( Compare( &file[left], &file[mid] ) == -1 )  left++;

        while( Compare( &file[right], &file[mid] ) == 1 ) right--;
        printf("хз ");
        DebugPrint(data, left, right, 8, mid);
        printf(" что это\n");
        if( left < right )
        {
            Swap( &data[left], &data[right] );
            Swap( &file[left], &file[right] );

            if( left == mid ) mid = right;
            else if( right == mid ) mid = left;
            DebugPrint(data, left, right, 8, mid);
        }

    }

    return mid;

}

void QSort( char** data, int left, int right, String* file )
{
    int mid = Partition( data, left, right, file );
    if(left < right)
    {
        QSort( data, left, mid - 1, file);
        QSort( data, mid + 1, right, file );
    }
}

/*
int Compare(String* lhs, String* rhs)
{

    size_t minLen = min( lhs->len, rhs->len );
    
    size_t iLhs = 0;
    size_t iRhs = 0;
    while( iLhs < minLen && iRhs < minLen )
    {
        while( !IsAlpha( lhs->str[iLhs] ) ) iLhs++;
        while( !IsAlpha( rhs->str[iRhs] ) ) iRhs++;
        if (ToLower( lhs->str[iLhs] ) > ToLower( rhs->str[iRhs] ) && (iLhs < minLen && iRhs < minLen) ) return 1;
        else if( ToLower( lhs->str[iLhs] ) < ToLower( rhs->str[iRhs] ) ) return -1;
        iLhs++;
        iRhs++;
    }

    if ( (*lhs).len == (*rhs).len ) return 0;
    if ( (*lhs).len > (*rhs).len  ) return 1;
    return -1;

}
*/

int Compare(String* lhs, String* rhs)
{
    int iLhs = lhs->len - 1;
    int iRhs = rhs->len - 1;

    while( iLhs >= 0 && iRhs >= 0 )
    {
        while( iLhs >= 0 && !IsAlpha( lhs->str[iLhs] ) ) { iLhs--; }
        while( iRhs >= 0 && !IsAlpha( rhs->str[iRhs] ) ) iRhs--;
        if ( ( iLhs >= 0 && iRhs >= 0 ) && ToLower( lhs->str[iLhs] ) > ToLower( rhs->str[iRhs] ) ) return 1;
        else if( ( iLhs >= 0 && iRhs >= 0 ) && ToLower( lhs->str[iLhs] ) < ToLower( rhs->str[iRhs] ) ) return -1;
        iLhs--;
        iRhs--;
        
    }

    if ( lhs->len == rhs->len ) return 0;
    if ( lhs->len > rhs->len ) return 1;
    return -1;

}


void Swap( char** lhs, char** rhs )
{
    char* tmp = *lhs;
	*lhs = *rhs;
    *rhs = tmp;
}

void Swap( String* lhs, String* rhs)
{
    String tmp = *lhs;
	*lhs = *rhs;
    *rhs = tmp;
}

size_t min( size_t lLen, size_t rLen )
{
    //isalpha()
    return lLen < rLen ? lLen : rLen;
}

// isalpha()

int IsAlpha( int sym )
{
    return ( ( sym >= 'A' && sym <= 'Z' ) || ( sym >= 'a' && sym <= 'z' ) ) ? 1 : 0;
}

int ToLower( int sym )
{
    if( sym >= 'a' && sym <= 'z' )
        return sym;
    return sym + ( 'a' - 'A' );
}
