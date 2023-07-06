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
	DiamondTrap(std::string const &ref);
    // DiamondTrap(DiamondTrap *ref);
    DiamondTrap &operator=(const DiamondTrap &ref);
    void attack(const std::string &target);
    void whoAmI(void);
};
