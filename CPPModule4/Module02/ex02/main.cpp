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

    std::cout << a << std::endl; // 0
    std::cout << ++a << std::endl; // 0.00390625
    std::cout << a << std::endl; // 0.00390625
    std::cout << a++ << std::endl; // 0.00390625
    std::cout << a << std::endl; // 0.0078125

    std::cout << b << std::endl; // 10.1016
    
    
    Fixed c(3.2f);
    Fixed c1(3.2f);
    Fixed d(3.1f);
    std::cout << "\nVarious operator checks\n";
    std::cout << "Compare 3.2 and 3.1 : ";
    if (c > d)
        std::cout << "> function is well operation\n";
    else
        std::cout << "ERROR\n";
    
    std::cout << "Compare 3.2 and 3.1 : ";
    if (c < d)
        std::cout << "ERROR\n";
    else
        std::cout << "< function is well operation\n";
    
    std::cout << "Compare 3.2 and 3.1 : ";
    if (c >= d)
        std::cout << ">= function is well operation\n";
    else
        std::cout << "ERROR\n";
    
    std::cout << "Compare 3.2 and 3.2 : ";
    if (c <= c1)
        std::cout << "<= function is well operation\n";
    else
        std::cout << "ERROR\n";
    
    std::cout << "Compare 3.2 and 3.1 : ";
    if (c == d)
        std::cout << "ERROR\n";
    else
        std::cout << "== function is well operation\n";
    
    std::cout << "Compare 3.2 and 3.2 : ";
    if (c != c1)
        std::cout << "ERROR\n";
    else
        std::cout << "!= function is well operation\n";

    
    std::cout << "\nfour arithmetic operations checks\n";
    float c_Plus_c1 = c + c1;
    float c_Minus_c1 = c - c1;
    float c_Multiply_c1 = c * c1;
    float c_Divide_c1 = c / c1;
    std:: cout << "c : 3.2 and c1 : 3.2\n";
    std::cout << "c + c1 : " << c_Plus_c1 << "\n";
    std::cout << "c - c1 : " << c_Minus_c1 << "\n";
    std::cout << "c * c1 : " << c_Multiply_c1 << "\n";
    std::cout << "c / c1 : " << c_Divide_c1 << "\n";

    std::cout << "\nMAX MIN checks\n";
    std::cout << "max : " << Fixed::max( a, b ) << std::endl; // 10.1016
    std::cout << "min : " << Fixed::min( a, b ) << std::endl; // 10.1016

    return 0;
}