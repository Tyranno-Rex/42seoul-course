#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n\n\n";
    const Animal*   meta = new Animal();
    const Animal*   i = new Cat();
    const Animal*   j = new Dog();

    std::cout<<i->GetSpecies()<<std::endl;
    std::cout<<j->GetSpecies()<<std::endl;

    meta->makeSound();
    i->makeSound();
    j->makeSound();

    delete j;
    delete i;
    delete meta;


    std::cout << "\n\n\n";
    const WrongAnimal*  w_meta = new WrongAnimal();
    const WrongAnimal*     w_i = new WrongCat();

    std::cout<<w_i->GetSpecies()<<std::endl;
    
    w_meta->makeSound();
    w_i->makeSound();

    delete w_i;
    delete w_meta;
    return 0;
}