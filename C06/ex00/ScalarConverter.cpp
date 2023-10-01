#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string const& argv): _argv(argv)
{
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

void  ScalarConverter::checkDigit(void)
{
   _int = atoi(this->_argv.c_str());
   _float = atof(this->_argv.c_str());
   _double = std::atof(this->_argv.c_str());
   if (_int < 32)
      _str = "Non displayable";
   else
      _char = (char)_int;
   std::cout << std::fixed << std::setprecision(1);
   if (_char)
      std::cout << "char: " << _char << std::endl;
   else
      std::cout << "char:  " << _str << std::endl;
   std::cout << "int: " << _int << std::endl;
   std::cout << "float: " << _float  << "f" << std::endl;
   std::cout << "double: " << _double << std::endl;
}

bool  ScalarConverter::checkContainInt(void)
{
   for(unsigned long i = 0; i < _argv.size(); ++i)
   {
      if (_argv[i] < '0' || _argv[i] > '9')
         return false;
      if (_argv[i]>= '0' && _argv[i] <= '9')
         return true;
   }
   return false;
}

bool  ScalarConverter::checkFormat(void)
{
   for(unsigned long i = 0; i < _argv.size(); ++i)
   {
      if ((_argv[i] < 46 || _argv[i] == 47 || (_argv[i] > '9' && _argv[i] < 102) || _argv[i] > 102))
         return true;
   }
   return false;
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
   if (_argv[0] < 45 || _argv[0]> '9' || (_argv[0] > 45 && _argv[0] < '0'))
      return false;
   for(unsigned long i = 1; i < _argv.size(); ++i)
   {
      if (_argv[i]> '9' || _argv[i] < '0')
         return false;
   }
   _isInt = true;
   return true;
}

bool  ScalarConverter::checkFloat(void)
{
   for(unsigned long i = 0; i < _argv.size(); ++i)
   {
      if (_argv.find('.') != _argv.size()-1 && _argv.back() == 'f' && checkContainInt() && !checkFormat() && checkTimes('f') == 1 && checkTimes('.') == 1)
         _isFloat = true;
      return true;
   }
   return false;
}

void  ScalarConverter::checkFloat2(void)
{
   _int = atoi(this->_argv.c_str());
   _float = atof(this->_argv.c_str());
   _double = std::atof(this->_argv.c_str());
   _char = (char)_int;
   std::cout << std::fixed << std::setprecision(1);
   if (_char)
      std::cout << "char: " << _char << std::endl;
   else
      std::cout << "char:  " << _str << std::endl;
   std::cout << "int: " << _int << std::endl;
   std::cout << "float: " << _float  << "f" << std::endl;
   std::cout << "double: " << _double << std::endl;
}

bool  ScalarConverter::checkDouble(void)
{
   if (_argv[0] == '-')
      if (checkTimes('-') != 1)
         return false;
   for(unsigned long i = 1; i < _argv.size(); ++i)
   {
      if (_argv.find('.') != _argv.size()-1 && checkContainInt() && !checkFormat() && checkTimes('.') == 1)
      {
         _isDouble = true;
         return true;
      }
   }
   return false;
}

void  ScalarConverter::checkDouble2(void)
{
   _int = atoi(this->_argv.c_str());
   _float = atof(this->_argv.c_str());
   _double = std::atof(this->_argv.c_str());
   _char = (char)_int;
   std::cout << std::fixed << std::setprecision(1);
   if (_char)
      std::cout << "char: " << _char << std::endl;
   else
      std::cout << "char:  " << _str << std::endl;
   std::cout << "int: " << _int << std::endl;
   std::cout << "float: " << _float  << "f" << std::endl;
   std::cout << "double: " << _double << std::endl;
}

void  ScalarConverter::checkChar(void)
{
   _isChar = true;
   std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
}

void    ScalarConverter::convert(void)
{
   if (checkAllInt())
   {
      checkDigit();
      std::cout << "0\n";
      return;
   }
   if (checkFloat())
   {
      checkFloat2();
      std::cout << "1\n";
      return;
   }
   if (checkDouble())
   {
      checkDouble2();
      std::cout << "2\n";
      return;
   }
   checkChar();
}