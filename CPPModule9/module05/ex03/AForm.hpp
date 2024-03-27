#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm{
private:
    std::string         _name;
    int                 _sign_lvl;
    int                 _exec_lvl;
    bool                _sign;

public:
    AForm(void);
    AForm(const AForm &form);
    AForm(std::string name);
    AForm(int acces_lvl, int exec_lvl);
    AForm(std::string name, int access_lvl, int exec_lvl);
    ~AForm(void);

    std::string getFormName(void) const;
    int         getSignLevel(void) const;
    int         getExecLevel(void) const;
    bool        getFormSign(void) const;

    void        beSigned(Bureaucrat agent);

    AForm &operator=(const AForm &src);

    virtual void execute(Bureaucrat const &executor) const = 0;
    class GradeTooHighException: public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException: public std::exception{
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &oper, AForm *form);

#endif