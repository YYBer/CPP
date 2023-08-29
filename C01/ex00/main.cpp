/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:00:21 by yli               #+#    #+#             */
/*   Updated: 2023/08/29 19:37:32 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string name1 = "";
    std::string name2 = "";

    std::cout << "Creating Zombie...\n"
        << "Please enter zombie name:" << std::flush;
    std::getline(std::cin, name1);
    randomChump(name1);

    std::cout << "Creating Zombie...\n"
        << "Please enter zombie name:" << std::flush;
    std::getline(std::cin, name2);
    Zombie *zom2 = newZombie(name2);
    zom2->announce();
    delete zom2;
}