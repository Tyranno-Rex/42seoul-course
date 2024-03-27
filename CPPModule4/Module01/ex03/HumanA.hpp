#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanA
{
private:
    std::string Human_Name;
    Weapon &OnHandWeapon;
public:
    HumanA(std::string NewName, Weapon &NewWeapon);
    ~HumanA(void);

    void attack(void);
};

#endif