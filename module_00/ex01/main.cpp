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
		if (input_string == "EXIT")
			exit = 0;
		else
		{
			std::cout << "Writing smth......" << std::endl;
			book.contacts[0].setFirstName("liza");
			std::cout << "First name is " << book.contacts[0].getFirstName()
					  << std::endl;
		}
	}


	return 0;

}