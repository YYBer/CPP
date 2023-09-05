/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:33:28 by yli               #+#    #+#             */
/*   Updated: 2023/09/05 14:08:33 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
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
}

// int main()
// {
//     const Animal*    a1 = new Animal();
//     const Animal*    a2 = new Cat();
//     const Animal*    a3 = new Dog();
//     const Animal*    a4;
//     //a3 = a1;
//     a4 = a2;

    
//     std::cout << "a1 is " << std::endl;
//     a1->makeSound();
//     std::cout << "a2 is " << std::endl;
//     a2->makeSound();
//     std::cout << "a3 is " << std::endl;
//     a3->makeSound();
//     std::cout << "a4 is " << std::endl;
//     a4->makeSound();
//     a4 = a3;
//     std::cout << "a4 is " << std::endl;
//     a4->makeSound();

//     delete a1;
//     delete a2;
//     delete a3;
//     //delete a4;
// }


// int main()
// {
//     Dog* d1 = new Dog();
//     const Dog* d2 = new Dog(*d1);

//     // Dog* d2 = new Dog;
//     // *d2 = *d1;

//     //delete d1;
//     std::cout << d2->_brain << std::endl;
//     std::cout << d1->_brain << std::endl;
    
//     d2->makeSound();

// } //only for test!