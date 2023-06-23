#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *newzombie;
    newzombie = new Zombie(name);
    return (newzombie); 
}