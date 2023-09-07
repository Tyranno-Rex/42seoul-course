#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Eunseong;
    Bureaucrat Bae(31);
    Bureaucrat Haeone("haeone");
    Bureaucrat Sullyoon("sullyoon", 120);

    // 
    Bureaucrat lily("lily", 200);
    Bureaucrat Kyujin("Kyujin", 0);

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Default Name is     " << Eunseong.getName() << "\n";
    std::cout << "Default Grade is    " << Eunseong.getGrade() << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Bae's Name is     " << Bae.getName() << "\n";
    std::cout << "Bae's Grade is    " << Bae.getGrade() << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Haeone's Name is     " << Haeone.getName() << "\n";
    std::cout << "Haeone's Grade is    " << Haeone.getGrade() << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Sullyoon's Name is     " << Sullyoon.getName() << "\n";
    std::cout << "Sullyoon's Grade is    " << Sullyoon.getGrade() << "\n";
}