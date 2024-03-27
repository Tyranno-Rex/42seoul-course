#include "Zombie.hpp"


Zombie::Zombie(const std::string &newname):
name(newname)
{
}

Zombie::~Zombie(void)
{
    std::cout << name << ": deleted" << std::endl;
}

void Zombie::MakeZombieName(std::string &newname)
{
    name = newname;
}

void Zombie::announce(void)
{
    std::cout << name  << ": Zombie name" << std::endl;
}