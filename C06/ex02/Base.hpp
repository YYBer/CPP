/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:40:00 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 19:59:45 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    BASE_HPP
#define    BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base(void){};
};

#endif


class A : public Base {};

class B : public Base {};

class C : public Base {};