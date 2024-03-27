#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    const std::string _name;

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(PresidentialPardonForm &name);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    std::string getNameFile(void) const;
    void execute(Bureaucrat const &executer) const;
};

std::ostream &operator<<(std::ostream &oper, PresidentialPardonForm *pres);

#endif
