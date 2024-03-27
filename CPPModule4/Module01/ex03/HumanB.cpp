#include "HumanB.hpp"

HumanB::HumanB(std::string Newname)
:Human_name(Newname)
{}

HumanB::~HumanB(void)
{
    std::cout << Human_name << "is destroyed\n";
}

void HumanB::attack(void)
{
    std::cout << Human_name << " uses " <<  OnHandWeapon->GetWeaponType() << " to attack" << "\n";
}

void HumanB::InitWeaponType(Weapon &NewWeapon)
{
    OnHandWeapon = &NewWeapon;
}