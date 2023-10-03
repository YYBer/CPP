/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:50:57 by yli               #+#    #+#             */
/*   Updated: 2023/10/03 15:50:58 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename type>
void    iter(type *add, size_t size, void(*f)(type&))
{
    for (size_t i = 0; i < size; ++i)
        f(add[i]);
}

template<typename type>
void    ft_print(type& i)
{
    std::cout << i << std::endl;
}