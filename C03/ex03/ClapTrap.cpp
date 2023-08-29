/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:26:53 by yli               #+#    #+#             */
/*   Updated: 2023/08/29 13:45:07 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*implement a FragTrap class that inherits from ClapTrap: creating a subclass or derived class*/

ClapTrap::ClapTrap(std::string name):_name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
    std::cout << "[ClapTrap] " << this->_name << " is created!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "[ClapTrap] " << this->_name << " is destroyed!" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "[ClapTrap] " << this->_name << " has not enough energy!" << std::endl;
        return ;
    }
    std::cout << "[ClapTrap] " << this->_name << " attacks " 
        << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= amount)
    {
        std::cout << "[ClapTrap] " << this->_name << " is dead!" << std::endl;
        return ;
    }
    std::cout << "[ClapTrap] " << this->_name << " takes " << amount << " damages!" << std::endl;
    this->_hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "[ClapTrap] " << this->_name << " has not enough energy!" << std::endl;
        return ;
    }
    std::cout << "[ClapTrap] " << this->_name << " is repaired with " << amount << " points!" << std::endl;
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
}