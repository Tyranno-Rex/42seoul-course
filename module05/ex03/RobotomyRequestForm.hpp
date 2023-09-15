#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
// #include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
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
    void execute(Bureaucrat const &executer) const;
};

std::ostream &operator<<(std::ostream &oper, RobotomyRequestForm *robo);

#endif
