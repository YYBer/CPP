/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:26:57 by yli               #+#    #+#             */
/*   Updated: 2023/08/25 00:10:47 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Tom");

    clap.attack("Jack");
    clap.takeDamage(5);
    clap.takeDamage(4);
    clap.attack("Jack");
    clap.beRepaired(8);
}