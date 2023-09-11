#include "Form.hpp"

int main()
{
    Bureaucrat Bae("bae", 31);
    Form nmixx;
    Form docs1(40, "new album", false);

    // std::cout << nmixx.getFormLevel() << "\n";
    // std::cout << nmixx.getFormName() << "\n";
    // nmixx.beSigned(Bae);
    // std::cout << "\n\n";

    std::cout << "Docs name is " << docs1.getFormName() << " and level is " << docs1.getFormLevel() << "\n";
    nmixx.beSigned(Bae);
}