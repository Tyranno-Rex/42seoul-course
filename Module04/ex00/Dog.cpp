#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog is created\n";
}

Dog::Dog(const Dog &ref)
{
    std::cout << "Copy: Dog is created\n";
}

Dog::~Dog(void)
{
    std::cout << "Dog is extinct\n";
}

const Dog& Dog::operator=(const Dog &ref)
{
    std::cout << "= operator is Operation(Dog)\n";
    this->type = ref.type;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woof woof\n";
}