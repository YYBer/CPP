/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:34:23 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 14:09:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->_type = "Animal";
}

void    WrongAnimal::makeSound(void)
{
    std::cout << "Animal: "<< "WAWA!" << std::endl;
}

std::string    WrongAnimal::getType(void) const
{
    return this->_type;
}

WrongDog::WrongDog(void): WrongAnimal()
{
    this->_type = "Dog";
}

void    WrongDog::makeSound(void)
{
    std::cout << "WrongDog: "<< "AWhuoAWhuo!" << std::endl;
}

WrongCat::WrongCat(void): WrongAnimal()
{
    this->_type = "Cat";
}

void    WrongCat::makeSound(void)
{
    std::cout << "WrongCat: "<< "MiaoMiao!" << std::endl;
}