/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:36:00 by yli               #+#    #+#             */
/*   Updated: 2023/09/05 15:11:23 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    std::cout << "step0" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    
    std::cout << "step1" << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    std::cout << "step2" << std::endl;
    me->equip(tmp);
    std::cout << "step3" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << "step4" << std::endl;

    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    std::cout << "step5" << std::endl;
    me->use(1, *bob);
    std::cout << "step6" << std::endl;
    delete bob;
    delete me;
    //delete src;
}