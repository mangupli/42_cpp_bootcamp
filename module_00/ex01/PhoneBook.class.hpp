#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iomanip>
#include <cstdlib>

class PhoneBook
{

public:

	PhoneBook( void );
	~PhoneBook( void );

	Contact contacts[8];

	int getNumberOfContacts( void );
	void programQuits( void );

	void addContact( void );
	void searchContact( void );

	static int numberOfContacts;
};

#endif