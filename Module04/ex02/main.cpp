#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void leak()
// {
//     system("leaks --list ex01");
// }

int main()
{
    const Animal*   i = new Cat();
    const Animal*   j = new Dog();

    std::cout<<i->GetSpecies()<<std::endl;
    std::cout<<j->GetSpecies()<<std::endl;
    
    i->makeSound();
    j->makeSound();

    delete j;
    delete i;
    std::cout<<"---------------------"<<std::endl;
    std::cout<<std::endl;

    const int animalCount = 4;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount; ++i)
    {
        if (i % 2 == 0)
        {
            std::cout<<"🐕 New Dog creation"<<std::endl;
            animals[i] = new Dog();
            std::cout<<"---------------------"<<std::endl;
        }
        else
        {
            std::cout<<"🐱 New Cat creation"<<std::endl;
            animals[i] = new Cat();
            std::cout<<"---------------------"<<std::endl;
        }
    }
    std::cout<<"All animals are destroyed"<<std::endl;
    for (int i = 0; i < animalCount; ++i)
        delete animals[i];
    return 0;
}