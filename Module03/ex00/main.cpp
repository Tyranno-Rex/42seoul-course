


#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a, b("seolA");
	std::cout << "\n";
	a.attack("seolA");
	b.takeDamage(7);
	b.beRepaired(2);
	std::cout << "\n";
	b.attack("eunseong");
	a.takeDamage(10);
	a.beRepaired(10);
	std::cout << "\n";
	return (0);
}