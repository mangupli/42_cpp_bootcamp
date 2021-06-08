#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{

public:

	PhoneBook( void );
	~PhoneBook( void );

	Contact contacts[8];

	int getNumberOfContacts( void );
	void programQuits( void );

	static int numberOfContacts;
};

#endif