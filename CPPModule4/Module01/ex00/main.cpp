#include "Zombie.hpp"


int main()
{
    std::cout << "first Zombie eunseong\n";
    Zombie zombie1("eunseong");
    zombie1.announce();

    std::cout << "\nRandomChump function make Extra Zombie\n";
    for (int i = 0; i < 5; i++)
    {
        std::stringstream ss;
        ss << "ExtraZombie" << i;
        std::string InstanceZombie = ss.str();
        randomChump(InstanceZombie);
    }
    
    std::cout << "\nNewZombie function make Extra Zombie\n";
    Zombie *zombie2;
    zombie2 = newZombie("eunjeong");
    zombie2->announce();
    delete zombie2;
    return (0);
}