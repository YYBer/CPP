/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:34:23 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 19:23:31 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    this->_type = "Animal";
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copied!" << std::endl;
    *this = other;
}

Animal& Animal::operator = (const Animal& other)
{
    std::cout << "Animal assignment operator created!" << std::endl;
    this->_type = other._type;
    return *this;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal: "<< "WAWA!" << std::endl;
}

std::string    Animal::getType(void) const
{
    return this->_type;
}



