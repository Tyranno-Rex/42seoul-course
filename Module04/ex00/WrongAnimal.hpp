#include "Animal.hpp"

class WrongAnimal
{
private:
protected:
    std::string type;
public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &ref);
    const WrongAnimal& operator=(const WrongAnimal &ref);
    virtual ~WrongAnimal(void);
    virtual void makeSound(void) const;
    std::string GetSpecies(void) const;
};