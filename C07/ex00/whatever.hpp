/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:50:54 by yli               #+#    #+#             */
/*   Updated: 2023/10/03 15:50:55 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename type>
void    swap(type& a, type&b)
{
    type tmp = a;
    a = b;
    b = tmp;
}

template<typename type>
type min(type&a , type&b)
{
    return (a < b? a : b);
}

template<typename type>
type max(type&a , type&b)
{
    return (a < b? b : a);
}

/*
A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter. 

C++ adds two new keywords to support templates: ‘template’ and ‘type name’. The second keyword can always be replaced by the keyword ‘class’.

How Do Templates Work?
Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type-checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class. */