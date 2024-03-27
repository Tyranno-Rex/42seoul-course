#include <iostream>
#include <string>
#include <fstream>
/*
getRawBits();
고정 소수점 값 원본을 반환하는 멤버 함수 int getRawBits( void ) const;

setRawBits();
고정 소수점 값 원본을 설정하는 멤버 함수 void setRawBits( int const raw );
*/


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