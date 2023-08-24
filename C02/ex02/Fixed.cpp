/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:02:05 by yli               #+#    #+#             */
/*   Updated: 2023/08/24 23:12:17 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void):_fixed(0)
{
}

Fixed::Fixed(const int i): _fixed(i << _fractionalBits)
{
}

Fixed::Fixed(const float i): _fixed(roundf(i * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed& other)
{
    this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator = (const Fixed& other)
{
    if (this != & other)
        this->_fixed = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
    return _fixed;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}

float   Fixed::toFloat(void)    const
{
    return (float)this->getRawBits() / (1 << _fractionalBits);   
}

int     Fixed::toInt(void) const
{
    return this->_fixed >> _fractionalBits;   
}

std::ostream & operator << (std::ostream & o, Fixed const & other)
{
    o << other.toFloat();
    return o;
}

bool    Fixed::operator > (const Fixed& other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool    Fixed::operator < (const Fixed& other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool    Fixed::operator >= (const Fixed& other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool    Fixed::operator <= (const Fixed& other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool    Fixed::operator == (const Fixed& other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool    Fixed::operator != (const Fixed& other) const
{
    return (this->getRawBits() != other.getRawBits());
}

Fixed   Fixed::operator + (const Fixed& other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator - (const Fixed& other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator * (const Fixed& other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator / (const Fixed& other) const
{
    return (this->toFloat() / other.toFloat());
}

Fixed&  Fixed::operator ++ (void) //++i
{
    ++this->_fixed;
    return *this;
}

Fixed   Fixed::operator ++ (int) //i++
{
    Fixed   tmp(*this);
    tmp._fixed = this->_fixed++;
    return tmp;
}

Fixed&  Fixed::operator -- (void)
{
    --this->_fixed;
    return *this;
}

Fixed   Fixed::operator -- (int)
{
    Fixed tmp(*this);
    tmp._fixed = this->_fixed;
    return tmp;
}   

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed&   Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return b;
    return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return b;
    return a;
}