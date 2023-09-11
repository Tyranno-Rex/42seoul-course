#include "Form.hpp"


Form::Form(void): _name("default_name"), _access_lvl(1), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(int level): _name("default_name"), _access_lvl(level), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(std::string name): _name(name), _access_lvl(1), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(bool sign): _name("default_name"), _access_lvl(1), _sign(sign){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(int level, std::string name): _name(name), _access_lvl(level), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(int level, bool sign): _name("default_name"), _access_lvl(level), _sign(sign){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(std::string name, bool sign): _name(name), _access_lvl(1), _sign(sign){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(int level, std::string name, bool sign): _name(name), _access_lvl(level), _sign(sign){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_access_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}


Form::~Form(void){
    // std::cout << "Form is deleted\n";
}

std::string Form::getFormName(void){
    return (this->_name);
}

int Form::getFormLevel(void){
    return (this->_access_lvl);
}

void Form::beSigned(Bureaucrat agent){
    if (this->_access_lvl >= agent.getGrade()){
        std::cout << "can access this Form\n";
        this->_sign = true;
    }
    else{
        std::cout << "can't access this Form\n";
        // throw Bureaucrat::GradeTooHighException();
    }
    std::cout << this->getFormName();
    if (this->_sign == true){
        std::cout << " is signed\n";
    }
    else{
        std::cout << " isn't signed\n";

    }
}

std::ostream &operator<<(std::ostream &oper, Form *form)
{
    oper << "Form " << form->getFormName() << " level: " << form->getFormLevel() << "\n";
	return (oper);
}