#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(), name(ClapTrap::name) 
{
	ClapTrap::name += "_clap_name";
	ClapTrap::AttackDamage = 30;
	std::cout << "DiamondTrap_Name : " << this->name << "\n";
}

DiamondTrap::DiamondTrap(std::string const &ref): ClapTrap(ref), ScavTrap(ref), FragTrap(ref),  name(ref) 
{
	ClapTrap::name += "_clap_name";
	ClapTrap::AttackDamage = 30;
	std::cout << "DiamondTrap_Name : " << this->name << "\n";
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << "DiamondTrap " << this->name << " has been destroyed." << "\n";
}

void	DiamondTrap::attack(std::string const & target) 
{
	ScavTrap::attack(target);
}

DiamondTrap&	DiamondTrap::operator=( DiamondTrap const& Diamond) 
{
	ClapTrap::operator=(Diamond);
	std::cout << "DiamondTrap " << this->name << " operator= is called" << "\n";
	return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTraps name is " << this->name << "\n";
	std::cout << "ClapTraps    name is " << this->ClapTrap::name << "\n";
	std::cout << "HitPoints: " << this->Hitpoint << "\n";
	std::cout << "EnergyPoints: " << this->EnergyPoint << "\n";
	std::cout << "AttackDamage: " << this->AttackDamage << "\n";
}