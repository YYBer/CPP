/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:49 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 21:53:58 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int    main()
{
    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("RobotmyRequestForm", "test");
    delete rrf;

    AForm*  a;
    a = someRandomIntern.makeForm("PresidentialPardonForm", "test");
    delete a;

    AForm*  b;
    b = someRandomIntern.makeForm("sdfsd", "test");
    delete b;
}
