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
	return (PhoneBook::numberOfContacts);
}

void 	PhoneBook::addContact ( void )
{
	std::string input_string;
	if (PhoneBook::numberOfContacts < 8)
	{
		std::cout << "Enter first name: ";
		std::cin >> input_string;
		this->contacts[PhoneBook::numberOfContacts].setFirstName(input_string);

//		std::cout << "Enter last name: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setLastName(input_string);
//
//		std::cout << "Enter nickname: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setNickname(input_string);
//
//		std::cout << "Enter login: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setLogin(input_string);
//
//		std::cout << "Enter postal address: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setPostalAddress(input_string);
//
//		std::cout << "Enter email address: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setEmailAddress(input_string);
//
//		std::cout << "Enter phone number: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setPhoneNumber(input_string);
//
//		std::cout << "Enter birthday: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setBirthday(input_string);
//
//		std::cout << "Enter favorite meal: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setFavoriteMeal(input_string);
//
//		std::cout << "Enter underwear color: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setUnderwearColor(input_string);
//
//		std::cout << "Enter darkest secret: ";
//		std::cin >> input_string;
//		this->contacts[PhoneBook::numberOfContacts].setDarkestSecret(input_string);

		PhoneBook::numberOfContacts += 1;
		std::cout << "Congrats! Contact added" << std::endl;
		std::cout << "Number of contacts: " << PhoneBook::numberOfContacts
				  << std::endl;
	}
	else
		std::cout << "Reached the limit of contacts" << std::endl;
}

void 	PhoneBook::searchContact ( void )
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

	for (int i = 0; i < PhoneBook::numberOfContacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i + 1;
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->contacts[i].getFirstName();
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->contacts[i].getLastName();
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->contacts[i].getNickname();
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}

	int index; //index
	std::string input_string;
	std::cout << "Choose contact index for more info: ";
	std::cin >> input_string;
	index = atoi(input_string.c_str());
	if (index > 0 && index <= PhoneBook::numberOfContacts)
	{
		int i = index - 1;
		std::cout << "index: " << index << std::endl;
		std::cout << "first name: " << this->contacts[i].getFirstName() << std::endl;
		std::cout << "last name: " << this->contacts[i].getLastName() << std::endl;
		std::cout << "nickname: " << this->contacts[i].getNickname() << std::endl;
		std::cout << "login: " << this->contacts[i].getLogin() << std::endl;
		std::cout << "postal address: " << this->contacts[i].getPostalAddress() << std::endl;
		std::cout << "email address: " << this->contacts[i].getEmailAddress() << std::endl;
		std::cout << "phone number: " << this->contacts[i].getPhoneNumber() << std::endl;
		std::cout << "birthday: " << this->contacts[i].getBirthday() << std::endl;
		std::cout << "favorite meal: " << this->contacts[i].getFavoriteMeal() << std::endl;
		std::cout << "underwear color: " << this->contacts[i].getUnderwearColor() << std::endl;
		std::cout << "darkest secret: " << this->contacts[i].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "not valid index: " << input_string << std::endl;
}

int		PhoneBook::numberOfContacts = 0;
