#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "Awesome Phone Book created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Phone Book destroyed" << std::endl;
	return ;
}

int		PhoneBook::getNumberOfContacts( void )
{
	return (PhoneBook::_numberOfContacts);
}

void 	PhoneBook::addContact ( void )
{
	std::string inputString;

	if (PhoneBook::_numberOfContacts < 8)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setFirstName(inputString);

		std::cout << "Enter last name: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setLastName(inputString);

		std::cout << "Enter nickname: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setNickname(inputString);

		std::cout << "Enter login: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setLogin(inputString);

		std::cout << "Enter postal address: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setPostalAddress(inputString);

		std::cout << "Enter email address: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setEmailAddress(inputString);

		std::cout << "Enter phone number: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setPhoneNumber(inputString);

		std::cout << "Enter birthday: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setBirthday(inputString);

		std::cout << "Enter favorite meal: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setFavoriteMeal(inputString);

		std::cout << "Enter underwear color: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setUnderwearColor(inputString);

		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, inputString);
		this->_contacts[PhoneBook::_numberOfContacts].setDarkestSecret(inputString);

		PhoneBook::_numberOfContacts += 1;
		std::cout << "Congratz! You made a new friend :З" << std::endl;
		std::cout << "Number of contacts: " << PhoneBook::_numberOfContacts
				  << std::endl;
	}
	else
		std::cout << "Reached the limit of contacts" << std::endl;
}

void 	PhoneBook::_printMaxTenChars ( std::string str ) const
{
	if (strlen(str.c_str()) <= 10)
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
	else
	{
		for (int i = 0; i < 9; i++)
			putchar((str[i]));
		std::cout << ".";
	}
}

void 	PhoneBook::_displayAvailableContacts ( void ) const
{
	std::cout << "Available contacts: " << std::endl;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "index";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "first name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "last name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "nick";
	std::cout << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < PhoneBook::_numberOfContacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i + 1;
		std::cout << "|";
		this->_printMaxTenChars(this->_contacts[i].getFirstName());
		std::cout << "|";
		this->_printMaxTenChars(this->_contacts[i].getLastName());
		std::cout << "|";
		this->_printMaxTenChars(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
}

void 	PhoneBook::_displayContactInfo ( int index ) const
{
	int i = index - 1;

	std::cout << "index: " << index << std::endl;
	std::cout << "first name: " << this->_contacts[i].getFirstName() << std::endl;
	std::cout << "last name: " << this->_contacts[i].getLastName() << std::endl;
	std::cout << "nickname: " << this->_contacts[i].getNickname() << std::endl;
	std::cout << "login: " << this->_contacts[i].getLogin() << std::endl;
	std::cout << "postal address: " << this->_contacts[i].getPostalAddress() << std::endl;
	std::cout << "email address: " << this->_contacts[i].getEmailAddress() << std::endl;
	std::cout << "phone number: " << this->_contacts[i].getPhoneNumber() << std::endl;
	std::cout << "birthday: " << this->_contacts[i].getBirthday() << std::endl;
	std::cout << "favorite meal: " << this->_contacts[i].getFavoriteMeal() << std::endl;
	std::cout << "underwear color: " << this->_contacts[i].getUnderwearColor() << std::endl;
	std::cout << "darkest secret: " << this->_contacts[i].getDarkestSecret() << std::endl;
}

void 	PhoneBook::searchContact ( void )
{
	int			index;
	std::string	inputString;

	this->_displayAvailableContacts();
	if (PhoneBook::_numberOfContacts > 0)
	{
		std::cout << "Choose contact index for more info: ";
		std::getline(std::cin, inputString);
		index = atoi(inputString.c_str());
		if (index > 0 && index <= PhoneBook::_numberOfContacts)
			this->_displayContactInfo(index);
		else
			std::cout << "not valid index: " << inputString << std::endl;
	}
	else
		std::cout << "You have 0 contacts :c" << std::endl << "Go make friends!" << std::endl;
}

int		PhoneBook::_numberOfContacts = 0;
