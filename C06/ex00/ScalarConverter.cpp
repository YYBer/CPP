#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string const& argv)
{
   _argv = argv;
   _str = argv.c_str();
   _int = 0;
   _float = 0;
   _double = 0;
   _char = '\0';
   _isChar = false;
   _isInt = false;
   _isFloat = false;
   _isDouble = false;
   convert();
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

int   ScalarConverter::checkTimes(char c)
{
   int   count = 0;
   for (size_t i = 0; i < _argv.length(); ++i)
   {
      if (_argv[i] == c)
         count++;
    }
    return count;
}

bool  ScalarConverter::checkAllInt(void)
{
   if (_argv[0] < 43 || _argv[0] == 44 || (_argv[0] < 48 && _argv[0] > 45)|| _argv[0] > '9')
      return false;
   for(unsigned long i = 1; i < _argv.size(); ++i)
   {
      if (_argv[i]> '9' || _argv[i] < '0')
         return false;
   }
   return true;
}

bool  ScalarConverter::checkDouble(void)
{
   if (_argv.find('.') == _argv.size() - 1)
      return false;
   else if (checkTimes('.') != 1)
      return false;
   if (_argv[0] < 43 || _argv[0] == 44 || (_argv[0] < 48 && _argv[0] > 45)|| _argv[0] > '9')
      return false;
   for(unsigned long i = 1; i < _argv.size(); ++i)
   {
      if (_argv[i]> '9' || _argv[i] < 46 || _argv[i] == 47)
         return false;
   }
   return true;
}

bool  ScalarConverter::checkFloat(void)
{
   if (_argv.find('.') == _argv.size() - 1)
      return false;
   if (_argv.find('f') != _argv.size() - 1)
      return false; 
   if (checkTimes('.') != 1)
      return false;
   if (checkTimes('f') != 1)
      return false;
   int i = _argv.find('.');
   if (_argv[i + 1] == 'f')
      return false;
   if (_argv[0] < 43 || _argv[0] == 44 || (_argv[0] < 48 && _argv[0] > 45)|| _argv[0] > '9')
      return false;
   for(unsigned long i = 1; i < _argv.size(); ++i)
   {
      if (_argv[i] > 102 || _argv[i] < 46 || _argv[i] == 47 || (_argv[i] > '9' && _argv[i] < 102))
         return false;
   }
   return true;
}

void  ScalarConverter::checkFormat(void)
{
   if (checkAllInt())
      _isInt = true;
   else if (checkFloat())
      _isFloat = true;
   else if (checkDouble())
      _isDouble = true;
   else
      _isChar = true;
}

void    ScalarConverter::convert(void)
{
   checkFormat();
   if (!_isChar)
   {
      _int = atoi(this->_argv.c_str());
      _float = atof(this->_argv.c_str());
      _double = atof(this->_argv.c_str());
      if (_int < 32)
         _str = "Non displayable";
      else
         _char = (char)_int;
      std::cout << std::fixed << std::setprecision(1);
      if (_char)
         std::cout <<"char: '" << _char  << "'"<< std::endl;
      else
         std::cout << "char:  " << _str << std::endl;
      std::cout << "int: " << _int << std::endl;
      std::cout << "float: " << _float  << "f" << std::endl;
      std::cout << "double: " << _double << std::endl;
   }
   else
      std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
}