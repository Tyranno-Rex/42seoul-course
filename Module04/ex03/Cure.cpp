#include "Cure.hpp"

Cure::Cure(void)
{
    this->type = "cure";
    // std::cout<<"Cure is Generated\n";
}

Cure::Cure(const Cure& other) : AMateria(other) 
{
    this->type = other.type;
    // std::cout<<"Copy: Cure is Generated\n";
}

Cure&    Cure::operator=(const Cure& other)
{
    // std::cout<<"Copy(=): Cure is Generated\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

Cure::~Cure(void) 
{
    // std::cout<<"Cure is Deleted\n";
}

Cure*    Cure::clone(void) const 
{
    return new Cure(*this); 
}

void    Cure::use(ICharacter& target)
{
    std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<"\n";
}