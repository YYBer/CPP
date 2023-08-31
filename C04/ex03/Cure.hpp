/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:18:35 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 20:56:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"


class Cure: public AMateria
{
    public:
        Cure();
        ~Cure() {};
        Cure(Cure const & other);
        Cure& operator= (const Cure & other);
        
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif