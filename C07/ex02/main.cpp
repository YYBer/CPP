/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:51:09 by yli               #+#    #+#             */
/*   Updated: 2023/10/11 17:49:30 by yli              ###   ########.fr       */
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

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }