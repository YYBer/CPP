/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:48:48 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 20:04:13 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): InstantAnimal()
{
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
    std::cout << "second dog is created!" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    this->_brain = new Brain(*other._brain);
    //this->_brain = other._brain; //only for test shallow copy!
    std::cout << "a new brain is created!" << std::endl;
    this->_type = other.getType();
    return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog: "<< "AWhuoAWhuo!" << std::endl;
}

Dog::~Dog(void)
{
    delete this->_brain;
}