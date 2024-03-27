#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "\n-------------EX00 main start-------------\n";
	ClapTrap a, b("SeolA");
	std::cout << "\n";
	a.attack("seolA");
	b.takeDamage(7);
	b.beRepaired(2);
	std::cout << "\n";
	b.attack("eunseong");
	a.takeDamage(10);
	a.beRepaired(10);
	std::cout << "\n";

	ClapTrap a1;
	a1 = a;
	std::cout << a.GetName() << " : " << a1.GetName() << "\n";
	std::cout << a.GetHP() << " : " << a1.GetHP() << "\n";
	std::cout << a.GetEP() << " : " << a1.GetEP() << "\n";
	std::cout << a.GetAD() << " : " << a1.GetAD() << "\n";
	std::cout << "\n";
	return (0);
}