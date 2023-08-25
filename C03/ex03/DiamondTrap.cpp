/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:04:45 by yli               #+#    #+#             */
/*   Updated: 2023/08/25 19:21:57 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

Diamond::Diamond(std::string name): ClapTrap(name), _name(name), FragTrap(name), ScavTrap(name)
{
    std::cout << "^Diamond^ " << this->_name << " is created!" << std::endl;
    this->ClapTrap::_name = name + "_clap_name";
    this->_attackDamage = this->ScavTrap::_attackDamage;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_hitPoints = this->FragTrap::_hitPoints;
}

Diamond::~Diamond(void)
{
    std::cout << "^Diamond^ " << this->_name << " is destroyed!" << std::endl;
}

void    Diamond::attack(std::string& target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "^Diamond^ " << this->_name << " has not enough energy!" << std::endl;
        return ;
    }
    std::cout << "^Diamond^ " << this->_name << " attacks " 
        << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
    
}

void    Diamond::whoAmI(void)
{
    std::cout << "^Diamond^ " << "I am "<< this->_name << std::endl;
}