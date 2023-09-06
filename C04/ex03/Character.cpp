/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:08:38 by yli               #+#    #+#             */
/*   Updated: 2023/09/06 20:59:42 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name): _name(name)
{
    for(int i = 0; i < 4 ; i++)
        this->_inventory[i] = NULL;
    //std::cout << "Character: " << this->_name << " is created!" << std::endl;
}

Character::Character(Character const & other): _name(other._name)
{
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    this->_name = other._name;
    for(int i = 0; i < 4 ; i++)
        this->_inventory[i] = other._inventory[i];
    return *this;
}

Character::~Character(void)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
         delete this->_inventory[i];
    }
}

std::string const & Character::getName() const
{
    return this->_name;
}

void    Character::equip(AMateria* m)
{
    if (m == NULL)
    {
        //std::cout << "Character: " << this->_name << " can not equip AMateria." << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            //std::cout << "Character: " << this->_name << " is equipped with " <<  m->getType() << std::endl;
            return ;
        }
    }
}

void    Character::unequip(int idx)
{
    if (this->_inventory[idx] || (idx >= 0 && idx < 4))
    {
        //std::cout << "Character: " << this->_name << " unequip " << this->_inventory[idx]->getType() << std::endl;
        ft_secret(this->_inventory[idx]);
        this->_inventory[idx] = NULL;
        return ;
    }
    std::cout << "Character: " << this->_name << "can not unquip" << std::endl;
}

void    Character::ft_secret(AMateria* secret)
{
    delete secret;
    return ;
}

// void    Character::unequip(int idx)
// {
//     if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
//         return ;
//     std::cout << "Character: " << this->_name << " unequip " << this->_inventory[idx]->getType() << std::endl;
//     auto it = std::next(inventory.begin(), idx);
//     inventory.erase(it);
//     this->_inventory[idx] = NULL;
// } we can not use c++11 wth!!



void Character::use(int idx, ICharacter& target)
{
    //std::cout << "Character: " << this->_inventory[idx]->getType() << std::endl;
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
        //std::cout << "Character: " << this->_name << " use " << this->_inventory[idx]->getType() << std::endl;
        return ;
    }
    //std::cout << "Character: " << this->_name << " can not use Nr." << idx << " inventory." << std::endl;
}