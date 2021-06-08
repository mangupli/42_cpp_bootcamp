#include "Contact.class.hpp"

Contact::Contact( void )
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Contact::~Contact( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// *****************Getters***************

std::string	Contact::getFirstName( void ) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName( void ) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname( void ) const
{
	return (this->_nickname);
}

std::string	Contact::getLogin( void ) const
{
	return (this->_login);
}

std::string	Contact::getPostalAddress( void ) const
{
	return (this->_postalAddress);
}

std::string	Contact::getEmailAddress( void ) const
{
	return (this->_emailAddress);
}

std::string	Contact::getPhoneNumber( void ) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getBirthday( void ) const
{
	return (this->_birthday);
}

std::string	Contact::getFavoriteMeal( void ) const
{
	return (this->_favoriteMeal);
}

std::string	Contact::getUnderwearColor( void ) const
{
	return (this->_underwearColor);
}

std::string	Contact::getDarkestSecret( void ) const
{
	return (this->_darkestSecret);
}


// *****************Setters***************

void Contact::setFirstName(std::string str)
{
	this->_firstName = str;
};

void Contact::setLastName(std::string str)
{
	this->_lastName = str;
};

void Contact::setNickname(std::string str)
{
	this->_nickname = str;
};

void Contact::setLogin(std::string str)
{
	this->_login = str;
};

void Contact::setPostalAddress(std::string str)
{
	this->_postalAddress = str;
};

void Contact::setEmailAddress(std::string str)
{
	this->_emailAddress = str;
};

void Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
};

void Contact::setBirthday(std::string str)
{
	this->_birthday = str;
};

void Contact::setFavoriteMeal(std::string str)
{
	this->_favoriteMeal = str;
};

void Contact::setUnderwearColor(std::string str)
{
	this->_underwearColor = str;
};

void Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
};


