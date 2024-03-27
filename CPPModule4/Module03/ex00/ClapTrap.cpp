// ClapTrap <name> attacks <target>, causing <damage> points of damage!
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:name("eunseong"), Hitpoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "eunseong is Generated\n";
}

ClapTrap::ClapTrap(std::string Name)
:name(Name), Hitpoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << name << " is Generated\n";
}

ClapTrap::ClapTrap(const ClapTrap& ref)
:name(ref.name), Hitpoint(ref.Hitpoint), EnergyPoint(ref.EnergyPoint), AttackDamage(ref.AttackDamage)
{
    std::cout << "Copy: " << name << "is Generated\n"; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
    this->name = ref.name;
    this->EnergyPoint = ref.EnergyPoint;
    this->Hitpoint = ref.Hitpoint;
    this->AttackDamage = ref.AttackDamage;
    std::cout <<  "Copy: " << this->name << "is Generated\n";
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << name << " is deleted\n";
}


void ClapTrap::attack(const std::string &traget)
{
    if (this->EnergyPoint)
    {
        std::cout << "ClapTrap: " << this->name << " attack " << traget << " and " << this->AttackDamage << " damage\n";
		this->EnergyPoint--;
    }
    else
        std::cout << this->name << " has no energy\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->Hitpoint)
		this->Hitpoint = 0;
	else
		this->Hitpoint -= amount;
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage\n";
	if (this->Hitpoint == 0)
	{
		std::cout	<< "ClapTrap " << this->name << " is died" << std::endl; 
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyPoint > 0)
    {
        if (this->Hitpoint + amount > 10)
            this->Hitpoint = 10;
        else
            this->Hitpoint += amount;
        this->EnergyPoint--;
        std::cout << "ClapTrap is Repaired.\n" << this->name << " HitPoint: " << this->Hitpoint <<  "\n";
    }
    else    
        std::cout << "ClapTrap has low energy, can't Repaired\n";
}


const std::string ClapTrap::GetName()
{
	return (this->name);
}

int ClapTrap::GetHP() const
{
	return(this->Hitpoint);
}
int ClapTrap::GetEP() const
{
	return(this->EnergyPoint);
}
int ClapTrap::GetAD() const
{
	return(this->AttackDamage);
}