#ifndef CAT_HPP
#define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *CatBrain;

public:
    Cat (void);
    ~Cat(void);
	Cat (const Cat &ref);
    Cat& operator=(const Cat &ref);

    virtual void makeSound(void) const;
    void setCatIdea(int i, std::string &CatIdea);
    std::string GetCatIdea(int i) const;
};

#endif