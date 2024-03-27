#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat Bae("bae", 30);
    Bureaucrat JYP("jyp", 1);

    ShrubberyCreationForm ShrubberyForm;
    RobotomyRequestForm RobotForm;
    PresidentialPardonForm PresidentialForm;


    std::cout << "\n\n";
    ShrubberyForm.beSigned(Bae);
    Bae.signForm(ShrubberyForm);
    ShrubberyForm.execute(Bae);

    std::cout << "\n\n";
    RobotForm.beSigned(Bae);
    Bae.signForm(RobotForm);
    RobotForm.execute(Bae);

    std::cout << "\n\n";
    PresidentialForm.beSigned(Bae);
    Bae.signForm(PresidentialForm);
    PresidentialForm.execute(Bae);

    std::cout << "\n\n";
    PresidentialForm.beSigned(JYP);
    JYP.signForm(PresidentialForm);
    PresidentialForm.execute(JYP);
}