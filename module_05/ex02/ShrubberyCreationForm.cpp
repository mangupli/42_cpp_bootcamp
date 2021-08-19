#include "ShrubberyCreationForm.hpp"

/*
*--------Constructors --------
*/

ShrubberyCreationForm::ShrubberyCreationForm( void ):
                    Form( "ShrubberyCreationForm", 145, 137),
                    _target("noTarget")
{
    std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ):
                    Form("ShrubberyCreationForm", 145, 137),
                    _target(target)
{
    std::cout << "ShrubberyCreationForm created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & other ):
                    Form("ShrubberyCreationForm", 145, 137),
                    _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}

/*
*----------Member functions------------
*/

std::string ShrubberyCreationForm::getTarget( void ) const
{
    return this->_target;
}

void        ShrubberyCreationForm::setTarget( std::string target )
{
    this->_target = target;
}

void        ShrubberyCreationForm::action ( void ) const
{
    std::string nameOfFile = this->_target + "_shrubbery";
    
    try
    {
        std::ofstream MyFile(nameOfFile);

        MyFile << "----------------------" << std::endl
            << "-----()()-(()---------" << std::endl
            << "----(0()/(0)())-------" << std::endl
            << "-----(())0)\\())(()---" << std::endl
            << "-((0))-\\///(0(())0)---" << std::endl
            << "(()\\())-|||-(()(0))---" << std::endl
            << "--\\()/--|||---\\/-----" << std::endl
            << "---||---|||---||------" << std::endl
            << "---//---///---/\\-----" << std::endl
            << "----------------------" << std::endl;
    
        MyFile.close();

        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Forest of shrubberies are waiting for you in <" << nameOfFile << "> file!"
        << std::endl;
                std::cout << "------------------------------------------------------------------------------------" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
