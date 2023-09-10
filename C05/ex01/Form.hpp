/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:06 by user              #+#    #+#             */
/*   Updated: 2023/09/08 19:30:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>

class Form
{
    private:
        const std::string _name;
        bool    _signed;
        const int   _grade;
        const int   _executegrade;
    
    public:
        Form(const std::string & name, const int grade, const int executegrade);
        ~Form(void){};
        Form(const Form & other);
        Form& operator=(const Form& other);
        
        class GradeTooHighException: public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("Grade too high");
            };
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("Grade too low");
            };
        };
        class FormAlreadySignedException: public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("execute grade errors");
            };
        };

        std::string getName(void) const;
        int getGrade(void) const;

        void increment(void);
        void decrement(void);
    
};


#endif