/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:33:28 by yli               #+#    #+#             */
/*   Updated: 2023/08/30 14:07:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    std::cout << std::endl;

    WrongAnimal* wmeta = new WrongAnimal();
    WrongAnimal* wj = new WrongDog();
    WrongAnimal* wi = new WrongCat();
    std::cout << wj->getType() << " " << std::endl;
    std::cout << wi->getType() << " " << std::endl;
    wi->makeSound();
    wj->makeSound();
    wmeta->makeSound();

    delete wmeta;
    delete wj;
    delete wi;
    return (0);
}