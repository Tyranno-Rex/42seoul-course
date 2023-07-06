#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void leak()
{
    system("leaks --list ex03");
}

int main()
{
    // atexit(leak);
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp1;
    AMateria* tmp2;
    tmp1 = src->createMateria("ice");
    me->equip(tmp1);
    me->equip(tmp1);
    tmp2 = src->createMateria("cure");
    me->equip(tmp2);
    me->equip(tmp2);
    
    me->unequip(4);
    ICharacter* bob = new Character("bob");
    for (int i = 0; i < 4; i++)
        me->use(i, *bob);

    delete bob;
    delete tmp1;
    delete tmp2;
    delete me;
    delete src;
    return 0;
}