/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:34:19 by yli               #+#    #+#             */
/*   Updated: 2023/09/15 17:53:10 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        ~WrongAnimal(void){};
        std::string getType(void) const;
        void makeSound(void);
};

class WrongDog: public WrongAnimal
{
    public:
        WrongDog(void);
        ~WrongDog(void){};
        void makeSound(void);
};

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        ~WrongCat(void){};
        void makeSound(void);
};




#endif