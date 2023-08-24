/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:18 by yli               #+#    #+#             */
/*   Updated: 2023/08/24 22:27:07 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//float       roundf( float num );
// Computes the nearest integer value to num (in floating-point format), rounding halfway cases away from zero, 
// regardless of the current rounding mode. The library provides overloads of std::round for all cv-unqualified floating-point 
// types as the type of the parameter num.
Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i): _fixed(i << _fractionalBit)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float i): _fixed(roundf(i * (1 << _fractionalBit)))
{
    std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
}

Fixed&  Fixed::operator = (const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // Avoid self-assignment
        this->_fixed = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return this->_fixed;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}

float   Fixed::toFloat(void) const
{
    return (float)this->getRawBits() / (1 << _fractionalBit);
}

int Fixed::toInt(void) const
{
    return this->_fixed >> _fractionalBit;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}
