/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:34:19 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 14:55:13 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        virtual ~Animal(void){};
        Animal(const Animal& other);
        Animal& operator = (const Animal& other);
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

class Dog: virtual public Animal
{
    public:
        Dog(void);
        ~Dog(void){};
        void makeSound(void) const;
};

class Cat: virtual public Animal
{
    public:
        Cat(void);
        ~Cat(void){};
        void makeSound(void) const;
};




#endif