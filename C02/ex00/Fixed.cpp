/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:18 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 22:00:44 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Fixed& Fixed::operator=(const Fixed& other) {
//     if (this != &other) { // Avoid self-assignment
//         std::cout << "Custom assignment operator called" << std::endl;
//         this->setRawBits(other.getRawBits());
//     }
//     return *this;
// }

Fixed::Fixed(void): _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}
