/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:57 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 20:33:34 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm:: ShrubberyCreationForm(std::string name): AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
    *this = other;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    (void) other;
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (executor.getGrade() > this->getExecuteGrade())
        throw RightException();
    if (!this->isSigned())
        throw SignException();
    std::string fileName = executor.getName() + "_shrubbery";
    std::ofstream outfile(fileName.c_str());
    if (!outfile.is_open())
    {
        outfile.close();
        throw FileException();
    }
    std::string tree =
    "                     . . .\n"
"                   .        .  .     ..    .\n"
"                .                 .         .  .\n"
"                                .\n"
"                               .                ..\n"
"               .          .            .              .\n"
"               .            '.,        .               .\n"
"               .              'b      *\n"
"                .              '$    #.                ..\n"
"               .    .           $:   #:               .\n"
"             ..      .  ..      *#  @):        .   . .\n"
"                          .     :@,@):   ,.**:'   .\n"
"              .      .,         :@@*: ..**'      .   .\n"
"                       '#o.    .:(@'.@*""  .\n"
"               .  .       'bq,..:,@@*'   ,*      .  .\n"
"                          ,p$q8,:@)'  .p*'      .\n"
"                   .     '  . '@@Pp@@*'    .  .\n"
"                    .  . ..    Y7'.'     .  .\n"
"                              :@):.\n"
"                             .:@:'.\n"
"                           .::(@:).  \n";
    outfile << tree;
    outfile.close();
}