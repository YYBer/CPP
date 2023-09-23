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
    private:
        std::string _tree;
        std::string _name;
    public:
    ShrubberyCreationForm(std::string name);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    void    setTree(void);
    std::string getTree(void) const;
    class RightException: public std::exception{
        public:
            virtual const char* what() const throw();
    }; 
    class FileException: public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class SignException: public std::exception{
        public:
            virtual const char* what() const throw();
    };
    void    execute(Bureaucrat const & executor) const;    
};


#endif