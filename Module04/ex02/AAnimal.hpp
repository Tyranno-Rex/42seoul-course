#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
private:
protected:
    std::string type;
public:
    Animal(void);
    Animal(const Animal &ref);
    Animal& operator=(const Animal &ref);
    virtual ~Animal(void);
    virtual void makeSound(void) const = 0;
    std::string GetSpecies(void) const;
};

#endif