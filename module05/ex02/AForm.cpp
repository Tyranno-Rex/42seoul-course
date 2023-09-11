#include "AForm.hpp"


Form::Form(void): _name("default_name"), _sign_lvl(150), _exec_lvl(150), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(const Form &src): _name(src.getFormName()), _sign_lvl(src.getFormLevel()), _exec_lvl(src.getExecLevel()), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(std::string name): _name(name), _sign_lvl(150), _exec_lvl(150), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(std::string name, int access_lvl, int exec_lvl): _name(name), _sign_lvl(access_lvl), _exec_lvl(exec_lvl), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}


Form::~Form(void){
    // std::cout << "Form is deleted\n";
}

std::string Form::getFormName(void) const{
    return (this->_name);
}

int Form::getFormLevel(void) const {
    return (this->_sign_lvl);
}

int Form::getExecLevel(void) const {
    return (this->_exec_lvl);
}

void Form::beSigned(Bureaucrat agent){
    std::cout << "!CHECK!\n[";
    try
    {
        if (this->_sign_lvl >= agent.getGrade()){
            std::cout << "you can access this "<< this->getFormName() << " Form]\n";
        }
        else{
            std::cout << "you can't access this "<< this->getFormName() << " Form]\n";
            throw Form::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


// <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>

void Form::signForm(Bureaucrat agent){
    try
    {
        if (this->_sign_lvl >= agent.getGrade()){
            this->_sign = true;
        }
        else{
            throw Form::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (this->_sign == true){
        std::cout << agent.getName() << " signed "<< this->getFormName() << "\n";
    }
    else{
        std::cout << agent.getName() << " couldn't signed "
        << this->getFormName() << " because this form level(" 
        << this->getFormLevel() <<  ") is higher than agent grade(" 
        << agent.getGrade() << ")\n";
    }
}

std::ostream &operator<<(std::ostream &oper, Form *form)
{
    oper << "Form " << form->getFormName() << " level: " << form->getFormLevel() << "\n";
	return (oper);
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade is too High";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade is too Low";
}