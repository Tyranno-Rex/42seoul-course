#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "\n-------------EX01 main start-------------\n";
	{
		ScavTrap c, d("SeolA_ST");
		std::cout << "\n";
		c.attack(d.GetName());
		d.takeDamage(20);
		d.beRepaired(20);
		c.guardGate();
		std::cout << "\n";
		d.attack(c.GetName());
		d.attack(c.GetName());
		c.takeDamage(20);
		c.takeDamage(20);
		c.beRepaired(5);
		d.guardGate();
		std::cout << "\n";

		ScavTrap c1;
		c1 = c;
		std::cout << c.GetName() << " : " << c1.GetName() << "\n";
		std::cout << c.GetHP() << " : " << c1.GetHP() << "\n";
		std::cout << c.GetEP() << " : " << c1.GetEP() << "\n";
		std::cout << c.GetAD() << " : " << c1.GetAD() << "\n";
	}
}