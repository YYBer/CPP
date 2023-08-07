#include "PhoneBook.hpp"
//#include <limits>
#include <iostream>

int main(void)
{
    PhoneBook book;
    std::string input = "";
    //book.welcome();
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
        std::cin >> input;
    }
    return 0;
}