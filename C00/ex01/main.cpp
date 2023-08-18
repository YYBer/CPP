/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:48 by yli               #+#    #+#             */
/*   Updated: 2023/08/09 19:20:49 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int main(void)
{
    PhoneBook book;
    std::string input = "";
    while(input.compare("EXIT"))
    {
        if (!input.compare("ADD"))
            book.addContact();
        else if (!input.compare("SEARCH"))
        {
            book.printContacts();
            book.search();
        }
        std::cout << ">" << std::flush;
        std::getline(std::cin, input);
    }
    return 0;
}