#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *DogBrain;
public:
    Dog (void);
	Dog (const Dog &ref);
    ~Dog(void);
    Dog& operator=(const Dog &ref);

    virtual void makeSound(void) const;
    void setDogIdea(int i, std::string &DogIdea);
    std::string GetDogIdea(int i) const;
};
#endif