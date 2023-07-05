# include <string>
# include <iostream>

# include "Animal.hpp"

class Dog : public Animal
{
private:
public:
    Dog (void);
	Dog (const Dog& to_copy);
    ~Dog(void);
    const Dog& operator=(const Dog &ref);
    void makeSound(void) const;
};