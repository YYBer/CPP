/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstantAnimal.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:57:35 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 20:03:09 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstantAnimal.hpp"


InstantAnimal::InstantAnimal(void)
{
    this->_type = "Animal";
}

InstantAnimal::InstantAnimal(const InstantAnimal& other)
{
    std::cout << "Animal copied!" << std::endl;
    *this = other;
}

InstantAnimal& InstantAnimal::operator = (const InstantAnimal& other)
{
    std::cout << "Animal assignment operator created!" << std::endl;
    this->_type = other._type;
    return *this;
}

void    InstantAnimal::makeSound(void) const
{
    std::cout << "Animal makeSound called" << std::endl;
}

std::string    InstantAnimal::getType(void) const
{
    return this->_type;
}


