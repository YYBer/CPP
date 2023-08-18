/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:56:46 by yli               #+#    #+#             */
/*   Updated: 2023/08/17 22:32:38 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string str)
{
    this->_str = str;
};

Weapon::~Weapon(void)
{
};

std::string Weapon::getType(void) const
{
    return (this->_str);
};

void Weapon::setType(std::string s)
{
    this->_str = s;
};