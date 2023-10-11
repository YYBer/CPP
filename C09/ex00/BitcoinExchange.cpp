#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string argv):_argv(argv) 
{
   fillList();
   validFile();
   std::cout << _output;
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
      time_t unixTime = stringConvertUnixTime(datum);
      _list2[unixTime] = atof(rate.c_str());
   }
   ifs.close();
}

time_t  BitcoinExchange::stringConvertUnixTime(const std::string& datum)
{
      struct tm timeInfo;
      memset(&timeInfo, 0, sizeof(struct tm));
      if (sscanf(datum.c_str(), "%d-%d-%d", &timeInfo.tm_year, &timeInfo.tm_mon, &timeInfo.tm_mday) != 3)
         return -1;
      std::cout << timeInfo.tm_year << timeInfo.tm_mon << std::endl;
      timeInfo.tm_year -= 1900;
      timeInfo.tm_mon -= 1;
      timeInfo.tm_hour = 0;
      timeInfo.tm_min = 0;
      timeInfo.tm_sec = 0;
      if(strptime(datum.c_str(), "%Y-%m-%d", &timeInfo) == NULL)
         return -1;
      time_t unixTime = mktime(&timeInfo);
      if (unixTime == -1)
         return -1;
      return unixTime;
      // std::cout << "unixTime "<< unixTime  << unixTime + 1<< std::endl;   
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
   _datum = datum;
   return true;
}

int    BitcoinExchange::validQuantity(std::string quantity)
{
   float quan = atof(quantity.c_str());
   if (quan < 0)
      return -1;
   else if (quan >= static_cast<float>(__INT_MAX__))
		return 1;
   _quan = quan;
   _quantity = quantity;
   // printOutfile(quantity + " = ");
   return 0; 
}

std::string BitcoinExchange::UnixTimeConvertString(const time_t& time);
{
   struct tm* timeinfo;
   std::string dateString;
   timeinfo = std::localtime(&time);
   if (timeinfo != NULL)
   {
      int year = timeinfo->tm_year + 1900;
      int month = timeinto->tm_mon + 1;
      int day = timeinfo->tm_mday;
      char buffer[11];
      std::sprintf(buffer, "%04d-%02d-%02d", year, month, day);
      std::string dateString(buffer);
   }
   return dateString;
}

float    BitcoinExchange::closestDate(time_t time)
{
   if 
   for (std::map<time_t, float>::iterator it = _list2.begin(); it != _list2.end(); ++it)
   {
      if (time == it->first)
         return it->second;
      time -= 86400;
   }  
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
      std::cout << line << std::endl;
      // if (line.find('|') == std::string::npos)
      //    throw InputError();
      std::istringstream lineStream(line);
      std::string datum;
      std::string a;
      std::string b;
      std::string quantity;
      getline(lineStream, datum, ' ');
      getline(lineStream, a, '|');
      getline(lineStream, b, ' ');
      getline(lineStream, quantity);
      _datum = datum;
      _quantity = quantity;
      std::string msg = "";
      // std::cout << "datum:" << datum << "quantity:" << quantity << std::endl;
      if (!validDatum(datum))
         msg = "Error: bad input => " + _datum + "\n";
      if (validQuantity(quantity) == -1)
         msg = "Error: not a positive number.\n";
      else if (validQuantity(quantity) == 1)
         msg = "Error: too large a number.\n";
      float result(0);
      time_t unixTime = stringConvertUnixTime(datum);
      for (std::map<time_t, float>::iterator it = _list2.begin(); it != _list2.end(); ++it)
      {
         // std::cout << "it->first" << it->first << "it->second" << it->second << std::endl;
         if (unixTime == it->first)
         {
            // std::cout << "it->second" << it->second << std::endl;
            result = _quan * it->second;
         }
         else result = _quan * closestDate(unixTime);
      }
      std::ostringstream oss;
      oss << result;
      _oss = oss.str();
      if (msg == "")
         msg = _datum + " => " + _quantity + " = " + _oss + "\n";
      printOutfile(msg);
   }
}

void    BitcoinExchange::printOutfile(const std::string& msg)
{
   _output +=  msg;
}