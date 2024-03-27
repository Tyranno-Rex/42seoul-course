#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string Name;
        AMateria*   slot[4];

    public:
        Character(void);
        ~Character(void);
        Character(std::string const& name);
        Character(const Character& other);
        Character& operator=(const Character& other);

        std::string const&  getName(void) const;
        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);
};

#endif