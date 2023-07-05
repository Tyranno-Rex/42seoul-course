#include "ScavTrap.hpp"

int	main(void)
{
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
	}
	std::cout << "\n\n\n\n\n";
	{
		ScavTrap c, d("SeolA_ST");
		std::cout << "\n";
		c.attack(d.GetName());
		d.takeDamage(20);
		d.beRepaired(20);
		c.guardGate();
		std::cout << "\n";
		d.attack(c.GetName());
		c.takeDamage(10);
		c.beRepaired(5);
		d.guardGate();
		std::cout << "\n";
	}
}