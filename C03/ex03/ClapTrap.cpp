/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:26:53 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 15:14:45 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
In all of these member functions, you have to print a message to describe what hap-
pens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!*/

ClapTrap::ClapTrap(std::string name):_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "copy ClapTrap is created!" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other)
{
    std::cout << "ClapTrap assignment operator is created!" << std::endl;
    this->_name = other._name;
    this->_attackDamage = other._attackDamage;
    this->_attackDamage = other._energyPoints;
    this->_hitPoints = other._hitPoints;
    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has not enough energy!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " 
        << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= amount)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages!" << std::endl;
    this->_hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has not enough energy!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " is repaired with " << amount << " points!" << std::endl;
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
}