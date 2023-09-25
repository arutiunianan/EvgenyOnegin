#include "qsort.h"


static int Partition( char** data, int left, int right )
{

    int mid = ( left - right ) / 2 + right;
    char* pivot = data[mid];

    assert( data );
    assert( pivot );

    while( left < right )
    {
        while( Compare( data[left], pivot) == -1 )  left++;

        while( Compare( data[right], pivot) == 1 ) right--;

        if( left < right )
        {
            Swap( &(data[left]), &(data[right]) );

            if( left == mid ) mid = right;
            else if( right == mid ) mid = left;
        }
    }

    return mid;

}

void QSort( char** data, int left, int right )
{
    int mid = Partition( data, left, right );
    if(mid - left > 0)
    {
        QSort( data, left, mid - 1);
        QSort( data, mid + 1, right );
    }

}


int Compare( char* lhs, char* rhs )
{
    // strcmp()
    // ;,:
    // isalpha()
    // tolower()
    // A [..] a [..]
    // tolower(str1[i]) - tolower(str2[i]);
    size_t lLen = strlen( lhs );
    size_t rLen = strlen( rhs );
    size_t minLen = min(lLen, rLen);
    
    size_t iLhs = 0;
    size_t iRhs = 0;
    while( iLhs < minLen && iRhs < minLen )
    {
        while( IsAlpha( !lhs[iLhs] ) ) iLhs++;
        while( IsAlpha( !rhs[iRhs] ) ) iRhs++;
        if (ToLower( lhs[iLhs] ) > ToLower( rhs[iRhs] ) && (iLhs < minLen && iRhs < minLen) ) return 1;
        else if( ToLower( lhs[iLhs] ) < ToLower( rhs[iRhs] ) ) return -1;
        iLhs++;
        iRhs++;
    }

    if ( lLen == rLen ) return 0;
    if ( lLen > rLen ) return 1;
    return -1;

}

void Swap(char** lhs, char** rhs)
{
    char* tmp = *lhs;
	*lhs = *rhs;
    *rhs = tmp;
}

size_t min( size_t lLen, size_t rLen)
{
    return lLen < rLen ? lLen : rLen;
}

int IsAlpha( int sym)
{
    return ( ( sym >= 'A' && sym <= 'Z' ) || ( sym >= 'a' && sym <= 'z' ) ) ? 1 : 0;
}

int ToLower( int sym)
{
    if( sym >= 'a' && sym <= 'z' )
        return sym;
    return sym + ( 'a' - 'A' );
}