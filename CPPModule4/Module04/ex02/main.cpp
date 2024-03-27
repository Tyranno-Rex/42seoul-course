#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void leak()
// {
//     system("leaks --list ex01");
// }

int main()
{
    const int animalCount = 4;
    Animal* animals[animalCount];
    Dog *dog;
    Cat *cat;
    const std::string statement = "I'm Full\n";

    std::cout << "-----------------------\n";
    std::cout<<"\nDog is Generated\n";
    animals[0] = new Dog();
    animals[0]->makeSound();
    // 다이나믹 케스트로 dog를 클래스 형식을 가져옴
    dog = dynamic_cast<Dog*>(animals[0]);
    std::cout << dog->GetDogIdea(0) << "\n";
    std::string dogIdea = statement;
    dog->setDogIdea(0, dogIdea);
    std::cout << dog->GetDogIdea(0);

    std::cout << "-----------------------\n";
    std::cout<<"Cat is Generated\n";
    animals[1] = new Cat();
    animals[1]->makeSound();

        // 다이나믹 케스트로 dog를 클래스 형식을 가져옴
    cat = dynamic_cast<Cat*>(animals[1]);
    std::cout << cat->GetCatIdea(1) << "\n";
    
    
    std::cout << "-----------------------\n";
    std::cout<<"All animals are destroyed"<<"\n";
    for (int i = 0; i < animalCount; ++i)
        delete animals[i];
    return 0;
}