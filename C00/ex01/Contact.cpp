/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:25:50 by yli               #+#    #+#             */
/*   Updated: 2023/08/09 19:25:52 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::_getInput(std::string str) const
{
    std::string input = "";

    std::cout << str << std::flush;
    std::getline(std::cin, input);
    if (std::cin.good() && !input.empty())
        return (input);
    std::cin.clear();
    std::cout << "Invalid Input, try again." << std::endl;
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
    this->_firstName = this->_getInput("Please enter your first name: ");
    this->_lastName = this->_getInput("Please enter your last name: ");
    this->_nickname = this->_getInput("Please enter your nickname: ");
    this->_phoneNumber = this->_getInput("Please enter your phonenumber: ");
    this->_favmeal = this->_getInput("Please enter your favorite meal: ");
    std::cout << std::endl;
}

void    Contact::setIndex(int i)
{
    this->_index = i;
    return ;
}

void    Contact::view(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "INDEX:" << std::setw(10) << index << "|" << std::flush;
    std::cout << "FIRSTNAME:" << std::setw(10) << this->_printLen(this->_firstName) << "|" << std::flush;
    std::cout << "LASTNAME:" << std::setw(10) << this->_printLen(this->_lastName) << "|" << std::flush;
    std::cout << "NICKNAME:" << std::setw(10) << this->_printLen(this->_nickname) << "|" << std::flush;
    std::cout << std::endl;
}

void    Contact::display(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
    {
        std::cout << "CONTACT DOES NOT EXIST" << std::endl;
        return ;
    }
    std::cout << "CONTACT #" << index << std::endl;
    std::cout << "FIRST NAME:" << this->_firstName << std::endl;
    std::cout << "LAST NAME:" << this->_lastName << std::endl;
    std::cout << "NICKNAME:" << this->_nickname << std::endl;
    std::cout << std::endl;
}