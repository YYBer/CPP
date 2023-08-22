/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:18:24 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 18:56:54 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl    harl;
    std::string input = "";

    while(input.compare("EXIT"))
    {
        std::cout << "Please enter the level: " << std::flush;
        std::getline(std::cin, input);
        harl.complain(input);
    }
    return (0);
}