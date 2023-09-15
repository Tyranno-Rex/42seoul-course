#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "ShrubberyCreationForm.hpp"

class RobotomyRequestForm : public Form
{
private:
    const std::string _name;

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(RobotomyRequestForm &name);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
    std::string getNameFile(void) const;
    void execute(Bureaucrat const &executer);
};

std::ostream &operator<<(std::ostream &oper, RobotomyRequestForm *robo);

#endif
