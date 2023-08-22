/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:18:24 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 19:21:53 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;

    if (argc != 2)
    {
        std::cout << "wrong arguments!" << std::endl;
        return (1);
    }
    harl.complain(argv[1]);
    return (0);
}