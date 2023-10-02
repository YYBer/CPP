/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:39:39 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 19:39:40 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *test = new Data();

    test->i = 42;

    std::cout << Serializer::deserialize(Serializer::serialize(test))->i << std::endl;
    std::cout << Serializer::serialize(Serializer::deserialize(test->i)) << std::endl;
    std::cout << Serializer::deserialize(Serializer::serialize(test)) << std::endl;
    std::cout << test << std::endl;

    delete test;


    Data test1;

    test1.i = 42;

    std::cout << Serializer::deserialize(Serializer::serialize(&test1))->i << std::endl;
    std::cout << Serializer::serialize(Serializer::deserialize(test1.i)) << std::endl;

    std::cout << Serializer::deserialize(Serializer::serialize(&test1)) << std::endl;
    std::cout << &test1 << std::endl;
    
    return 0;
}