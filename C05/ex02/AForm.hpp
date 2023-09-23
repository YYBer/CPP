/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:06 by user              #+#    #+#             */
/*   Updated: 2023/09/23 16:31:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool    _signed;
        const int   _grade;
        const int   _executegrade;
    
    public:
        AForm(const std::string & name, const int grade, const int executegrade);
        virtual ~AForm(void){};
        AForm(const AForm & other);
        AForm& operator=(const AForm& other);
        
        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return ("Grade too high");
                };
        };
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return ("Grade too low");
                };
        };
        class AFormAlreadySignedException: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return ("execute grade errors");
                };
        };
        class RightException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class SignException: public std::exception{
            public:
                virtual const char * what() const throw();
        };

        int getGrade(void) const;
        int getExecuteGrade(void) const;
        std::string getName(void) const;
        bool    isSigned(void) const;
        void    signAForm(Bureaucrat const & other);
        
        virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const & other);

#endif