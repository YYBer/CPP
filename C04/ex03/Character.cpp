/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:08:38 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 21:47:35 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name): _name(name)
{
    for(int i; i < 4 ; i++)
        this->_inventory[i] = NULL;
    std::cout << "Character: " << this->_name << " is created!" << std::endl;
}

Character::Character(Character const & other): _name(other._name)
{
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    this->_name = other._name;
    for(int i; i < 4 ; i++)
        this->_inventory[i] = other._inventory[i];
    return *this;
}

std::string const & Character::getName() const
{
    return this->_name;
}

void    Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << "equipped" << std::endl;
            return ;
        }
    }
    std::cout << "not equip" << std::endl;
}

void    Character::unequip(int idx)
{
    if (this->_inventory[idx])
    {
        std::cout << "Character: " << this->_name << " unequip " << this->_inventory[idx]->getType() << std::endl;
        delete this->_inventory[idx];
        this->_inventory[idx] = NULL;
        return ;
    }
    std::cout << "Character: " << this->_name << "can not unquip" << std::endl;
}

void Character::use(int idx, Character& target)
{
    if (this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
        std::cout << "Character: " << this->_name << " use " << this->_inventory[idx]->getType() << std::endl;
    }
    std::cout << "Character: " << this->_name << " can not use "<< std::endl;
}

