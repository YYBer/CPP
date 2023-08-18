/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:26:28 by yli               #+#    #+#             */
/*   Updated: 2023/08/09 19:27:28 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    addContact(void);
        void    printContacts(void) const;
        void    search(void) const;
        void    welcome(void) const;
    
    private:
        Contact _contacts[8];
        int _readInput(void) const;
};
#endif