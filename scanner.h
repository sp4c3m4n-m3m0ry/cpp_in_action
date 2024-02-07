#ifndef SCANNER_H
#define SCANNER_H

#include <cassert>
#include <iostream>

const int maxSymLen = 100;

enum EToken
{
    tEnd,
    tError,
    tNumber, // literal number
    tPlus,   // +
    tMult,   // *
    tDivide, //
    tLParen, // (
    tRParen, // )
    tAssign, // =
    tIdent   // identifier (symbolic name)
};

class Scanner
{
  public:
    Scanner( char const* buf );

    EToken
    Token() const
    {
        return _token;
    }

    EToken
    Accept();

    double
    Number()
    {
        assert( _token == tNumber );
        return _number;
    }

    void
    SymbolName( char* strOut, int& len );

  private:
    void
    EatWhite();

    const char* const _buf;
    int               _iLook;
    int               _lenSymbol;
    int               _iSymbol;
    EToken            _token;
    double            _number;
};

#endif // SCANNER_H
