#ifndef    BITCOINEXCHANGE_HPP
#define    BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string argv);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        bool    validDatum(void);
        bool    validRate(void);
        void    execute(void);

    private:
        std::string _argv;
};

#endif
