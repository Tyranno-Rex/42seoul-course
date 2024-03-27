#include "Fixed.hpp"

const int Fixed::fract_bit = 8;


Fixed::Fixed(void):RawBits(0)
{
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &ref)
{
    // std::cout << "Copy constructor called\n";
    this->RawBits = ref.getRawBits();
}

/*
Fixed::Fixed(const Fixed &ref):RawBits(ref.RawBits)
{
    std::cout << "Copy constructor called\n";
}
*/

Fixed::Fixed(const int Number)
{
    // std::cout << "Int constructor called\n";
    this->RawBits = Number << this->fract_bit;
}

Fixed::Fixed(const float Number)
{
    // std::cout << "Float constructor called\n";
    this->RawBits = roundf(Number * (1 << this->fract_bit));
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &ref)
{
    // std::cout << "Assignation operator called\n";
    
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
    // std::cout << "getRawBits member function called\n";
    return (RawBits);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called\n";
    this->RawBits = raw;
}

// Public Methods
float	Fixed::toFloat(void)const
{
	return ((float)this->RawBits / (float)(1 << this->fract_bit));
}

int	Fixed::toInt(void)const
{
	return (this->RawBits >> this->fract_bit);
}

std::ostream	&operator<<(std::ostream &ref, const Fixed &fixed)
{
	ref << fixed.toFloat();
	return (ref);
}

bool Fixed::operator>(Fixed fixed)const
{
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed)const
{
    return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed)const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed)const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed)const
{
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed)const
{
    return (this->toFloat() != fixed.toFloat());
}

float Fixed::operator+(Fixed fixed)const
{
    return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed)const
{
    return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed)const
{
    return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed fixed)const
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
    this->RawBits++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->RawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->RawBits;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->RawBits;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}