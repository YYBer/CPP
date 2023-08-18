/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:10 by yli               #+#    #+#             */
/*   Updated: 2023/08/17 21:13:36 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie();
        void    announce(void);
        //Zombie* newZombie(std::string name);
        void    saveName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
