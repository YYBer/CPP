#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Sorry, I can't do anything for you!\n";
        return 1;
    }
    BitcoinExchange exchange(argv[1]);
}