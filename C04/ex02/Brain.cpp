/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:41:46 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 19:15:34 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain is created. There are 100 ideas in the brain!" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain is copying!" << std::endl;
    *this = other;
}

Brain& Brain::operator= (const Brain& other)
{
    for(int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
    return *this;
}

Brain::~Brain(void)
{
    std::cout << "Brain is destroyed." << std::endl;
}