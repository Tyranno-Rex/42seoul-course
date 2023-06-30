#include "Fixed.hpp"

Fixed::Fixed(void):RawBits(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &ref)
{
    std::cout << "Copy constructor called\n";
    this->RawBits = ref.getRawBits();
}

/*
Fixed::Fixed(const Fixed &ref):RawBits(ref.RawBits)
{
    std::cout << "Copy constructor called\n";
}
*/

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &ref)
{
    std::cout << "Assignation operator called\n";
    
    if (this != &ref)
    {
        RawBits = ref.getRawBits();
    }
    return (*this);
}

/*
Fixed &Fixed::operator=(const Fixed &ref)
{
    std::cout << "Assignation operator called\n";
    
    if (this != &ref)
    {
        RawBits = ref.RawBits;
    }
    return (*this);
}
*/


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (RawBits);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->RawBits = raw;
}