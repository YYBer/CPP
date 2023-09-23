#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm(std::string name): AForm(name, 72, 45), _name(name) {}

RobotmyRequestForm::~RobotmyRequestForm(void){}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm& other): AForm(other)
{
    *this = other;
}

RobotmyRequestForm& RobotmyRequestForm::operator=(const RobotmyRequestForm& other)
{
    this->_name = other._name;
    return *this;
}

void    RobotmyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExecuteGrade())
        throw RightException();
    if (!this->isSigned())
        throw SignException();
    std::cout << "ZzzZZ  pilipala ****   ZzzzZZZ pilipala" << std::endl;
    if ((rand() % 100) > 50)
        std::cout << this->_name << " has been robotimized successfully." << std::endl;
    else
        std::cout << this->_name << " the robotomy failed." << std::endl;
}




