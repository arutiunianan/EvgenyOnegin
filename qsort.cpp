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

// QSort
void QSort( char** data, int left, int right )
{
    int mid = Partition( data, left, right );
    if(mid - left > 0)
    {
        QSort( data, left, mid - 1);
        QSort( data, mid + 1, right );
    }

}


// lhs, rhs
int Compare( char* l, char* r )
{
    // strcmp()
    // ;,:
    // isalpha()
    // tolower()
    // A [..] a [..]
    // tolower(str1[i]) - tolower(str2[i]);
    size_t lLen = strlen( l );
    size_t rLen = strlen( r );
    // min(lLen, rLen)
    size_t minLen = lLen < rLen ? lLen : rLen;
    
    for( size_t i = 0; i < minLen; i++ )
    {
        // printf("i = %d\n", i);
        if (l[i] > r[i] ) return 1;
        else if( l[i] < r[i] ) return -1;
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