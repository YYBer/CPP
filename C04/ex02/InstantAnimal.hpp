/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstantAnimal.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:58:12 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 20:15:24 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTANTANIMAL_HPP
# define INSTANTANIMAL_HPP

#include <iostream>

class InstantAnimal
{
    protected:
        std::string _type;
    public:
        InstantAnimal(void);
        virtual ~InstantAnimal(void){};
        InstantAnimal(const InstantAnimal& other);
        InstantAnimal& operator = (const InstantAnimal& other);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};


#endif

// virtual function is pure, meaning that you cannot call it as such: 
// the function doesn't have any code to it, hence the = 0. 
// Only by deriving the class and overriding the function you can call it. 
// The class with pure virtual functions cannot be instantiated so they are called abstract classes, interfaces in some languages.