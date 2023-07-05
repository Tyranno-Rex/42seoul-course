#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string     name;
    unsigned int    Hitpoint;
    unsigned int    EnergyPoint;
    unsigned int    AttackDamage;

public:
    virtual ClapTrap(void);
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap& ref);
    ClapTrap& operator=(const ClapTrap &ref);
    virtual ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
