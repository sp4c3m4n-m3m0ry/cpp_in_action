#include "parser.h"
#include "scanner.h"
#include "symboltable.h"

const int maxBuf = 100;

int
main()
{
    char        buf[ maxBuf ];
    Status      status;
    SymbolTable symTab;
    do
    {
        std::cout << "> "; // prompt
        std::cin.getline( buf, maxBuf );
        Scanner scanner( buf );
        Parser  parser( scanner, symTab );
        status = parser.Parse();
    } while ( status != stQuit );
}