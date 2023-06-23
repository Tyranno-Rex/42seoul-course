#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
private:
    std::string name;
public:
    Zombie(const std::string &_name = "");
    ~Zombie(void);
    void announce(void);
};

Zombie::Zombie(const std::string &_name):
    name(_name)
{
}

Zombie::~Zombie(void)
{
std::cout << ": deleted\n";
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif