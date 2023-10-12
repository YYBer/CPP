#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string argv):_argv(argv) 
{
   fillList();
   handleFile();
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
   std::ifstream ifs("data.csv");
   std::string line;
   std::string datum;
   std::string rate;
   if (!ifs.good())
      throw FileError();
   std::getline(ifs, line);
   while(std::getline(ifs, line))
   {
      std::istringstream tokenStream(line);
      getline(tokenStream, datum, ',');
      getline(tokenStream, rate);
      time_t firstElement = stringConvertUnixTime(datum);
      _list[firstElement] = atof(rate.c_str());
      time_t unixTime = stringConvertUnixTime(datum);
      _list[unixTime] = atof(rate.c_str());
   }
   ifs.close();
}

time_t  BitcoinExchange::stringConvertUnixTime(const std::string& datum)
{
      struct tm timeInfo;
      memset(&timeInfo, 0, sizeof(struct tm));
      if (sscanf(datum.c_str(), "%d-%d-%d", &timeInfo.tm_year, &timeInfo.tm_mon, &timeInfo.tm_mday) != 3)
         return -1;
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
   int yeari = atoi(year.c_str());
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
   return 0; 
}

std::string BitcoinExchange::UnixTimeConvertString(const time_t& time)
{
   struct tm* timeinfo;
   std::string dateString;
   timeinfo = std::localtime(&time);
   if (timeinfo != NULL)
   {
      int year = timeinfo->tm_year + 1900;
      int month = timeinfo->tm_mon + 1;
      int day = timeinfo->tm_mday;
      char buffer[11];
      std::sprintf(buffer, "%04d-%02d-%02d", year, month, day);
      std::string dateString(buffer);
   }
   return dateString;
}

float    BitcoinExchange::closestDate(time_t time)
{
   std::map<time_t, float>::iterator pos = _list.upper_bound(time);
   if(time < _list.begin()->first) 
      return -1;
   if (pos != _list.end())
   {
      pos--;
      return pos->second;
   }
   return -1; 
}

void  BitcoinExchange::handleFile(void)
{
   std::string line;
   std::ifstream ifs(this->_argv.c_str());
   if (!ifs)
      throw FileError();
   std::getline(ifs, line);
   if (line.compare("date | value"))
      throw InputError();
   std::string msg = "";
   while(std::getline(ifs, line))
   {
      std::string msg = "";
      std::istringstream lineStream(line);
      std::string datum;
      std::string a;
      std::string b;
      std::string quantity = "";
      getline(lineStream, datum, ' ');
      _datum = datum;
      if (line.find('|') == std::string::npos)
         msg = "Error: bad input => " + _datum + "\n";
      getline(lineStream, a, '|');
      getline(lineStream, b, ' ');
      getline(lineStream, quantity);
      if (!quantity.size())
         msg = "Error: bad input => " + _datum + "\n";
      _quantity = quantity;
      if (!validDatum(datum) && msg == "")
         msg = "Error: bad input => " + _datum + "\n";
      if (validQuantity(quantity) == -1 && msg == "")
         msg = "Error: not a positive number.\n";
      else if (validQuantity(quantity) == 1 && msg == "")
         msg = "Error: too large a number.\n";
      float result(-1);
      time_t unixTime = stringConvertUnixTime(datum);
      std::map<time_t, float>::iterator test = _list.end();
      test--;
      if (msg == "")
      {
         for (std::map<time_t, float>::iterator it = _list.begin() ; it != _list.end(); ++it)
         {
            if (unixTime == it->first && _quan >= 0)
            {
               result = _quan * it->second;
               msg = "";
            }
            else
            {
               result = _quan * closestDate(unixTime);
               if (result < 0) 
                  msg = "Error: bad input3 => " + _datum + "\n";
            }
         }
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