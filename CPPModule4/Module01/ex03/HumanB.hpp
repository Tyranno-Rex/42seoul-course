#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanB
{
private:
    std::string Human_name;
    Weapon *OnHandWeapon;
public:
    HumanB(std::string Newname);
    ~HumanB(void);

    void attack(void);
    void InitWeaponType(Weapon &NewWeapon);
};

#endif