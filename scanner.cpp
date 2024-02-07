#include "scanner.h"
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>

Scanner::Scanner( char const* buf )
    : _buf( buf ),
      _iLook( 0 )
{
    std::cout << "Scanner with \"" << buf << "\"" << std::endl;
    Accept();
}

EToken
Scanner::Accept()
{
    EatWhite();
    switch ( _buf[ _iLook ] )
    {
        case '+' :
            _token = tPlus;
            ++_iLook;
            break;
        case '*' :
            _token = tMult;
            ++_iLook;
            break;
        case '1' :
        case '2' :
        case '3' :
        case '4' :
        case '5' :
        case '6' :
        case '7' :
        case '8' :
        case '9' :
        case '.' :
            _token = tNumber;
            char* p;
            _number = strtod( &_buf[ _iLook ], &p );
            _iLook  = p - _buf; // pointer subtraction
            break;
        case '\0' : // end of input
            _token = tEnd;
            break;
        default :
            if ( isalpha( _buf[ _iLook ] ) || _buf[ _iLook ] == '_' )
            {
                _token   = tIdent;
                _iSymbol = _iLook;
                int cLook; // initialized in the do loop
                do
                {
                    ++_iLook;
                    cLook = _buf[ _iLook ];
                } while ( isalnum( cLook ) || cLook == '_' );

                _lenSymbol = _iLook - _iSymbol;
                if ( _lenSymbol > maxSymLen )
                    _lenSymbol = maxSymLen;
            }
            else
                _token = tError;
            break;
    }
    return Token();
}

void
Scanner::SymbolName( char* strOut, int& len )
{
    assert( len >= maxSymLen );
    assert( _lenSymbol <= maxSymLen );
    strncpy( strOut, &_buf[ _iSymbol ], _lenSymbol );
    strOut[ _lenSymbol ] = 0;
    len                  = _lenSymbol;
}

void
Scanner::EatWhite()
{
    while ( isspace( _buf[ _iLook ] ) )
        ++_iLook;
}
