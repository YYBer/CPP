/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:58:02 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 21:52:06 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ShrubberyCreationForm: Required grades: sign 145, exec 137
//Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
# include <fstream>
# include <string>
# include <cstdlib>

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
    public:
    ShrubberyCreationForm(std::string name);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    class FileException: public std::exception{
        public:
            virtual const char* what() const throw(){
                return ("open file failed.");
            };
    };
    void    execute(Bureaucrat const & executor) const;
    AForm*   target(std::string const& target);   
};


#endif