#include "Intern.hpp"

Intern::Pair::Pair(std::string const& name, AForm*(*fct)(std::string const&)):
   name(name), fct(fct){}

Intern::Pair::Pair(Pair const& other): name(other.name), fct(other.fct) {}

Intern::Pair::~Pair(){}

Intern::Pair&  Intern::Pair::operator=(const Pair& other)
{
   (void)other;
   return *this;
}

bool  Intern::Pair::correspond(std::string const& name) const
{
   return (this->name == name);
}

AForm*   Intern::Pair::execute(std::string const& target) const
{
   return ((this->fct)(target));
}

Intern::Intern(void)
{
   this->list[0] = new Intern::Pair("PresidentialPardon1", PresidentialPardonForm::target);
   this->list[1] = new Intern::Pair("PresidentialPardon2", PresidentialPardonForm::target);
   this->list[2] = new Intern::Pair("PresidentialPardon3", PresidentialPardonForm::target);
   this->list[3] = new Intern::Pair("RobotmyRequest1", RobotmyRequestForm::target);
   this->list[4] = new Intern::Pair("RobotmyRequest2", RobotmyRequestForm::target);
   this->list[5] = new Intern::Pair("RobotmyRequest3", RobotmyRequestForm::target);
   this->list[6] = new Intern::Pair("ShrubberyCreation1", ShrubberyCreationForm::target);
   this->list[7] = new Intern::Pair("ShrubberyCreation2", ShrubberyCreationForm::target);
   this->list[8] = new Intern::Pair("ShrubberyCreation3", ShrubberyCreationForm::target);
}

Intern::~Intern(void)
{
   for(size_t  i =0; i < 9; ++i)
      delete this->list[i];
}

Intern::Intern(const Intern& other)
{
   *this = other;
}

Intern&    Intern::operator=(const Intern& other)
{
   (void)other;
   return *this;
}

AForm*   makeForm(std::string const & formName, std::string const &target)
{
   AForm*   tmp = NULL;
   for(size_t  i = 0; !tmp&&i < 9; ++i)
      if (this->list[i]->conrrespond(formName))
         tmp = this->list[i]->execute(target);
   if (tmp == NULL)
   {
      std::cout << formName << "does not exist" << std::endl;
      throw Intern::FormDoesNotExistException();
   }
   else
      std::cout << "Intern creates " << *tmp <<std::endl;
   return (tmp);
}