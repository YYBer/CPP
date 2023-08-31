/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:48:50 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 17:51:51 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat: virtual public Animal
{
    private:
        Brain *_brain;
    public:
        Cat(void);
        Cat(const Cat& other);
        Cat& operator= (const Cat& other);
        ~Cat(void);
        void makeSound(void) const;
};

#endif