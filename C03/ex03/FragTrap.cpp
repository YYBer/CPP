/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:11:54 by yli               #+#    #+#             */
/*   Updated: 2023/08/29 15:23:49 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "*FragTrap* "<< this->_name << " is created!" << std::endl;
    this->_attackDamage = 30;
    this->_energyPoints = 100;
    this->_hitPoints = 100;
}

FragTrap::~FragTrap(void)
{
    std::cout << "*FragTrap* "<< this->_name << " is destroyed!" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "*FragTrap* " << this->_name << "does not have enough energy!" << std::endl;
        return ;
    }
    std::cout << "*FragTrap* "<< this->_name << " give you high fives!" << std::endl;
}