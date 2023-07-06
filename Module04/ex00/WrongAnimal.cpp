#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal is created\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
    this->type = ref.type;
    std::cout << "Copy: WrongAnimal is created\n";
}

const WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref)
{
    std::cout << "= operator is Operation\n";
    this->type = ref.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal is extinction\n";
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "hhdidhidmksadnfiosd\n";
}

std::string WrongAnimal::GetSpecies(void) const
{
    std::cout << "This WrongAnimal's Species is " << this->type << "\n";
    return (this->type);
}