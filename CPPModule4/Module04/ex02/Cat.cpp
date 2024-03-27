#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    this->CatBrain = new Brain();
    this->CatBrain->setAllIdea("i want to eat fish");
    std::cout << "Cat is created\n";
}

Cat::Cat(const Cat &ref) : Animal(ref)
{
    this->CatBrain = new Brain();
    this->CatBrain->setAllIdea("i want to eat fish");
    std::cout << "Copy: Cat is created\n";
}

Cat::~Cat(void)
{
    delete this->CatBrain;
    std::cout << "Cat is extinct\n";
}

Cat& Cat::operator=(const Cat &ref)
{
    std::cout << "= operator is Operation(Cat)\n";
    this->type = ref.type;
    delete this->CatBrain;
    this->CatBrain = new Brain();
    for (int i = 0; i < 100; i++)
        CatBrain->setAllIdea(ref.GetCatIdea(i));
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow Meow\n";
}

void Cat::setCatIdea(int i, std::string &CatIdea)
{
    CatBrain->setIdea(i, CatIdea);
}

std::string Cat::GetCatIdea(int i) const
{
    return (CatBrain->GetIdea(i));
}