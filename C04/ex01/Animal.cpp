/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:34:23 by yli               #+#    #+#             */
/*   Updated: 2023/08/29 20:01:05 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    this->_type = "Animal";
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