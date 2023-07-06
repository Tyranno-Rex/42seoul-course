#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
int	main(void)
{
	{
		DiamondTrap e, f("SeolA_DMT");
		std::cout << "\n";
		
		e.attack(f.GetName());
		f.takeDamage(30);
		f.beRepaired(20);
		
		std::cout << "\n";
		e.highFivesGuys();
		std::cout << "\n";
		
		f.attack(e.GetName());
		e.takeDamage(30);
		e.beRepaired(15);

		std::cout << "\n";
		f.highFivesGuys();
		std::cout << "\n";

		std::cout << "e who am i?\n";
		e.whoAmI();
		std::cout << "\n\n";
		std::cout << "f who am i?\n";
		f.whoAmI();
		std::cout << "\n\n";
	}
}