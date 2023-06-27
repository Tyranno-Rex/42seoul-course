#include <iostream>
#include <string>
#include <cstdlib>

class Zombie{
private:
    std::string name;
public:
    Zombie (const std::string &newname = "");
    ~Zombie (void);
    void MakeZombieName(std::string &newname);
    void announce(void);
};

Zombie* zombieHorde(int N, std::string name);