#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string argv):_argv(argv) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
   *this = other;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
   this->_argv = other._argv;
   return *this;
}

bool    BitcoinExchange::validDatum(void)
{

}


