#include "functiontable.h"

#include "symboltable.h"
#include <cstring>
#include <iostream>

FunctionTable::FunctionTable( SymbolTable symTab, FunctionEntry funArr[] )
    : _size( 0 )
{
    for ( int i = 0; i < maxIdFun; ++i )
    {
        int len = strlen( funArr[ i ].strFun );
        if ( len = 0 )
            break;
        _pFun[ i ] = funArr[ i ].pFun;
        std::cout << funArr[ i ].strFun << std::endl;
        int j = symTab.ForceAdd()
    }
}
