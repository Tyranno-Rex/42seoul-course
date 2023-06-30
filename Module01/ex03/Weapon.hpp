#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(const std::string &newType  = "");
    ~Weapon(void);

    void InitWeaponType(const std::string &Type);
    const std::string GetWeaponType(void);
};

#endif