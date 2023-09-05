/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:18:37 by yli               #+#    #+#             */
/*   Updated: 2023/08/31 12:57:00 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
}

Cure::Cure (const Cure & other): AMateria("cure")
{
    *this = other;
}

Cure& Cure::operator=(const Cure& other)
{
    this->_type = other._type;
    return *this;
}
// their member function clone() will return a new instance of the same type (i.e., if you clone an Ice Materia,
// you will get a new Ice Materia).
AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}