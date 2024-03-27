#include "Character.hpp"

Character::Character(void)
{
    this->Name = "";
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
    // std::cout<<"Character is Generated"<<"\n";
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] != NULL)
        {
            delete this->slot[i];
            this->slot[i] = NULL;
        }
    }
    // std::cout<<"Character is Deleted\n";
}

Character::Character(std::string const& name)
{
    this->Name = name;
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
    // std::cout<< "Character is Generated, name: " << this->Name << "\n";
}

Character::Character(const Character& other)
{
    this->Name = other.Name;
    for (int i = 0; i < 4; i++)
    {
        if (other.slot[i] != NULL)
            this->slot[i] = other.slot[i]->clone();
        else
            this->slot[i] = NULL;
    }
    // std::cout<<"Copy: Character is Generated\n";
}

Character&  Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->Name = other.Name;
        for (int i = 0; i < 4; i++)
        {
            if (this->slot[i] != NULL)
            {
                delete this->slot[i];
                this->slot[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.slot[i] != NULL)
                this->slot[i] = other.slot[i]->clone();
            this->slot[i] = NULL;
        }
        // std::cout<<"Copy: operator Character is Generated\n";
        return *this;
    }
    // std::cout<<"Copy: operator Character is Generated\n";
    return *this;
}

std::string const&  Character::getName(void) const 
{
    return this->Name;
}

void    Character::equip(AMateria* m)
{
    if (m != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->slot[i] == NULL)
            {
                this->slot[i] = m->clone();
                std::cout<<"Character "<< this->Name <<" equipped with " << i << " " << m->getType()<<"\n";
                return ;
            }
        }
        return ;
    }
    std::cout<<"Character " << this->Name << " can't equip\n";
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->slot[idx] != NULL)
    {
        delete this->slot[idx];
        this->slot[idx] = NULL;
        std::cout<<"Character "<< this->Name <<" unequipped\n";
        return ;
    }
    std::cout<<"Character "<< this->Name <<" can't unequip\n";
    return ;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->slot[idx] != NULL)
    {
        this->slot[idx]->use(target);
        std::cout<<"Character "<< this->Name << " uses " << this->slot[idx]->getType() << "\n";
    }
    else
        std::cout<<"There is nothing to use at this index\n";
}