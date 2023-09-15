#pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include <map>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
private:
public:
    Intern(void);
    Intern(const Intern &src);
    ~Intern(void);
    Intern &operator=(const Intern &src);
    AForm *makeForm(const std::string form, const std::string target);
};

#endif