#ifndef    BITCOINEXCHANGE_HPP
#define    BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
// #include <string>
#include <ctime>
#include <cstring>

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
        void    printOutfile(const std::string& msg);
        void    fillList(void);
        time_t  stringConvertUnixTime(const std::string& datum);
        std::string UnixTimeConvertString(const time_t& time);
        float    closestDate(time_t time);
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
        // class DatumError: public std::exception{
        //     public:
        //         virtual const char* what() const throw(){
        //             return "bad datum";
        //         };
        // };
        // class QuantityError: public std::exception{
        //     public:
        //         virtual const char* what() const throw(){
        //             return "bad Quantity";
        //         };
        // };

    private:
        std::string _argv;
        std::map<std::string, float> _list;
        std::map<time_t , float> _list2;
        std::string _output;
        float _quan;
        std::string _quantity;
        std::string _datum;
        std::string _oss;
};

#endif


// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.

// #include <iostream>
// #include <ctime>
// #include <cstring>

// int main() {
//     std::string dateString = "2023-10-07"; // Replace this with your date string
//     struct tm timeInfo;

//     // Initialize timeInfo with default values
//     memset(&timeInfo, 0, sizeof(struct tm));

//     // Use sscanf to parse the date string
//     if (sscanf(dateString.c_str(), "%d-%d-%d", &timeInfo.tm_year, &timeInfo.tm_mon, &timeInfo.tm_mday) != 3) {
//         std::cerr << "Error parsing date string" << std::endl;
//         return 1;
//     }

//     // Adjust year and month to be 0-based (C++98)
//     timeInfo.tm_year -= 1900;
//     timeInfo.tm_mon -= 1;

//     // Set the remaining time components to default values (midnight)
//     timeInfo.tm_hour = 0;
//     timeInfo.tm_min = 0;
//     timeInfo.tm_sec = 0;

//     // Convert the parsed date into a Unix timestamp
//     time_t unixTime = mktime(&timeInfo);

//     if (unixTime == -1) {
//         std::cerr << "Error converting date to Unix timestamp" << std::endl;
//         return 1;
//     }

//     std::cout << "Unix timestamp: " << unixTime << std::endl;

//     return 0;
// }




