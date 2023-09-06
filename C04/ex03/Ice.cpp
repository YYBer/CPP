/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:17:21 by yli               #+#    #+#             */
/*   Updated: 2023/09/05 18:08:39 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
}

Ice::Ice (const Ice & other): AMateria("ice")
{
    *this = other;
}

Ice& Ice::operator=(const Ice& other)
{
    this->_type = other._type;
    return *this;
}
// their member function clone() will return a new instance of the same type (i.e., if you clone an Ice Materia,
// you will get a new Ice Materia).
AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "  << target.getName()  << " *"<< std::endl;
}