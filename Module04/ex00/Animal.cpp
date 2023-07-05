#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal is created\n";
}

Animal::Animal(const Animal &ref)
{
    std::cout << "Copy: Animal is created\n";
}

const Animal& Animal::operator=(const Animal &ref)
{
    std::cout << "= operator is Operation\n";
    this->type = ref.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal is extinction\n";
}

void Animal::makeSound(void) const
{
    std::cout << "hahahahah\n";
}

std::string Animal::GetSpecies(void) const
{
    std::cout << "This Animal's Species is " << this->type << "\n";
    return (this->type);
}