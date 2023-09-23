/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:02 by user              #+#    #+#             */
/*   Updated: 2023/09/23 12:29:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string & name, const int grade, const int executegrade): _name(name), _signed(false), _grade(grade), _executegrade(executegrade)
{
    if (_grade < 1 || _executegrade < 1)
        throw AForm::GradeTooHighException();
    else if (_grade > 150 || _executegrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & other):_name(other._name), _signed(other._signed), _grade(other._grade), _executegrade(other._executegrade)
{
	if (_grade < 1 || _executegrade < 1)
		throw AForm::GradeTooHighException();
	else if (_grade > 150 || _executegrade > 150)
		throw AForm::GradeTooLowException();
    *this = other;
}

AForm& AForm::operator=(const AForm& other)
{
    this->_signed = other._signed;
    return *this;
}

std::string AForm::getName(void) const
{
    return this->_name;
}

int AForm::getGrade(void) const
{
    return this->_grade;
}

bool    AForm::isSigned(void) const
{
    return this->_signed;
}

int AForm::getExecuteGrade(void) const
{
    return this->_executegrade;
}

void    AForm::signAForm(Bureaucrat const & other)
{
    if (other.getGrade() > this->getGrade())
    {
        std::cerr << other.getName() << " couldn't sign " << this->getName() << " because ";
        throw AForm::GradeTooLowException();
    }
    else if (this->_signed == true)
    {
        std::cerr << other.getName() << " couldn't sign" << this->getName() << " because " << std::endl;
        throw AForm::AFormAlreadySignedException();
    }
    this->_signed = true;
    std::cout << other.getName() << " signed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, AForm const & other)
{
    out << other.getName() << "'s AForm status is " << other.isSigned() << ", his grade is "
        << other.getGrade() << " and his execute grade is " << other.getExecuteGrade();
    return out;
}


