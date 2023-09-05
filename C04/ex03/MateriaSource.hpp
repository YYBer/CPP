/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:08:28 by yli               #+#    #+#             */
/*   Updated: 2023/08/31 13:23:58 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"


class MateriaSource: public IMateriaSource
{
    private:
        AMateria*   _materias[4];
    public:
        MateriaSource(void);
        ~MateriaSource(void);
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        AMateria* getMateria(std::string const & type);
        AMateria* createMateria(std::string const & type);
        void learnMateria(AMateria* other);
};

#endif