#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm:: ShrubberyCreationForm(std::string name): AForm(name, 145, 137), _name(name) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
    *this = other;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    this->_name = other._name;
    return *this;
}

void    ShrubberyCreationForm::setTree(void)
{
    this->_tree =
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
}

std::string ShrubberyCreationForm::getTree(void) const
{
    return this->_tree;
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
    outfile << getTree();
    outfile.close();
}