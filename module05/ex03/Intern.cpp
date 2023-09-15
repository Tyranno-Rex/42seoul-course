#include "Intern.hpp"

Intern::Intern(void){
    // std::cout << this->_name << " created\n";
}

Intern::Intern(const Intern &src){
    // std::cout << this->_name << " created\n";
	*this = src;
}

Intern::~Intern(void){
    // std::cout << this->_name << " is deleted\n";
}

Intern &Intern::operator=(const Intern &src){
	if (this == &src)
		return *this;
	return *this;
}

static Form	*makePresident(const std::string target){
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobot(const std::string target){
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubbery(const std::string target){
	return (new ShrubberyCreationForm(target));
}


// Intern someRandomIntern;
// Form* rrf;
// rrf = someRandomIntern.makeForm("robotomy request", "Bender");

Form	*Intern::makeForm(const std::string form, const std::string target){
    std::map<std::string, Form *(*)(const std::string)> all_forms;
    all_forms["PresidentialPardonForm"] = &makePresident;
    all_forms["RobotomyRequestForm"] = &makeRobot;
    all_forms["ShrubberyCreationForm"] = &makeShrubbery;

    std::map<std::string, Form *(*)(const std::string)>::iterator it = all_forms.find(form);
    if (it != all_forms.end()) {
        std::cout << "Intern creates " << form << " now\n";
        return (it->second(target));
    } else {
        std::cout << "Intern can not create a form called " << form << "\n";
        return (NULL);
    }
}
