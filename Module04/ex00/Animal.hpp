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
    const Animal& operator=(const Animal &ref);
    virtual ~Animal(void);
    virtual void makeSound(void) const;
    std::string GetSpecies(void) const;
};
