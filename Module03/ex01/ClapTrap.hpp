#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string     name;
    unsigned int    Hitpoint;
    unsigned int    EnergyPoint;
    unsigned int    AttackDamage;
    ClapTrap(std::string Name, int HP, int EP, int AD);

public:
    ClapTrap(void);
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap& ref);
    ClapTrap& operator=(const ClapTrap &ref);
    virtual ~ClapTrap();

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    const std::string GetName();
    int GetHP() const;
    int GetEP() const;
    int GetAD() const;
};
