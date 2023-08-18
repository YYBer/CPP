/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:57:03 by yli               #+#    #+#             */
/*   Updated: 2023/08/18 20:50:27 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& WeaA) :_name(name), _WeaA(WeaA)
{
    this->_name = name;
    std::cout << this->_name << " is created." << std::endl;
};

HumanA::~HumanA(void)
{
    std::cout << this->_name << " is destroyed." << std::endl;
};

void    HumanA::attack(void)
{
    std::cout << this->_name 
    << " attacks with his " 
    << this->_WeaA.getType() << std::endl; 
};
