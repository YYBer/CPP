/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:08:35 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 21:48:21 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*   _inventory[4];
    public:
        Character(std::string const & name);
        Character(Character const & other);
        Character& operator=(const Character & other);
        ~Character() {};
        std::string const & getName() const = 0;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, Character& target);
};


#endif