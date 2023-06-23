#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook 	phonebook;
	std::string	command;

	while (1) {
		for (int i = 0; i < 2; i++)
			std::cout<< "\n";
		std::cout << "You must type either ADD, SEARCH or EXIT.\n"
		<< "Anything else won't work, " 
		<< "and you'll have to write everything in upper case.\n";
		
		getline(std::cin, command);
		if (std::cin.eof() == 1 || command.compare("EXIT") == 0)
			phonebook.EXIT();
		else if (command.compare("ADD") == 0)
		{
			phonebook.ADD();
			std::cin.ignore();
		}
		else if (command.compare("SEARCH") == 0)
			phonebook.SEARCH();
		// else if (command.compare("clear") == 0)
		// 	for (int i = 0; i < 100; i++)
		// 		std::cout<< "\n";
		else
			std::cout << "Wrong Input Usage: Only ADD, SEARCH and EXIT can be used(check uppercase)\n";
	}
}
