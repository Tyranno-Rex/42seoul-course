
#include "FragTrap.hpp"



FragTrap::FragTrap()
:ClapTrap::ClapTrap("eunseong_FT", 100, 100, 30)
{
    std::cout << "eunseong_FT is Generated(FragTrap)\n";
}

FragTrap::FragTrap(std::string name)
:ClapTrap::ClapTrap(name, 100, 100, 30)
{
    std::cout << name << " is Generated(FragTrap)\n";
}

FragTrap::FragTrap(const FragTrap &ref)
:ClapTrap::ClapTrap(ref)
{
    std::cout << name << " is Generated(FragTrap)\n";
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
    this->name = ref.name;
    this->EnergyPoint = ref.EnergyPoint;
    this->Hitpoint = ref.Hitpoint;
    this->AttackDamage = ref.AttackDamage;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << name << "HIGH FIVE!\n";
    std::cout << name << "HIGH FIVE!\n";
    std::cout << name << "HIGH FIVE!\n";
    std::cout << name << "HIGH FIVE!\n";
    std::cout << name << "HIGH FIVE!\n";
}

FragTrap::~FragTrap()
{
    std::cout << name << " is deleted(FragTrap)\n";
}