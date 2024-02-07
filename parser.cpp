#include "parser.h"
#include "scanner.h"
#include <iostream>

Parser::Parser( Scanner& scanner, SymbolTable& symTab )
    : _scanner( scanner ),
      _symTab( symTab )
{
    std::cout << "Parser created\n";
}

Parser::~Parser()
{
    std::cout << "Destroying parser\n";
}
Status
Parser::Parse()
{
    for ( EToken token = _scanner.Token(); token != tEnd; token = _scanner.Accept() )
    {
        switch ( token )
        {
            case tMult :
                std::cout << "Times\n";
                break;
            case tPlus :
                std::cout << "Plus\n";
                break;
            case tNumber :
                std::cout << "Number: \n";
                break;
            case tError :
                std::cout << "Error\n";
                break;
            default :
                std::cout << "Error: bad token";
                return stQuit;
        }
    }
    return stOk;
}