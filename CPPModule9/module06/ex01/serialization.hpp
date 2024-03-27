#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    std::string data;
};

class serialization
{
private:
    uintptr_t _pointer;

public:
    serialization(void);
    serialization(const serialization &src);
    ~serialization(void);

    uintptr_t   serialize(Data* ptr);
    Data*       deserialize(uintptr_t raw);
};
