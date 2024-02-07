#ifndef HTABLE_H
#define HTABLE_H

#include "list.h"
#include <cassert>
#include <new>

const int sizeHTable = 127;

class HTable
{
  public:
    explicit HTable( int size = sizeHTable )
        : _size( size )
    {
        _aList = new List[ size ];
    }

    ~HTable()
    {
        delete[] _aList;
    }

    // return a short list of candidates
    List const&
    Find( char const* str ) const;

    // add another string->id mapping
    void
    Add( char const* str, int id );

  private:
    int
    hash( const char* str ) const;

    List* _aList; // an array of (short) lists
    int   _size;
};

// Find the list in the hash table that may contain
// the id of the string we are looking for
List const&
HTable::Find( char const* str ) const
{
    int i = hash( str );
    return _aList[ i ];
}

void
HTable::Add( char const* str, int id )
{
    int i = hash( str );
    _aList[ i ].Add( id );
}

int
HTable::hash( char const* str ) const
{
    // no empty strings, please
    assert( str != 0 && str[ 0 ] != 0 );
    unsigned h = str[ 0 ];
    for ( int i = 1; str[ i ] != 0; ++i )
        h = ( h << 4 ) + str[ i ];
    return h % sizeHTable; // remainder
}

#endif // HTABLE_H
