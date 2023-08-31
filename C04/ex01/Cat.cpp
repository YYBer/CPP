/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:48:53 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 17:52:31 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
    this->_type = "Cat";
    this->_brain = new Brain();
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat: "<< "MiaoMiao!" << std::endl;
}

Cat::Cat(const Cat& other)
{
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    this->_brain = new Brain(*other._brain);
    std::cout << "cat brain is running!" << std::endl;
    this->_type = other._type;
    return *this;
}

Cat::~Cat(void)
{
    delete this->_brain;
}