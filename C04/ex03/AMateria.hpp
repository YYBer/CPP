/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:12:49 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 20:59:45 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const &type);
        AMateria(AMateria const & other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria(void){};
        
        std::string const & getType(void) const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};



#endif