#include <iostream>
#include <string> // stof, stod
#include <climits>

#include "Conversion.class.hpp"

int main(int argc, char *argv[])
{
    if( argc != 2 )
    {
        std::cout << "Wrong arguments. Usage: ./convert <string>" << std::endl;
        return 0;
    }

    std::string const   string(argv[1]);

    Conversion convert(string);

    convert.displayChar();
    convert.displayInt();
    convert.displayFloat();
    convert.displayDouble();

    return 0;
}
