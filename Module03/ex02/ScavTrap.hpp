#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& name);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap &ref);
    virtual void attack(const std::string& target);
    void guardGate();
};

