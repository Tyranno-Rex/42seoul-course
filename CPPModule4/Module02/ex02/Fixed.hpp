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

    bool operator>(Fixed Fixed)const;
    bool operator<(Fixed Fixed)const;
    bool operator>=(Fixed Fixed)const;
    bool operator<=(Fixed Fixed)const;
    bool operator==(Fixed Fixed)const;
    bool operator!=(Fixed Fixed)const;

    float operator+(Fixed fixed)const;
    float operator-(Fixed fixed)const;
    float operator*(Fixed fixed)const;
    float operator/(Fixed fixed)const;

    Fixed operator++();
    Fixed operator--();
    
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed &min(Fixed &first, Fixed &second);
    static const Fixed &min(const Fixed &first, const Fixed &second);
    static Fixed &max(Fixed &first, Fixed &second);
    static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &ref, const Fixed &fixed);
