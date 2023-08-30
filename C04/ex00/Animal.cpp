/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:34:23 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 15:04:40 by yli              ###   ########.fr       */
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
    if (this != & other)
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

Dog::Dog(void): Animal()
{
    this->_type = "Dog";
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog: "<< "AWhuoAWhuo!" << std::endl;
}

Cat::Cat(void): Animal()
{
    this->_type = "Cat";
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat: "<< "MiaoMiao!" << std::endl;
}