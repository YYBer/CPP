/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:17:19 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 21:00:54 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        ~Ice() {};
        Ice(Ice const & other);
        Ice& operator= (const Ice & other);
        
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};


#endif