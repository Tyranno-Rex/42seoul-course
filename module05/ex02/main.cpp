#include "AForm.hpp"

int main()
{
    Bureaucrat Bae("bae", 31);
    Form nmixx;
    Form docs1("new album", 10, 10);

    nmixx.beSigned(Bae);
    nmixx.signForm(Bae);
    
    docs1.beSigned(Bae);
    docs1.signForm(Bae);
}