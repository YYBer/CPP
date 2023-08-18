/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:56:59 by yli               #+#    #+#             */
/*   Updated: 2023/08/18 20:27:22 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Now, create two classes: HumanA and HumanB. They both have a Weapon and a
// name. They also have a member function attack() that displays (of course, without the
// angle brackets):
// <name> attacks with their <weapon type>
// HumanA and HumanB are almost the same except for these two tiny details:
// • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed.

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _WeaA;
    public:
        HumanA(std::string name, Weapon& WeaA);
        ~HumanA(void);
        void    attack(void);
};

#endif