#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

#include "Contact.hpp"

# define MAX_CONTACT 8


class PhoneBook
{
private:
    int     idx;
    Contact contacts[MAX_CONTACT];
public:
    PhoneBook();
    void    ADD(void);
    void    SEARCH(void);
    void    EXIT(void);
};

PhoneBook::PhoneBook(void) {
    this->idx = 0;
}

void	PhoneBook::ADD(void) {
	if (this->idx == 8)
		this->idx = 0; 
	this->contacts[idx].InitContact(this->idx + 1);
	this->idx++;
}

void	PhoneBook::SEARCH(void) {
	std::string	command;
	int			find_idx;

	if (this->idx == 0)
	{
		std::cout << "Error: Contact not found.\n";
		return ;
	}
    std::cout << "Enter the index of the contact you are looking for\n";

	for (int i = 0; i < 8; i++)
		this->contacts[i].displayContact();
	
    std::cout << "index: ";
	getline(std::cin, command);

    for (size_t i = 0; i < command.length(); i++)
	{
		if (std::isdigit(command.at(i)) == 0)
		{
			std::cout << "Input after search must be numeric\n";
			return ;
		}
	}

    find_idx = atoi(command.c_str());
    if (find_idx == 0)
        std::cout << "Error: Input is not a number\n";
    else if (find_idx > 8 || find_idx < 1)
        std::cout << "Error: Out of range\n";
    else if (this->contacts[find_idx - 1].GetContactId() == 0)
        std::cout << "Error: It is an empty contatct\n";
    else
        this->contacts[find_idx - 1].displayAllContact();
}

void	PhoneBook::EXIT(void) {
	exit(0);
}

#endif