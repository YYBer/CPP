/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:52 by yli               #+#    #+#             */
/*   Updated: 2023/09/07 13:55:37 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& other);

#endif



/*
In C++, these two constructor declarations:

Bureaucrat(std::string const name, int grade);
Bureaucrat(std::string const& name, int grade);
Differ in how they accept and handle the name parameter, specifically regarding whether it is passed by value or by reference.

Bureaucrat(std::string const name, int grade);
In this constructor, the name parameter is passed by value, meaning a copy of the name string is created inside the constructor. 
Any modifications made to name within the constructor will not affect the original name outside of the constructor. 
This approach is suitable when you want to modify or store a local copy of name without affecting the original string.

Bureaucrat(std::string const& name, int grade);
In this constructor, the name parameter is passed by const reference. 
It means that the constructor does not create a copy of the name string but instead works with the original string passed as an argument. 
This is generally more efficient because it avoids unnecessary string copies. 
However, it also means that the constructor cannot modify the original name string because it is const. 
This approach is suitable when you want to work with the original string without modifying it within the constructor.
In summary, the main difference is in how the name parameter is passed and treated within the constructor. 

The first constructor creates a local copy, while the second constructor works with the original string using a const reference. 
The choice between the two depends on your specific needs and performance considerations.
*/


/*
GradeTooHighException and GradeTooLowException, both of which inherit from std::exception. 
These classes provide a what() function that returns a message describing the exception when it's thrown. 
*/