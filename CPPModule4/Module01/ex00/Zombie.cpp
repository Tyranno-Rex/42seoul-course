#include "Zombie.hpp"

Zombie::Zombie(const std::string &_name):
    name(_name)
{
}

Zombie::~Zombie(void)
{
std::cout << name << ": deleted\n";
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}