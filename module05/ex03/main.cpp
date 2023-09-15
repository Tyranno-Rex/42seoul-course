#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat Bae("bae", 31);
    Bureaucrat JYP("jyp", 1);

    Intern *intern = new Intern();
    
    AForm *newAlbum1 = intern->makeForm("ShrubberyCreationForm", "DICE");
    AForm *newAlbum2 = intern->makeForm("RobotomyRequestForm", "Love me like this");
    AForm *newAlbum3 = intern->makeForm("PresidentialPardonForm", "Party O'Clock");

    std::cout << "\n\n";

    std::cout << "new album [Dice] is Created\n";
    std::cout << "new album name                :" << newAlbum1->getFormName() << "\n";
    std::cout << "new album grade(sign)         :" << newAlbum1->getSignLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum1->getExecLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum1->getFormSign() << "\n";
    newAlbum1->beSigned(Bae);
    newAlbum1->execute(Bae);

    std::cout << "\n\n";
    std::cout << "new album [Love me like this] is Created\n";
    std::cout << "new album name                :" << newAlbum2->getFormName() << "\n";
    std::cout << "new album grade(sign)         :" << newAlbum2->getSignLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum2->getExecLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum2->getFormSign() << "\n";
    newAlbum2->execute(Bae);

    std::cout << "\n\n";
    std::cout << "new album [Party O'Clock] is Created\n";
    std::cout << "new album name                :" << newAlbum3->getFormName() << "\n";
    std::cout << "new album grade(sign)         :" << newAlbum3->getSignLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum3->getExecLevel() << "\n";
    std::cout << "new album grade(exec)         :" << newAlbum3->getFormSign() << "\n";
    newAlbum3->execute(Bae);


    std::cout << "\n\n";
}