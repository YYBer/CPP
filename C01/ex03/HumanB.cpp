/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:56:57 by yli               #+#    #+#             */
/*   Updated: 2023/08/18 20:48:54 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _WeaB(NULL)
{
    std::cout << this->_name << " is created." << std::endl;
};

HumanB::~HumanB(void)
{
    std::cout << this->_name << " is destroyed." << std::endl;
};

void    HumanB::attack(void)
{
    std::cout << this->_name 
    << " attacks with his " 
    << _WeaB->getType() << std::endl;
};

void    HumanB::setWeapon(Weapon& weapon)
{
   _WeaB = &weapon;
}
