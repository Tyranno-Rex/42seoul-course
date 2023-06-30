#include "Fixed.hpp"










/*
여섯 개의 비교 연산자: >, <, >=, <=, == 그리고 !=
네 개의 산술 연산자: +, -, *, 그리고 /
++ 그리고 --

min max
*/






int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}