/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:04:41 by yli               #+#    #+#             */
/*   Updated: 2023/08/29 15:12:52 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class Diamond: public FragTrap, public ScavTrap
{
    public:
        Diamond(std::string name);
        ~Diamond(void);

        using   ScavTrap::attack;
        void    whoAmI(void);
        
    private:
        std::string _name;
};
#endif