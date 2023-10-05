#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
   *this = other;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
   (void)other;
   return *this;
}
