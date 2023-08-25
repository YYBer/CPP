/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:29:52 by yli               #+#    #+#             */
/*   Updated: 2023/08/25 17:06:56 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout <<"||ScavTrap|| " << this->_name << " is created!" << std::endl;
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
}

ScavTrap::~ScavTrap(void)
{
    std::cout <<"||ScavTrap|| " << this->_name << " is destroyed!" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    std::cout <<"||ScavTrap|| " << this->_name << " is in Gate keeper mode!" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "||ScavTrap|| " << this->_name << " has not enough energy!" << std::endl;
        return ;
    }
    std::cout << "||ScavTrap|| " << this->_name << " attacks " 
        << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}