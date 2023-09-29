/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:44 by yli               #+#    #+#             */
/*   Updated: 2023/09/25 16:25:08 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm(std::string name): AForm(name, 72, 45), _name(name) {}

RobotmyRequestForm::~RobotmyRequestForm(void){}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm& other): AForm(other)
{
    *this = other;
}

RobotmyRequestForm& RobotmyRequestForm::operator=(const RobotmyRequestForm& other)
{
    this->_name = other._name;
    return *this;
}

void    RobotmyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExecuteGrade())
        throw RightException();
    if (!this->isSigned())
        throw SignException();
    std::cout << "ZzzZZ  pilipala ****   ZzzzZZZ pilipala" << std::endl;
    if ((rand() % 100) > 50)
        std::cout << this->_name << " has been robotimized successfully." << std::endl;
    else
        std::cout << this->_name << " the robotomy failed." << std::endl;
}

AForm*   RobotmyRequestForm::target(std::string const& target)
{
    return (new RobotmyRequestForm(target));
}



