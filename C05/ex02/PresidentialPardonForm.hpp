//PresidentialPardonForm: Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.


#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
    PresidentialPardonForm(std::string name);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    void    execute(Bureaucrat const & executor) const;
    class RightException: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class SignException: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    private:
        std::string _name;
};

#endif