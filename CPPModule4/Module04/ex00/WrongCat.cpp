#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat is created\n";
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal(ref)
{
    this->type = ref.type;
    std::cout << "Copy: WrongCat is created\n";
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat is extinct\n";
}

const WrongCat& WrongCat::operator=(const WrongCat &ref)
{
    std::cout << "= operator is Operation(WrongCat)\n";
    this->type = ref.type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meowg Meowg\n";
}