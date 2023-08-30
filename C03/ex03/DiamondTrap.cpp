/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:04:45 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 10:56:25 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

Diamond::Diamond(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    std::cout << "^Diamond^ " << this->_name << " is created!" << std::endl;
    std::cout << "^Diamond^ "<< "hitPoints is from  FragTrap: " << FragTrap::_hitPoints << std::endl;
    std::cout << "^Diamond^ "<< "energyPoints is from  ScavTrap: " << ScavTrap::_energyPoints << std::endl;
    FragTrap::_attackDamage = 30;
    std::cout << "^Diamond^ "<< "attackDamage is from  FragTrap: " << FragTrap::_attackDamage << std::endl;
}

Diamond::~Diamond(void)
{
    std::cout << "^Diamond^ " << this->_name << " is destroyed!" << std::endl;
}

void    Diamond::whoAmI(void)
{
    //this->_name = _name + "_clap_name";
    std::cout << "^Diamond^ " << "I am "<< this->_name << " but in ClapTrap my name is " << this->ClapTrap::_name << std::endl;
}