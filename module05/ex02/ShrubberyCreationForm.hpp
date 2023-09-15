#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    const std::string _name;

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(ShrubberyCreationForm &name);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
    std::string getNameFile(void) const;
    void execute(Bureaucrat const &executer) const;
};

std::ostream &operator<<(std::ostream &oper, ShrubberyCreationForm *shru);

#endif