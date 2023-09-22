/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:02 by user              #+#    #+#             */
/*   Updated: 2023/09/11 16:57:10 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string & name, const int grade, const int executegrade): _name(name), _signed(false), _grade(grade), _executegrade(executegrade)
{
    if (_grade < 1 || _executegrade < 1)
        throw Form::GradeTooHighException();
    else if (_grade > 150 || _executegrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form & other):_name(other._name), _signed(other._signed), _grade(other._grade), _executegrade(other._executegrade)
{
    *this = other;
} //test for too high grade

// Form::Form(Form const &other):
// 	name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade)
// {
// 	if (signGrade < 1 || executeGrade < 1)
// 		throw Form::GradeTooHighException();
// 	else if (signGrade > 150 || executeGrade > 150)
// 		throw Form::GradeTooLowException();
// }

Form& Form::operator=(const Form& other)
{
    this->_signed = other._signed;
    return *this;
}

std::string Form::getName(void) const
{
    return this->_name;
}

int Form::getGrade(void) const
{
    return this->_grade;
}

bool    Form::isSigned(void) const
{
    return this->_signed;
}

int Form::getExecuteGrade(void) const
{
    return this->_executegrade;
}

void    Form::signForm(Bureaucrat const & other)
{
    if (other.getGrade() < this->getGrade())
    {
        std::cerr << other.getName() << " couldn't sign" << this->getName() << " because ";
        throw Form::GradeTooLowException();
    }
    else if (this->_signed == true)
    {
        std::cerr << other.getName() << " couldn't sign" << this->getName() << " because " << std::endl;
        throw Form::FormAlreadySignedException();
    }
    this->_signed = true;
    std::cout << other.getName() << " signed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, Form const & other)
{
    out << other.getName() << "'s Form status is " << other.isSigned() << ", his grade is "
        << other.getGrade() << " and his execute grade is " << other.getExecuteGrade();
    return out;
}


