#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main()
{
	PhoneBook	book;
	std::string	input_string;
	int			exit;

	exit = 1;
	while (exit)
	{
		std::cout << "Enter a command: ";
		std::cin >> input_string;
		if (input_string == "EXIT" || input_string == "exit")
			exit = 0;
		else if (input_string == "ADD" || input_string == "add")
			book.addContact();
		else if (input_string == "SEARCH" || input_string == "search")
			book.searchContact();
		else
			std::cout << "Not valid input" << std::endl;
	}

	return 0;

}