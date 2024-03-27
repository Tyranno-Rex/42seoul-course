#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _name("default_name"){
    // std::cout << this->_name << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm("ShrubberyCreationForm", 145, 137), _name(name){
    // std::cout << this->_name << "\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    // std::cout << this->_name << " is deleted\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const {
    if (this-getFormSign() == false){
        std::cout << "this form isn't signed\n";
        std::cout << "go sign first\n";
        return ;
    }

    if (executer.getGrade() < 137){
        std::cout << "you can execute the this form\n";
    }
    else{
        std::cout << "you can't execute the this form\n";
        return ;
    }
    std::ofstream outfile((this->getNameFile() + "_shrubbery").c_str());
    {
    outfile <<
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\\n";
    outfile.close();
    }
}

std::string ShrubberyCreationForm::getNameFile(void) const{
    return (this->_name);
}

std::ostream &operator<<(std::ostream &oper, ShrubberyCreationForm *shru){
    oper << "Form " << shru->getNameFile() << "\nSign or Not: " << shru->getFormSign()
    << "\nsign level: " << shru->getSignLevel() << "\nExec level: " << shru->getExecLevel() << "\n";
    return oper;
}