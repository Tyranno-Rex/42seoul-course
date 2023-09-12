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

std::string ShrubberyCreationForm::getName(void) const{
    return (this->_name);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer){
    // 145 137
    // if (executer.getGrade())
    
}


ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137), _name("default_name")
{
    std::cout << this->_name << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): _name(name)
{
    std::cout << this->_name << "\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << this->_name << " is deleted\n";
}