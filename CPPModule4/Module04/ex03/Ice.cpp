#include "Ice.hpp"

Ice::Ice(void)
{
    this->type = "ice";
    // std::cout<<"Ice is Generated\n";
}

Ice::~Ice(void)
{
    // std::cout<<"Ice is Deleted\n"; 
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    this->type = other.type;
    // std::cout<<"Ice is Generated, type: " << this->type << "\n";
}

Ice&    Ice::operator=(const Ice& other)
{
    // std::cout<<"Copy: operator Ice is Generated\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

Ice*    Ice::clone(void) const 
{
    return new Ice(*this); 
}

//  Ice: "* shoots an ice bolt at <name> *"
void    Ice::use(ICharacter& ref)
{
    std::cout<<"* shoots an ice bolt at "<< ref.getName()<<"\n";
}