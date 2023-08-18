/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:28:53 by yli               #+#    #+#             */
/*   Updated: 2023/08/11 13:30:38 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();
    void    announce(void);
    
    private:
    std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif