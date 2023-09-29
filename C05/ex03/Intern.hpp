#ifndef    INTERN_HPP
#define    INTERN_HPP

#include <iostream>
//#include "AForm.hpp"
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
        class FormDoesNotExistException: public std::exception{
            virtual const char* what() const throw(){
                return "Form does not exit";};};
    private:
        class Pair
        {
            private:
                Pair();
                std::string const name;
                AForm*(*fct)(std::string const &);
            public:
                Pair(std::string const& name, AForm*(*fct)(std::string const&));
                Pair(const Pair& other);
                Pair& operator=(const Pair& other);
                bool    correspond(std::string const & name)const;
                AForm*   execute(std::string const& target) const;
        };
        Pair *list[9];
};

#endif
