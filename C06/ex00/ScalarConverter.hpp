#ifndef    SCALARCONVERTER_HPP
#define    SCALARCONVERTER_HPP

#include <iostream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
    public:
        ScalarConverter(std::string const& argv);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        void    convert(void);
        //void  checkChar(void);
        void  checkFormat(void);
        int   checkTimes(char c);
        bool  checkAllInt(void);
        bool  checkDouble(void);
        bool  checkFloat(void);

    private:
        std::string _argv;
        const char*   _str;
        char  _char;
        int _int;
        float   _float;
        double  _double;
        bool    _isChar;
        bool    _isInt;
        bool    _isFloat;
        bool    _isDouble;
};

#endif
