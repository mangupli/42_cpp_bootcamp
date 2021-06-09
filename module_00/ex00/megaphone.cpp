#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

void megaphone(int strings_number, char **strings)
{
	for (int i = 1; i < strings_number; i++)
	{
		for (int j = 0; j < static_cast<int>(strlen(strings[i])); j++)
			putchar(toupper(strings[i][j]));
		//std::cout << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		megaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
