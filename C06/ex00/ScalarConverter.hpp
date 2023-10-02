/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:27:29 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 17:27:30 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        static void    convert(char*   argv);

    private:
        static std::string _argv;
        static const char*   _str;
        static char  _char;
        static int _int;
        static float   _float;
        static double  _double;
        static bool    _isChar;
        static bool    _isInt;
        static bool    _isFloat;
        static bool    _isDouble;
        ScalarConverter(){};
        ~ScalarConverter(void) {};
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        static void  checkFormat(void);
        static int   checkTimes(char c);
        static bool  checkAllInt(void);
        static bool  checkDouble(void);
        static bool  checkFloat(void);
};

#endif
