/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:52 by yli               #+#    #+#             */
/*   Updated: 2023/09/23 16:02:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string const& name, int grade);
        ~Bureaucrat(void) {};
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName(void) const;
        int getGrade(void) const;

        void increment(void);
        void decrement(void);
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too High";
                }
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too low";
                }
        };

        

        void    executeForm(AForm const& AForm);
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& other);

#endif


//add the executeForm(Form const & form) member function to the Bureau- crat. It must attempt to execute the form. If it’s successful, print something like:
//   <bureaucrat> executed <form>