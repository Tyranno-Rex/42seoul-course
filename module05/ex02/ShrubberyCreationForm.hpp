#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
private:
    const std::string _name;

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(ShrubberyCreationForm &name);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
    std::string getNameFile(void) const;
    void execute(Bureaucrat const &executer);
};