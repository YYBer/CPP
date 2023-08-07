#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
    public:
        Phonebook(void);
        ~Phonebook(void);
        void    addContact(void);
        void    printContacts(void) const;
        void    search(void) const;
        void    welcome(void) const;
    
    private:
        Contact _contact[8];
        int _readInput(void) const;
}
#endif
