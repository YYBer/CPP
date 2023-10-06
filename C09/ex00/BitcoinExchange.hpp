#ifndef    BITCOINEXCHANGE_HPP
#define    BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string argv);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        bool    validDatum(std::string datum);
        void    validFile(void);
        int    validQuantity(std::string quantity);
        void    printOutfile(const std::string& original);
        void    fillList(void);
        class   FileError: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "bad file!";
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
        class QuantityError: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "bad Quantity";
                };
        };

    private:
        std::string _argv;
        std::map<std::string, double> _list;
        std::string _output;
        double _quan;
};

#endif
