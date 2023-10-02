/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:49:29 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 21:49:30 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern& other)
{
   *this = other;
}

Intern&    Intern::operator=(const Intern& other)
{
   (void)other;
   return *this;
}

AForm*   Intern::makeForm(std::string const & formName, std::string const &target)
{
   std::string formNames[] = {"RobotmyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
   int i = 0;
   for (i = 0; i < 3; ++i)
   {
      if (formName == formNames[i])
         break;
   }
   switch(i)
   {
      case 0:
      {
         std::cout << "Intern creates " << formName <<std::endl;
         return new RobotmyRequestForm(target);
      }
      case 1:
      {
         std::cout << "Intern creates " << formName <<std::endl;
         return new PresidentialPardonForm(target);
      }
      case 2:
      {
         std::cout << "Intern creates " << formName <<std::endl;
         return new ShrubberyCreationForm(target);
      }
      default:
      {
         std::cout << formName << " doesn’t exist"  <<std::endl;
         return NULL;
      }
   }
}