#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include "symboltable.h"

enum Status
{
    stOk,
    stQuit,
    stError
};

class Parser
{
  public:
    Parser( Scanner& scanner, SymbolTable& symTab );

    ~Parser();

    Status
    Parse();

  private:
    Scanner&     _scanner;
    SymbolTable& _symTab;
};

#endif // PARSER_H
