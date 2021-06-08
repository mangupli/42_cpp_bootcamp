#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "Awesome Phone Book created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Awesome Phone Book destroyed" << std::endl;
	return ;
}

int		getNumberOfContacts( void )
{
	return (PhoneBook::numberOfContacts);
}

int		PhoneBook::numberOfContacts = 0;
