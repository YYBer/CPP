/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:12:52 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 21:00:21 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
}

AMateria::AMateria(AMateria const & other)
{
    *this = other;
}

std::string const & AMateria::getType(void) const
{
    return this->_type;
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    this->_type = other._type;
    return *this;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "use func in AM called for " << target.getName() << std::endl;
}



// void AMateria::use(ICharacter& target)
// {
//     if (target == "Ice")
//         std::cout << "* shoots an ice bolt at "  << ICharacter::_name << std::endl;
//     if (target == "Cure")
//         std::cout << "* heals " << ICharacter::_name << "'s wounds *" << std::endl;
// }