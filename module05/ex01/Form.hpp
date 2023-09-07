#include <iostream>
#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class Form: public Bureaucrat{
private:
    const std::string   _name;
    int                 _access_lvl;
    bool                _sign;

public:
    Form(void);
    Form(int level);
    Form(std::string name);
    Form(bool sign);
    Form(int level, std::string name);
    Form(int level, bool sign);
    Form(std::string name, bool sign);
    Form(int level, std::string name, bool sign);
    ~Form(void);
    
    void beSigned(Bureaucrat agent);
    
    std::string getFormName(void);
    int         getFormLevel(void);
};

std::ostream &operator<<(std::ostream &oper, Form *form);