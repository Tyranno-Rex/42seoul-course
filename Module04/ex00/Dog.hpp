#ifndef DOG_HPP
#define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
private:
public:
    Dog (void);
	Dog (const Dog &ref);
    ~Dog(void);
    Dog& operator=(const Dog &ref);
    virtual void makeSound(void) const;
};
#endif