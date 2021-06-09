#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iomanip>
#include <cstdlib>
#include <string>

class PhoneBook
{

public:

	PhoneBook( void );
	~PhoneBook( void );

	int		getNumberOfContacts( void );
	void	addContact( void );
	void	searchContact( void );

private:

	Contact		_contacts[8];
	static int	_numberOfContacts;

	void 		_displayAvailableContacts( void ) const;
	void 		_displayContactInfo( int index ) const;
	void 		_printMaxTenChars(std::string str) const;
};

#endif