#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << "Animal is created\n";
}

Animal::Animal(const Animal &ref)
{
    this->type = ref.type;
    std::cout << "Copy: Animal is created\n";
}

Animal& Animal::operator=(const Animal &ref)
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