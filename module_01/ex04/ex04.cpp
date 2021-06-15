#include <string>
#include <iostream>


void displayStrPtr(std::string *string)
{
    std::cout << *string << std::endl;
}

void displayStrRef(std::string &string)
{
    std::cout << string << std::endl;
}

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *ptr;
    std::string &ref = string;

    ptr = &string;

    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;

    displayStrPtr(&string);
    displayStrRef(string);
    
	return (0);
}