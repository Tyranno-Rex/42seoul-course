#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
private:
	int			id;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact();
	int		GetContactId(void);
	void	InitContact(int i);
	void	displayFormat(std::string str);
	void	displayContact(void);
	void	displayAllContact(void);
};

Contact::Contact() {
	this->id = 0;
}

int	Contact::GetContactId(void) {
	return (this->id);
}

void	Contact::InitContact(int i) {
	this->id = i;
	std::cout << "first name: ";
	std::cin >> this->firstName;
	std::cout << "last name: ";
	std::cin >> this->lastName;
	std::cout << "nickname: ";
	std::cin >> this->nickName;
	std::cout << "phone number: ";
	std::cin >> this->phoneNumber;
	std::cout << "darkest secret: ";
	std::cin >> this->darkestSecret;
}

void Contact::displayFormat(std::string str) {
    long unsigned int maxLength = 10;
    if (str.length() > maxLength) {
        str = str.substr(0, maxLength - 1) + ".";
    }
    std::cout << std::setw(maxLength) << str;
}


void	Contact::displayContact(void) {

	if (this->id == 0)
		return ;
	std::stringstream	ss;
	ss << this->id;
	this->displayFormat(ss.str());
	std::cout << "|";
	this->displayFormat(this->firstName);
	std::cout << "|";
	this->displayFormat(this->lastName);
	std::cout << "|";
	this->displayFormat(this->nickName);
	std::cout << std::endl;
}

void	Contact::displayAllContact(void) {
	std::cout << "first name: " << this->firstName << std::endl;
	std::cout << "last name: " << this->lastName << std::endl;
	std::cout << "nickname: " << this->nickName << std::endl;
	std::cout << "phone number: " << this->phoneNumber << std::endl;
	std::cout << "darkset secret: " << this->darkestSecret << std::endl;
}


#endif
