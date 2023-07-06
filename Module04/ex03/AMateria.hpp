#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

// class AMateria
// {
// protected:
        // [...] 
// public:
        // AMateria(std::string const & type); [...]
        // std::string const & getType() const; //Returns the materia type
        // virtual AMateria* clone() const = 0;
// };

class AMateria
{
protected:
    std::string type;
public:
    AMateria(void);
    virtual ~AMateria(void);
    AMateria(std::string const& ref);
    AMateria(const AMateria& ref);
    AMateria& operator=(const AMateria& ref);

    std::string const& getType(void) const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif