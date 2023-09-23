//RobotomyRequestForm: Required grades: sign 72, exec 45
//Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.

#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

class RobotmyRequestForm: public AForm
{
    public:
    RobotmyRequestForm(std::string name);
    ~RobotmyRequestForm(void);
    RobotmyRequestForm(const RobotmyRequestForm& other);
    RobotmyRequestForm& operator=(const RobotmyRequestForm& other);

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