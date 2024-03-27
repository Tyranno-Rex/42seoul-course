#include "HumanA.hpp"

HumanA::HumanA(std::string NewName, Weapon &NewWeapon)
    :Human_Name(NewName), OnHandWeapon(NewWeapon)
{
}

HumanA::~HumanA(void)
{
    std::cout << Human_Name << "is destroyed" << "\n";
}

void HumanA::attack(void)
{
    std::cout << Human_Name << " uses " <<  OnHandWeapon.GetWeaponType() << " to attack" << "\n";
}