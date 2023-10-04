/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:25:56 by yli               #+#    #+#             */
/*   Updated: 2023/10/04 16:25:57 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
void    easyfind(T& other, int value)
{
    if (std::find(other.begin(), other.end(), value) != other.end())
    {
        std::cout << "I found it\n";
        return;
    }
    std::cout << "I can not find it.\n";
}
/*
std::find is a function defined inside <algorithm> header file that finds the element in the given range. It returns an iterator to the first occurrence of the specified element in the given sequence. If the element is not found, an iterator to the end is returned.

Syntax:

input_iterator std::find(input_iterator first, input_iterator last, const T& value);
Parameters:

first: iterator to the initial position in the sequence.
last: iterator to position just after the final position in the sequence. (Note that vector.end() points to the next position to the last element of the sequence and not to the last position of the sequence).
value: value to be searched.
Return Value :

If the value is found in the sequence, the iterator to its position is returned.
If the value is not found, the iterator to the last position is returned.*/