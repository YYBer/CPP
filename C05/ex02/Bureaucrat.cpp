/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:55 by yli               #+#    #+#             */
/*   Updated: 2023/09/23 16:30:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const& name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    // else
    //     this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->_grade = other._grade;
    //this->_name = other._name;
    return *this;
}

std::string    Bureaucrat::getName(void) const
{
    return this->_name;
}

int    Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void    Bureaucrat::increment(void)
{
    if (this->_grade > 149)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void    Bureaucrat::decrement(void)
{
    if (this->_grade < 2)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& other)
{
    o << other.getName() << " 's grade is " << other.getGrade();
    return o;
}

void    Bureaucrat::executeForm(AForm const& Form)
{
    if (this->_grade > Form.getGrade())
        std::cout << this->_name << " can not execute " << Form.getName() << " , because " << this->_name << "'s grade is too low." << std::endl;
    if (!Form.isSigned())
        std::cout << this->_name << " can not execute " << Form.getName() << ", because it is not signed " << std::endl;
    std::cout << this->_name  << " executed " << Form.getName() << std::endl;
    Form.execute(*this);
}