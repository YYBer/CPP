#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    try{
    BitcoinExchange exchange(argv[1]);
    } catch (const BitcoinExchange::DatumError& e){
        std::cerr << e.what() << std::endl;
    } catch (const BitcoinExchange::FileError& e){
        std::cerr << e.what() << std::endl;
    } catch (const BitcoinExchange::InputError& e){
        std::cerr << e.what() << std::endl;
    }
}