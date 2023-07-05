#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
	FragTrap();					
	FragTrap(std::string name);
	FragTrap (const FragTrap &ref);				
	FragTrap& operator=(const FragTrap& ref);		
	~FragTrap();							
	void highFivesGuys(void);
};
