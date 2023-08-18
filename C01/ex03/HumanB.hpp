/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:56:54 by yli               #+#    #+#             */
/*   Updated: 2023/08/18 20:33:41 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon*  _WeaB;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    setWeapon(Weapon& weapon);
        void    attack(void);
};

#endif