/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:39:46 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 19:39:47 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    SERIALIZER_HPP
#define    SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    uintptr_t i;
};
class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        Serializer(void){};
        ~Serializer(void){};
        Serializer(const Serializer& other){*this = other;};
        Serializer& operator=(const Serializer& other) {(void)other; return *this;};
};

#endif
