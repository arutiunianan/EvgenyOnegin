#include "qsort.h"
#include <string.h>
#include <ctype.h>

int Partition( String* strings, int left, int right, int Comparator( String* lhs, String* rhs ) )
{

    assert( strings );
    int mid = ( left - right ) / 2 + right;
    assert(0 <= mid <= 7 );

    while( left < right )
    {
        
        while( Comparator( &strings[left], &strings[mid] ) == -1 )  left++;

        while( Comparator( &strings[right], &strings[mid] ) == 1 ) right--;

        if( left < right )
        {

            Swap( &strings[left], &strings[right] );

            if( left == mid ) mid = right;
            else if( right == mid ) mid = left;

        }

    }

    return mid;

}

void QSort( String* strings, int left, int right, int Comparator( String* lhs, String* rhs ) )
{
    int mid = Partition( strings, left, right, Comparator );
    if(left < right)
    {
        QSort( strings, left, mid - 1, Comparator );
        QSort( strings, mid + 1, right, Comparator );
    }
}


int CompareFirstLet( String* lhs, String* rhs )
{

    size_t minLen = min( lhs->len, rhs->len );
    
    size_t iLhs = 0;
    size_t iRhs = 0;
    while( iLhs < minLen && iRhs < minLen )
    {
        while( !isalpha( lhs->str[iLhs] ) ) iLhs++;
        while( !isalpha( rhs->str[iRhs] ) ) iRhs++;
        if ( ( iLhs < minLen && iRhs < minLen) && ( tolower( lhs->str[iLhs] ) > tolower( rhs->str[iRhs] ) )  ) return 1;
        else if( ( iLhs < minLen && iRhs < minLen ) && ( tolower( lhs->str[iLhs] ) < tolower( rhs->str[iRhs] ) ) ) return -1;
        iLhs++;
        iRhs++;
    }

    if ( (*lhs).len == (*rhs).len ) return 0;
    if ( (*lhs).len > (*rhs).len  ) return 1;
    return -1;

}


int CompareLastLet( String* lhs, String* rhs )
{
    int iLhs = lhs->len - 1;
    int iRhs = rhs->len - 1;

    while( iLhs >= 0 && iRhs >= 0 )
    {
        while( iLhs >= 0 && !isalpha( lhs->str[iLhs] ) ) { iLhs--; }
        while( iRhs >= 0 && !isalpha( rhs->str[iRhs] ) ) iRhs--;
        if ( ( iLhs >= 0 && iRhs >= 0 ) && tolower( lhs->str[iLhs] ) > tolower( rhs->str[iRhs] ) ) return 1;
        else if( ( iLhs >= 0 && iRhs >= 0 ) && tolower( lhs->str[iLhs] ) < tolower( rhs->str[iRhs] ) ) return -1;
        iLhs--;
        iRhs--;
        
    }

    if ( lhs->len == rhs->len ) return 0;
    if ( lhs->len > rhs->len ) return 1;
    return -1;

}


void Swap( String* lhs, String* rhs)
{
    String tmp = *lhs;
	*lhs = *rhs;
    *rhs = tmp;
}

size_t min( size_t lLen, size_t rLen )
{
    return lLen < rLen ? lLen : rLen;
}

void Print( OneginFile file )
{
    
    for ( size_t i = 0; i < file.LineNumber; i++ ) 
    {
        printf( "%s\n", file.OneginsLines[i].str );
    }
    printf( "\n" );

}