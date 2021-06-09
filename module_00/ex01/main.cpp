#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main()
{
	PhoneBook	book;
	std::string	inputString;
	int			exit;

	exit = 1;
	while (exit)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, inputString);
		if (inputString == "EXIT" || inputString == "exit")
			exit = 0;
		else if (inputString == "ADD" || inputString == "add")
			book.addContact();
		else if (inputString == "SEARCH" || inputString == "search")
			book.searchContact();
		else
			std::cout << "Not valid input" << std::endl;
	}

	return 0;

}