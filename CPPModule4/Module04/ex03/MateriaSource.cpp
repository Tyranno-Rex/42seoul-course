#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
    // std::cout<<"MateriaSource is Generated\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = other._materia[i]->clone();
    // std::cout<< "Copy: MateriaSource is Generated\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        if (this->_materia[i] != NULL)
        {
            delete this->_materia[i];
            this->_materia[i] = NULL;
        }
    for (int i = 0; i < 4; i++)
        if (other._materia[i] != NULL)
            this->_materia[i] = other._materia[i]->clone();
    // std::cout<< "Copy(=): MateriaSource is Generated\n";
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL)
        {
            delete this->_materia[i];
            this->_materia[i] = NULL;
        }
    }
    // std::cout<<"MateriaSource is Deleted\n";
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (m != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materia[i] == NULL)
            {
                this->_materia[i] = m;
                std::cout<<"MateriaSource " << m->getType()<<  " learned\n";
                return ; 
            }
        }
    }
    std::cout<<"MateriaSource can't learn\n";
}

AMateria*   MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] && type.compare(this->_materia[i]->getType()) == 0)
            return this->_materia[i]->clone();
    }
    return NULL;
}