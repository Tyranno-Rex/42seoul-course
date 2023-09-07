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


void Form::beSigned(Bureaucrat agent){
    // 접근 가능 -> form signed -> true로 바꿔야 함.
    if (this->_access_lvl >= agent.getGrade()){
        this->_sign = true;
        std::cout << agent.getName() << "is signed the form " << this->_name;
    }
    // 접근 불가능 
    else{
        throw Bureaucrat::GradeTooHighException();
        std::cout << agent.getName() << " can't signed the form " << this->_name;
    }
}

std::ostream &operator<<(std::ostream &oper, Form *form)
{
    oper << "Form " << form->getFormName() << " level: " << form->getFormLevel() << "\n";
	return (oper);
}