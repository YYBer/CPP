/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:44 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 20:33:16 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm(std::string name): AForm(name, 72, 45) {}

RobotmyRequestForm::~RobotmyRequestForm(void){}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm& other): AForm(other)
{
    *this = other;
}

RobotmyRequestForm& RobotmyRequestForm::operator=(const RobotmyRequestForm& other)
{
    (void)other;
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
        std::cout << this->getName() << " has been robotimized successfully." << std::endl;
    else
        std::cout << this->getName() << " the robotomy failed." << std::endl;
}




