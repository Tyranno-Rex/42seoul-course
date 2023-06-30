#include <iostream>
#include <string>
#include <fstream>


class Fixed
{
private:
    int RawBits;

public:
    Fixed(void);
    Fixed(const Fixed &ref);
    ~Fixed(void);
    Fixed &operator=(const Fixed &ref);

    int getRawBits() const;
    void setRawBits( int const raw );
};