/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:56:43 by yli               #+#    #+#             */
/*   Updated: 2023/08/17 22:32:12 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implement a Weapon class that has:
// • A private attribute type, which is a string.
// • A getType() member function that returns a const reference to type.
// • A setType() member function that sets type using the new one passed as param-
// eter.

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>

class Weapon
{
    private:
        std::string _str;

    public:
        Weapon(std::string str);
        ~Weapon(void);
        std::string getType (void) const;
        void setType (std::string s);
};

#endif