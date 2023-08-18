/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:12:29 by yli               #+#    #+#             */
/*   Updated: 2023/08/09 19:41:37 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE *";
		else
		{
			for (int i = 1; av[i]; i++)
			{
				for (int j = 0; av[i][j]; j++)
					std::cout << (char) toupper(av[i][j]);
				if (i < ac - 1)
					std::cout << ' ';
			}
		}
	std::cout << std::endl;
	return (0);
}
