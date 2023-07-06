#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "\n-------------EX03 main start-------------\n";
	{
		FragTrap e, f("SeolA_GT");
		std::cout << "\n";
		e.attack(f.GetName());
		f.takeDamage(30);
		f.beRepaired(20);
		std::cout << "\n";
		f.attack(e.GetName());
		e.takeDamage(30);
		e.beRepaired(15);
		std::cout << "\n";


		std::cout << "\n\n";
		e.highFivesGuys();
		f.highFivesGuys();
		std::cout << "\n\n";


		FragTrap e1;
		e1 = e;
		std::cout << e.GetName() << " : " << e1.GetName() << "\n";
		std::cout << e.GetHP() << " : " << e1.GetHP() << "\n";
		std::cout << e.GetEP() << " : " << e1.GetEP() << "\n";
		std::cout << e.GetAD() << " : " << e1.GetAD() << "\n";
		std::cout << "\n\n";
	}
}