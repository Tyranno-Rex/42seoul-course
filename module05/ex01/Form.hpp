#include <iostream>
#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class Form{
private:
    std::string         _name;
    int                 _sign_lvl;
    int                 _exec_lvl;
    bool                _sign;

public:
    Form(void);
    Form(const Form &form);
    Form(std::string name);
    Form(int acces_lvl, int exec_lvl);
    Form(std::string name, int access_lvl, int exec_lvl);
    ~Form(void);

    std::string getFormName(void) const;
    int         getFormLevel(void) const;
    int         getExecLevel(void) const;
    bool        getFormSign(void) const;

    void        beSigned(Bureaucrat agent);
    void        signForm(Bureaucrat agent);

    Form &operator=(const Form &src);
    class GradeTooHighException: public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException: public std::exception{
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &oper, Form *form);