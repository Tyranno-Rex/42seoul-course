#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat Bae("bae", 31);
    ShrubberyCreationForm hello;
    hello.beSigned(Bae);
    hello.execute(Bae);
}