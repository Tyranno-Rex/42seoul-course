# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
    WrongCat (void);
	WrongCat (const WrongCat &ref);
    ~WrongCat(void);
    const WrongCat& operator=(const WrongCat &ref);
    void makeSound(void) const;
};