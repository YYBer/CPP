#include "Contact.hpp"

Contact::Contact(void)
{
}

~Contact::Contact(void)
{
}

std::string Contact::_getInput(std::string str) const
{
    std::string input = "";
    bool    valid = 0;

    while (!valid)
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = 1;
        else 
        {
            std::cin.clear();
            std::cout << "Invalid Input, try again." << std::endl;
        }
    }
    return (input);
}

std::string Contact::_printLen(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::init(void)
{
    std::cin.ignore();
    this->_firstName = this->_getInput("Please enter your first name: ");
    this->_lastName = this->_getInput("Please enter your last name: ");
    this->_nickname = this->_getInput("Please enter your nickname: ");
    this->phoneNumber = this->_getInput("Please enter your phonenumber: ");
    this->favmeal = this->_getInput("Please enter your favorite meal: ");
    std::cout << std::endl;
}

void    Contact::setIndex(int i)
{
    this->index = i;
    return ;
}

void    Contact::view(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << std::setw(10) << index << std::flush;
    std::cout << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << std::setw(10) << this->_printLen(this->nickname) << std::flush;
    std::cout << std<<endl;
}

void    Contact::display(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "CONTACT #" << index << std::endl;
    std::cout << "FIRST NAME: " << this->_firstName << std::endl;
    std::cout << "LAST NAME: " << this->_lastName << std::endl;
    std::cout << "NICKNAME: " << this->_nickame << std::endl;
    std::cout << std::endl;
}