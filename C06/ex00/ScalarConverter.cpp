#include "ScalarConverter.hpp"
        float   _float;
        double  _double;
        bool    _isChar;
        bool    _isInt;
        bool    _isFloat;
        bool    _isDouble;
ScalarConverter::ScalarConverter(std::string const& argv): _argv(argv)
{
   _str = argv.c_str();
   _int = 0;
   _float = 0;
   _double = 0;
   _isChar = false;
   _isInt = false;
   _isFloat = false;
   _isDouble = false;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
   *this = other;
}

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other)
{
   this->_argv = other._argv;
   return *this;
}

bool  ScalarConverter::checkDigit(void)
{
   if (isdigit(atoi(this->_argv.c_str())))
   {
      _int = atoi(this->_argv.c_str());
      _isInt = true;
      return true;
   }
   return false;
}

bool  ScalarConverter::checkFloat(void)
{
   for(int i = 0; i < _argv.size(); ++i)
   {
      if (_argv.find('.') == 1 && _argv.back() == 'f')
      {
         _isFloat = true;
         _float = 
      }
   }

}

void    ScalarConverter::convert(void)
{
   if (checkDigit()
}