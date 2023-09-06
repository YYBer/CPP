/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:36:00 by yli               #+#    #+#             */
/*   Updated: 2023/09/06 20:58:11 by yli              ###   ########.fr       */
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
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

// int main()
// {
//     IMateriaSource* src0 = new MateriaSource();
//     AMateria* src1 = new Ice();
//     AMateria* src2 = new Cure();
//     ICharacter* bob = new Character("bob");
//     ICharacter* me = new Character("me");
//     AMateria* tmp0;
//     AMateria* tmp1;
//     // src1->getType();
//     // src2->getType();
//     src0->learnMateria(src1);
//     src0->learnMateria(src2);
    
//     tmp0 = src0->createMateria("Ice");
//     // tmp1 = src0->createMateria("Cure");
//     std::cout << tmp0 << std::endl;
//     std::cout << tmp1 << std::endl;
//     bob->equip(tmp0);
//     // me->equip(tmp1);
    
//     // //bob->debug();
//      bob->use(0 ,*me);
//     delete src1;
//     delete src2;
//     delete src0;
//     //ICharacter* me = new Character("me");
//     //AMateria *tmp;
//     //tmp = src
// }

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter*me = new Character("me");
//     AMateria*tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     me->unequip(0);
//     delete me;
//     delete src;
// }