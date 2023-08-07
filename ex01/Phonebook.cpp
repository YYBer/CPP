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