#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: virtual public ClapTrap, public ScavTrap, public FragTrap
{
private:
    std::string name;
public:
    DiamondTrap(void);
    virtual ~DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap *ref);
    DiamondTrap &operator=(const DiamondTrap &ref);
    void attack(const std::string &target);
    void whoAmI(void);
};

DiamondTrap::DiamondTrap(void): ClapTrap(), FragTrap(), ScavTrap()
{	
	std::cout << "Default Constructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "Parameterized Constructor of DiamondTrap called" << std::endl;
	this->name = name;
	this->Hitpoint = FragTrap::GetHP();      
	this->EnergyPoint = ScavTrap::GetEP();
	this->AttackDamage = FragTrap::GetAD();
}

DiamondTrap::~DiamondTrap() 
{	
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& ref)
{
	std::cout << "Operator assignment of DiamondTrap called" << std::endl;
	if (this == &ref)
		return (*this);
	this->ClapTrap::name = ref.ClapTrap::name;
	this->name = ref.name;
	Hitpoint = ref.Hitpoint;
	EnergyPoint = ref.EnergyPoint;
	AttackDamage = ref.AttackDamage;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap&	ref)
	:	ClapTrap(ref),
		FragTrap(ref),
		ScavTrap(ref)
{
	std::cout << "Copy Constructor of FragTrap called" << std::endl;
	this->ClapTrap::name = ref.ClapTrap::name;
	this->name = ref.name;
	Hitpoint    = ref.Hitpoint;
	EnergyPoint = ref.EnergyPoint;
	AttackDamage = ref.AttackDamage;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTraps name is " << this->name << std::endl;
	std::cout << "ClapTraps    name is " << this->ClapTrap::name << std::endl;
	std::cout << "HitPoints: " << this->Hitpoint << std::endl;
	std::cout << "EnergyPoints: " << this->EnergyPoint << std::endl;
	std::cout << "AttackDamage: " << this->AttackDamage << std::endl;
}