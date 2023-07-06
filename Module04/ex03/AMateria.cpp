#include "AMateria.hpp"

AMateria::AMateria(void) : type("")
{
    // std::cout<<"AMaterial is Generated\n";
}

AMateria::~AMateria(void) 
{
    // std::cout<<"AMateria is Deleted"<<"\n"; 
}

AMateria::AMateria(std::string const &ref)
{
    this->type = ref;
    // std::cout<<"AMaterial is Generated, type: " << this->type << "\n";
}

AMateria::AMateria(const AMateria& ref)
{
    this->type = ref.type;
    // std::cout<<"Copy: AMaterial is Generated\n";
}

AMateria&   AMateria::operator=(const AMateria& other)
{
    // std::cout<<"Copy: operator AMaterial is Generated\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string const&  AMateria::getType(void) const 
{ 
    return this->type;
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
}