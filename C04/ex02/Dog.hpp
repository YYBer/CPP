/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:48:43 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 20:03:19 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Brain.hpp"
#include "InstantAnimal.hpp"

class Dog: virtual public InstantAnimal
{
    private:
        Brain *_brain;
    public:
        Dog(void);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog(void);
        void makeSound(void) const;
};


#endif