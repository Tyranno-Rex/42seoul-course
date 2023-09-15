#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat Bae("bae", 31);
    Bureaucrat JYP("jyp", 1);

    ShrubberyCreationForm ShrubberyForm;
    RobotomyRequestForm RobotForm;
    PresidentialPardonForm PresidentialForm;
    Intern *intern = new Intern();

    Form *newAlbum = intern->makeForm("ShrubberyCreationForm", "newAlbum");

    std::cout << "\n\n";
    std::cout << newAlbum->getFormName();
    std::cout << "\n\n";
}