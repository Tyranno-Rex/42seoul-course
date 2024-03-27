#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
:ClapTrap::ClapTrap("eunseong_ST", 100, 50, 20)
{
    std::cout << "eunseong_ST is Generated(ScavTrap)\n";
}

ScavTrap::ScavTrap(std::string name)
:ClapTrap::ClapTrap(name, 100, 50, 20)
{
    std::cout << name << " is Generated(ScavTrap)\n";
}

ScavTrap::ScavTrap(const ScavTrap &ref)
:ClapTrap::ClapTrap(ref)
{
    std::cout << name << " is Generated(ScavTrap)\n";
}


void ScavTrap::attack(const std::string& target)
{
    if (this->EnergyPoint)
    {
        std::cout << "ScavTrap: " << this->name << " attack " << target << ", causing " << this->AttackDamage << " points of damage!\n";
		this->EnergyPoint--;
    }
    else
        std::cout << this->name << " has no energy\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
    this->name = ref.name;
    this->EnergyPoint = ref.EnergyPoint;
    this->Hitpoint = ref.Hitpoint;
    this->AttackDamage = ref.AttackDamage;
    return (*this);
}

void ScavTrap::guardGate(void)
{
    std::cout << name << "is in GuardGate mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << name << " is deleted(ScavTrap)\n";
}