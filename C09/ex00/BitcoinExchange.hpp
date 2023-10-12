#ifndef    BITCOINEXCHANGE_HPP
#define    BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <bits/stdc++.h> 

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string argv);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        bool        validDatum(std::string datum);
        void        handleFile(void);
        int         validQuantity(std::string quantity);
        void        printOutfile(const std::string& msg);
        void        fillList(void);
        time_t      stringConvertUnixTime(const std::string& datum);
        std::string UnixTimeConvertString(const time_t& time);
        float       closestDate(time_t time);
        class   FileError: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "could not open file.";
                };
        };
        class InputError: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "bad input";
                };
        };
        class DatumError: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "bad datum";
                };
        };

    private:
        std::string _argv;
        std::map<time_t , float> _list;
        std::string _output;
        float _quan;
        std::string _quantity;
        std::string _datum;
        std::string _oss;
};

#endif


