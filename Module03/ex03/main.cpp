#include "FragTrap.hpp"

int	main(void)
{
	{
		ClapTrap a, b("seolA");
		std::cout << "\n";
		a.attack("seolA");
		b.takeDamage(0);
		b.beRepaired(0);
		std::cout << "\n";
		b.attack("eunseong");
		a.takeDamage(0);
		a.beRepaired(0);
		std::cout << "\n";
	}
	std::cout << "\n\n\n\n\n";
	{
		ScavTrap c, d("SeolA_ST");
		std::cout << "\n";
		c.attack(d.GetName());
		d.takeDamage(20);
		d.beRepaired(10);
		c.guardGate();
		std::cout << "\n";
		d.attack(c.GetName());
		c.takeDamage(20);
		c.beRepaired(5);
		d.guardGate();
		std::cout << "\n";
	}
	std::cout << "\n\n\n\n\n";
	{
		FragTrap e, f("SeolA_GT");
		std::cout << "\n";
		e.attack(f.GetName());
		f.takeDamage(30);
		f.beRepaired(20);
		e.highFivesGuys();
		std::cout << "\n";
		f.attack(e.GetName());
		e.takeDamage(30);
		e.beRepaired(15);
		f.highFivesGuys();
		std::cout << "\n";
	}
}