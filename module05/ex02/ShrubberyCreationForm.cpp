#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137), _name("default_name"){
    std::cout << this->_name << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): Form("ShrubberyCreationForm", 145, 137), _name(name){
    std::cout << this->_name << "\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    std::cout << this->_name << " is deleted\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer){
    if (this->isSigned() == false){
        std::cout << "this form isn't signed\n";
        std::cout << "go sign first\n";
        return ;
    }

    if (executer.getGrade() < 137){
        std::cout << "you can assign the this form\n";
    }
    else{
        std::cout << "you can't assign the this form\n";
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