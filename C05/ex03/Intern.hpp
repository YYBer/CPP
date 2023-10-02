/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:49:10 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 21:49:11 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    INTERN_HPP
#define    INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern(void);
        ~Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm*   makeForm(std::string const & formName, std::string const &target);
};

#endif
