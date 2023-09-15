#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat Bae("bae", 31);
    Bureaucrat JYP("jyp", 1);

    Intern *intern = new Intern();
    
    Form *newAlbum1 = intern->makeForm("ShrubberyCreationForm", "DICE");
    Form *newAlbum2 = intern->makeForm("RobotomyRequestForm", "Love me like this");
    Form *newAlbum3 = intern->makeForm("PresidentialPardonForm", "Party O'Clock");

    std::cout << "\n\n";

    std::cout << "new album Dice is Created\n";
    std::cout << "new album name                :" << newAlbum1->getFormName() << "\n";
    std::cout << "new album grade(sign)         :" << newAlbum1->getFormLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum1->getFormLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum1->getFormLevel() << "\n";

    newAlbum1->execute(*Bae);

    std::cout << "\n\n";
}