/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:51:09 by yli               #+#    #+#             */
/*   Updated: 2023/10/03 16:31:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    Array<double> dd;
    Array<int> i1(5);
    for (int i = 0; i < 5; ++i)
    {
        i1[i] = i * 2;
    }
    Array<int> i2 (i1);
    Array<int> i3 = i1;
    std::cout << "1. " << dd;
    std::cout << "2. " << i1;
    std::cout << "3. " << i2;
    std::cout << "4. " << i3;

    try{
        std::cout << "valid index: " << i1[4] << std::endl;
    }catch (Array<int>::OutOfBondsException& e){
        std::cout << "Error:" << e.what() << std::endl;
    }
    try{
        std::cout << "invalid index: " << i1[6] << std::endl;
    }catch (Array<int>::OutOfBondsException& e){
        std::cout << "Error:" << e.what() << std::endl;
    }
}