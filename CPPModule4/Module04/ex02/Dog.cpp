#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    this->DogBrain = new Brain();
    this->DogBrain->setAllIdea("i want to eat bones");
    std::cout << "Dog is created\n";
}

Dog::Dog(const Dog &ref) : Animal(ref)
{
    this->DogBrain = new Brain();
    this->DogBrain->setAllIdea("i want to eat bones");
    std::cout << "Copy: Dog is created\n";
}

Dog::~Dog(void)
{
    delete this->DogBrain;
    std::cout << "Dog is extinct\n";
}

Dog& Dog::operator=(const Dog &ref)
{
    std::cout << "= operator is Operation(Dog)\n";
    this->type = ref.type;
    delete this->DogBrain;
    this->DogBrain = new Brain();
    for (int i = 0; i < 100; i++)
        DogBrain->setAllIdea(ref.GetDogIdea(i));
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woof woof\n";
}

void Dog::setDogIdea(int i, std::string &DogIdea)
{
    DogBrain->setIdea(i, DogIdea);
}

std::string Dog::GetDogIdea(int i) const
{
    return (DogBrain->GetIdea(i));
}