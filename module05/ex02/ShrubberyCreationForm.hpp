#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
private:
    std::string _name;

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(ShrubberyCreationForm &name);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
    std::string getName(void) const;
    void execute(Bureaucrat const &executer);
};

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
    }
    if (executer.getGrade() < 137){
        std::cout << "you can assign the this form\n";
    }
    else{
        std::cout << "you can't assign the this form\n";
    }
}

std::string ShrubberyCreationForm::getName(void) const{
    return (this->_name);
}