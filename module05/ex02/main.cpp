#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat Bae("bae", 50);
    Bureaucrat JYP("jyp", 1);

    ShrubberyCreationForm ShrubberyForm;
    RobotomyRequestForm RobotForm;
    PresidentialPardonForm PresidentialForm;


    std::cout << "\n\n";
    ShrubberyForm.beSigned(Bae);
    ShrubberyForm.signForm(Bae);
    ShrubberyForm.execute(Bae);

    std::cout << "\n\n";
    RobotForm.beSigned(Bae);
    RobotForm.signForm(Bae);
    RobotForm.execute(Bae);

    std::cout << "\n\n";
    PresidentialForm.beSigned(Bae);
    PresidentialForm.signForm(Bae);
    PresidentialForm.execute(Bae);

    std::cout << "\n\n";
    PresidentialForm.beSigned(JYP);
    PresidentialForm.signForm(JYP);
    PresidentialForm.execute(JYP);
}