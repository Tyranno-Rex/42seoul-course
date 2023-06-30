#include "Weapon.hpp"

Weapon::Weapon(const std::string &newType):type(newType)
{
}

Weapon::~Weapon(void)
{
    // std::cout << "Weapon Type " <<  type << "is destroyed\n";
}

void Weapon::InitWeaponType(const std::string &Type)
{
    type = Type;
}

const std::string Weapon::GetWeaponType(void)
{
    std::cout << "Weapon type is " <<  type << "\n";
    return (type);
}