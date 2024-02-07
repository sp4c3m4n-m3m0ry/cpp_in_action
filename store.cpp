#include "store.h"
#include <iostream>
#include <math.h>

Store::Store( int size, SymbolTable& symTab )
    : _size( size )
{
    _cell   = new double[ size ];
    _status = new unsigned char[ size ];
    for ( int i = 0; i < size; ++i )
        _status[ i ] = stNotInit;
    std::cout << "e = " << exp( 1 ) << std::endl;
    int id = symTab.ForceAdd( "e", 1 );
    SetValue( id, exp( 1 ) );
    std::cout << "pi = " << 2 * acos( 0.0 ) << std::endl;
    id = symTab.ForceAdd( "pi", 2 );
    SetValue( id, 2.0 * acos( 0.0 ) );
}
