/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:26:00 by yli               #+#    #+#             */
/*   Updated: 2023/10/04 16:26:01 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int>test;
    for (int i = 0; i < 4; ++i)
        test.push_back(i);
    std::cout << "can you find 2? ";
    easyfind(test, 2);
    std::cout << "can you find 6? ";
    easyfind(test, 6);


    std::list<int>  test1;
    for (int i = 0; i < 4; ++i)
        test1.push_back(i * 2);
    std::cout << "can you find 6? ";
    easyfind(test1, 6);
    std::cout << "can you find 10? ";
    easyfind(test1, 10);
}