#include "Zombie.hpp"

int main()
{
    Zombie *zombies;

    int number;
    std::string name;
    std::cout << "Enter the number and names of zombies you want to create:\n";
    std::cout << "number:\t";
    std::cin >> number;
    std::cout << "name  :\t";
    std::cin >> name;

    zombies = zombieHorde(number, name);
    for (int i = 0; i < number; i++)
        zombies[i].announce();
    delete[] zombies;

    system("leak Zombie");
    return (0);
}