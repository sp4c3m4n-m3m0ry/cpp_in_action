#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H

class SymbolTable;

const int maxIdFun = 16;

using PtrFun = double ( * )( double );

class FunctionEntry
{
  public:
    PtrFun pFun;
    char*  strFun;
};

class FunctionTable
{
  public:
    FunctionTable( SymbolTable symTab, FunctionEntry funArr[] );

    int
    Size() const
    {
        return size;
    }

    PtrFun
    GetFun( int id ){ return _pFun[ id ] };

  private:
    PtrFun _pFun[ maxIdFun ];
    int    _size;
};

#endif // FUNCTIONTABLE_H
