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
    std::cout << "ADD       To add a contact." << std::endl;
    std::cout << "SEARCH        To search for a contact" << std::endl;
    std::cout << "EXIT      to quit the PhoneBook" << std::end;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void)
{
    static int i;
    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::printContact(void) const
{
    std::cout << "------------PHONEBOOK CONTACTS---------------" << std::endl;
    for (size_t = 0; i < 8; i++)
        this->_contacts[i].view(i);
    std::cout << std::endl;
}

int PhoneBook::_readInput() const
{
    int input = -1;
    int valid = 0;

    while (!valid)
    {
        std::cout << "Pleas enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8))
            valid = 1;
        else
        {
            std::cin.clear();
            //std::cin.ignore()
            std::cout << "Invalid index, please re-enter." << std::endl;
        }
    }
    return (input);
}

void    PhoneBook::search(void) const
{
    int i = this-_readInput();
    this->_contacts[i].display(i);
}
