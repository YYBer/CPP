/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:31:43 by yli               #+#    #+#             */
/*   Updated: 2023/08/31 13:24:35 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if(this->_materias[i])
            delete this->_materias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = other._materias[i];
    return *this;
}

AMateria* MateriaSource::getMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return this->_materias[i];
    return NULL;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return this->_materias[i]->clone();
    return NULL;
}

void    MateriaSource::learnMateria(AMateria* other)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] == NULL)
        {
            this->_materias[i] = other;
            std::cout << "learned"<< std::endl;
        }
        std::cout << "can not lerned" << std::endl;
    }
}
