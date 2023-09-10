/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:02 by user              #+#    #+#             */
/*   Updated: 2023/09/08 19:36:08 by user             ###   ########.fr       */
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
}



// Form::Form(std::string const &name, int const signGrade, int const executeGrade):
// 	name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade)
// {
// 	if (signGrade < 1 || executeGrade < 1)
// 		throw Form::GradeTooHighException();
// 	else if (signGrade > 150 || executeGrade > 150)
// 		throw Form::GradeTooLowException();
// }

// Form::Form(Form const &other):
// 	name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade)
// {
// 	if (signGrade < 1 || executeGrade < 1)
// 		throw Form::GradeTooHighException();
// 	else if (signGrade > 150 || executeGrade > 150)
// 		throw Form::GradeTooLowException();
// }