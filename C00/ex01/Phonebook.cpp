/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:37 by yli               #+#    #+#             */
/*   Updated: 2023/08/09 19:27:15 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
PhoneBook::PhoneBook(void)
{
    this->welcome();
}

PhoneBook::~PhoneBook(void)
{
}

void    PhoneBook::welcome(void) const
{
    std::cout << std::endl;
    std::cout << "WELCONE TO YOUR PHONEBOOK" << std::endl;
    std::cout << std::endl;
    std::cout << "----------USAGE----------" << std::endl;
    std::cout << "ADD       To add a contact" << std::endl;
    std::cout << "SEARCH    To search for a contact" << std::endl;
    std::cout << "EXIT      To quit the PhoneBook" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void)
{
    static int i;

    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::printContacts(void) const
{
    std::cout << "------------PHONEBOOK CONTACTS---------------" << std::endl;
    for (size_t i = 0; i < 8; i++)
        this->_contacts[i].view(i);
    std::cout << std::endl;
}

int PhoneBook::_readInput() const
{
    int input;

    std::cout << "Pleas enter the contact index: " << std::flush;
    std::cin >> input;
    if (std::cin.good() && input >= 0 && input <= 8)
        return (input);
    std::cin.clear();
    std::cout << "Invalid index, please re-enter." << std::endl;
    input = -1;
    return (input);
}

void    PhoneBook::search(void) const
{
    int i = this->_readInput();
    if (i >= 0)
        this->_contacts[i].display(i);
}