#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "htable.h"

const int idNotFound = -1;

class SymbolTable
{
  public:
    explicit SymbolTable( int size );
    ~SymbolTable();
    int
    ForceAdd( char const* str, int len );
    int
    Find( char const* str, int len ) const;
    char const*
    GetString( int id ) const;

  private:
    HTable _htab;
    int*   _offStr; // offsets of strings in buffer
    int    _size;
    int    _curId;
    char*  _strBuf;
    int    _bufSize;
    int    _curStrOff;
};

#endif // SYMBOLTABLE_H
