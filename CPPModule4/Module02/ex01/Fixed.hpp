#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class Fixed
{
private:
    int RawBits;
    static const int fract_bit;

public:
    Fixed(void);
    Fixed(const Fixed &ref);
    Fixed(const int Number);
    Fixed(const float Number);
    ~Fixed(void);
    
    Fixed &operator=(const Fixed &ref);
    
    float MakeFloat(void) const;
    int MakeInt(void) const;
    float toFloat(void)const;
    int toInt(void)const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &ref, const Fixed &fixed);
