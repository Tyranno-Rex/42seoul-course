#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << "Cat is created\n";
}

Cat::Cat(const Cat &ref) : Animal(ref)
{
    this->type = ref.type;
    std::cout << "Copy: Cat is created\n";
}

Cat::~Cat(void)
{
    std::cout << "Cat is extinct\n";
}

Cat& Cat::operator=(const Cat &ref)
{
    std::cout << "= operator is Operation(Cat)\n";
    this->type = ref.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow Meow\n";
}