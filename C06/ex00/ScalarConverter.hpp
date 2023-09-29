#ifndef    SCALARCONVERTER_HPP
#define    SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter(std::string const& argv);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        void    convert(void);
        bool  checkDigit(void);
        bool  checkFloat(void);

    private:
        std::string _argv;
        char*   _str;
        int _int;
        float   _float;
        double  _double;
        bool    _isChar;
        bool    _isInt;
        bool    _isFloat;
        bool    _isDouble;
};

#endif
