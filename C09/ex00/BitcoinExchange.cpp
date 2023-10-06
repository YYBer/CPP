#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string argv):_argv(argv) 
{
   fillList();
   validFile();
   std::cout << "in constractor: "<< _output << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
   if (_list.size())
      _list.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
   *this = other;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
   this->_argv = other._argv;
   this->_list = other._list;
   return *this;
}


void    BitcoinExchange::fillList(void)
{
   std::ifstream ifs("datatest.csv");
   std::string line;
   std::string datum;
   std::string rate;
   if (!ifs.good())
      throw FileError();
   while(std::getline(ifs, line))
   {
      std::istringstream tokenStream(line);
      getline(tokenStream, datum, ',');
      getline(tokenStream, rate);
      _list[datum] = atof(rate.c_str());
   }
   ifs.close();
}

bool    BitcoinExchange::validDatum(std::string datum)
{
   std::string year;
   std::string month;
   std::string day;
   std::istringstream datumStream(datum);
   std::getline(datumStream, year, '-');
   std::getline(datumStream, month, '-');
   std::getline(datumStream, day, ' ');
   // std::cout << "year:" << year << " month:" << month << " day:" << day << std::endl;
   int yeari = atoi(year.c_str());
   // std::cout << "yeari: "<< yeari << std::endl;
   if (yeari < 2009 || yeari > 2022)
      return false;
   int monthi = atoi(month.c_str());
   if (monthi < 1 || monthi > 12)
      return false;
   int dayi = atoi(day.c_str());
   if ((dayi < 1 || dayi > 31) && (monthi == 1 || monthi == 3 || monthi == 5 || monthi == 7 || monthi == 8 || monthi == 10 || monthi == 12))
      return false;
   if ((dayi < 1 || dayi > 30) && (monthi == 2 || monthi == 4 || monthi == 6 || monthi == 9 || monthi == 11))
      return false;
   // std::cout << "0" << datum << std::endl;
   printOutfile(datum + " => ");
   return true;
}

int    BitcoinExchange::validQuantity(std::string quantity)
{
   double quan = atof(quantity.c_str());
   if (quan < 0)
      return -1;
   else if (quan > 2147483647)
      return 1;
   _quan = quan;
   printOutfile(quantity + " = ");
   return 0; 
}

void    BitcoinExchange::validFile(void)
{
   std::string line;
   std::ifstream ifs(this->_argv.c_str());
   if (!ifs)
      throw FileError();
   std::getline(ifs, line);
   if (line.compare("date | value"))
      throw InputError();
   while(std::getline(ifs, line))
   {
      // std::cout << line << std::endl;
      if (line.find('|') == std::string::npos)
         throw InputError();
      std::istringstream lineStream(line);
      std::string datum;
      std::string a;
      std::string b;
      std::string quantity;
      getline(lineStream, datum, ' ');
      getline(lineStream, a, '|');
      getline(lineStream, b, ' ');
      getline(lineStream, quantity);
      // std::cout << "datum:" << datum << "quantity:" << quantity << std::endl;
      if (!validDatum(datum))
         printOutfile("Error: bad input" + datum + "\n");
      if (validQuantity(quantity) == -1)
         printOutfile("Error: not a positive number.\n");
      else if (validQuantity(quantity) == 0)
         printOutfile("Error: too large a number.\n");
      double result(0);
      for (std::map<std::string, double>::iterator it = _list.begin(); it != _list.end(); ++it)
      {
         // std::cout << "it->first" << it->first << "it->second" << it->second << std::endl;
         if (!datum.compare(it->first))
         {
            // std::cout << "it->second" << it->second << std::endl;
            result = _quan * it->second;
            break;
         }
      }
      // std::cout << "_quan: " << _quan << "result" << result << std::endl;
      std::ostringstream oss;
      oss << result;
      printOutfile(oss.str() + '\n');
   }
}

void    BitcoinExchange::printOutfile(const std::string& original)
{
   _output += original;
}