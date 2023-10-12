#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) 
{
   implementCentre(argc, argv);
}

PmergeMe::~PmergeMe(void) 
{
   _vclist.clear();
   _dqlist.clear();
}

PmergeMe::PmergeMe(const PmergeMe& other): _vclist(other._vclist), _dqlist(other._dqlist)
{
   *this = other;
}

PmergeMe&    PmergeMe::operator=(const PmergeMe& other)
{
   if (this != &other)
   {
      if (_vclist.size())
         _vclist.clear();
      if (_dqlist.size())
         _dqlist.clear();
   }
   this->_vclist = other._vclist;
   this->_dqlist = other._dqlist;
   return *this;
}

bool     PmergeMe::validInput(int argc, char **argv)
{
   for (int i = 0; i < argc - 1; ++i)
   {
      std::string tmp = argv[i];
      for(size_t j = 0; j < tmp.length(); ++j)
         if(!isdigit(argv[i][j]))
            return false;
      long long int value = std::atoll(argv[i]);
         if (value < 0 || value > INT_MAX)
            return false;
   }
   return true;
}

void    PmergeMe::vclistSort2(void)
{
   for(unsigned int i = 0; i < _vclist.size() - 3; i += 2)
   {
      if (_vclist[i] > _vclist[i + 2])
      {
         int tmp2 = _vclist[i];
         _vclist[i] = _vclist[i + 2];
         _vclist[i + 2] = tmp2;
         tmp2 = _vclist[i + 1];
         _vclist[i + 1] = _vclist[i + 3];
         _vclist[i + 3] = tmp2;
      }
   }
}

bool    PmergeMe::vclistSort2sorted(const std::vector<int>& list)
{
   for(unsigned int i = 0; i < list.size() - 2; i += 2)
   {
      if (list[i] > list[i + 2])
         return false;
   }
   return true;
}

void    PmergeMe::vclistSort1(void)
{
   for(unsigned int i = 0; i < _vclist.size() - 1; i += 2)
   {
      if (_vclist[i] < _vclist[i + 1])
      {
         int tmp2 = _vclist[i];
         _vclist[i] = _vclist[i + 1];
         _vclist[i + 1] = tmp2;
      }
   }
   while(1)
   {
      vclistSort2();
      if (vclistSort2sorted(_vclist))
         break;
   }
}

void    PmergeMe::vcMerge(int i, std::vector<int>& up)
{
   if (i < up[0])
   {
      up.insert(up.begin(), i);
      return;
   }
   for(size_t size = 1; size < up.size(); ++size)
   {
      if (i > up[size - 1] && i < up[size])
         up.insert(up.begin() + size, i);
   }
   if (i > up[up.size() - 1])
      up.push_back(i);
}

void    PmergeMe::vcSimpleSort(void)
{
   if (_vclist.size() == 2)
   {
      if (_vclist[0] > _vclist[1])
      {
         int tmp = _vclist[0];
         _vclist[0] = _vclist[1];
         _vclist[1] = tmp;
      }
   }
   if (_vclist.size() == 3)
   {
      if ((_vclist[0] > _vclist[1]) && (_vclist[0] > _vclist[2]) && (_vclist[1] < _vclist[2])) // 3 1 2
      {
         _vclist.push_back(_vclist[0]);
         _vclist.erase(_vclist.begin());
      }
      else if ((_vclist[0] > _vclist[1]) && (_vclist[0] > _vclist[2]) && (_vclist[1] > _vclist[2])) // 3 2 1
      {
         _vclist.push_back(_vclist[1]);
         _vclist.push_back(_vclist[0]);
         _vclist.erase(_vclist.begin());
         _vclist.erase(_vclist.begin());
      }
      else if ((_vclist[0] < _vclist[1]) && (_vclist[0] > _vclist[2]) && (_vclist[1] > _vclist[2])) // 2 3 1
      {
         _vclist.insert(_vclist.begin(), _vclist[2]);
         _vclist.pop_back();
      }
      else if ((_vclist[0] > _vclist[1]) && (_vclist[0] < _vclist[2]) && (_vclist[1] < _vclist[2])) // 2 1 3
      {
         int tmp = _vclist[0];
         _vclist.erase(_vclist.begin());
         _vclist.insert(_vclist.begin() + 1, tmp);
      }
      else if ((_vclist[0] < _vclist[1]) && (_vclist[0] < _vclist[2]) && (_vclist[1] > _vclist[2])) // 1 3 2
      {
         int tmp = _vclist[2];
         _vclist.pop_back();
         _vclist.insert(_vclist.begin() + 1, tmp);
      }
   }   
}

void    PmergeMe::vclistSort3(void)
{
   clock_t start = clock();
   if (_vclist.size() <= 3)
   {
      vcSimpleSort();
      clock_t end = clock();
      double diff = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
      _vcTime = diff;
      return;     
   }
   std::vector<int> up;
   std::vector<int> down;
   int tmp = -1;
   if (_vclist.size() % 2 == 1)
   {
      tmp = _vclist[_vclist.size() - 1];
      _vclist.pop_back();
   }
   vclistSort1();
   for(unsigned int i = 0; i < _vclist.size(); i += 2)
      up.push_back(_vclist[i]);
   for(unsigned int j = 1; j < _vclist.size(); j += 2)
      down.push_back(_vclist[j]);
   vcMerge(down[0], up);
   vcMerge(down[1], up);
   int a = 1, b = 1, jacobsthal = 0;
   for(unsigned int i = 4; i < down.size(); ++i)
   {
      jacobsthal = 2 * a + b;
      if ((unsigned int)jacobsthal > down.size())
      {
         jacobsthal = b;
         break;
      }
      for (int diff = jacobsthal; diff >= b + 1; --diff)
         vcMerge(down[diff], up);
      a = b;
      b = jacobsthal;
   }
   while ((unsigned int)jacobsthal < down.size())
      vcMerge(down[jacobsthal++], up);
   if (tmp >= 0)
      vcMerge(tmp, up);
   _vclist.clear();
   down.clear();
   _vclist = up;
   clock_t end = clock();
   double diff = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
   _vcTime = diff;
}

void    PmergeMe::printOutvc(const std::vector<int>& list)
{
   for(size_t i = 0; i < list.size(); ++i)
      std::cout << list[i] << " " << std::flush;
   std::cout << std::endl;
}

void  PmergeMe::dqlistPairSort(void)
{
   for (unsigned int i = 0; i < _dqlist.size() - 3; i += 2)
   {
      if (_dqlist[i] > _dqlist[i + 2])
      {
         int tmp2 = _dqlist[i];
         _dqlist[i] = _dqlist[i + 2];
         _dqlist[i + 2] = tmp2;
         tmp2 = _dqlist[i + 1];
         _dqlist[i + 1] = _dqlist[i + 3];
         _dqlist[i + 3] = tmp2;
      }
   }
}

bool  PmergeMe::dqlistPairSortCheck(const std::deque<int>& list)
{
   for (unsigned int i = 0; i < list.size() - 2; i += 2)
   {
      if (list[i] > list[i + 2])
         return false;
   }
   return true;
}

void    PmergeMe::dqMerge(int i, std::deque<int>& up)
{
   int check = 0;
   if (i < up[0])
   {
      up.push_front(i);
      return ;
   }
   for(size_t size = 1; size <= up.size(); ++size)
   {
      if (i > up[size - 1] && i < up[size])
      {
         up.insert(up.begin() + size, i);
         check = 1;
      }
   }
   if (check == 0 && i > up[up.size() - 1])
      up.push_back(i);
}

void  PmergeMe::dqSimpleSort(void)
{
   if (_dqlist.size() == 2)
   {
      if (_dqlist[0] > _dqlist[1])
      {
         int tmp = _dqlist[0];
         _dqlist[0] = _dqlist[1];
         _dqlist[1] = tmp;
      }
   }
   if (_dqlist.size() == 3)
   {
      if ((_dqlist[0] > _dqlist[1]) && (_dqlist[0] > _dqlist[2]) && (_dqlist[1] < _dqlist[2])) // 3 1 2
      {
         _dqlist.push_back(_dqlist[0]);
         _dqlist.pop_front();
      }
      else if ((_dqlist[0] > _dqlist[1]) && (_dqlist[0] > _dqlist[2]) && (_dqlist[1] > _dqlist[2])) // 3 2 1
      {
         _dqlist.push_back(_dqlist[1]);
         _dqlist.push_back(_dqlist[0]);
         _dqlist.pop_front();
         _dqlist.pop_front();
      }
      else if ((_dqlist[0] < _dqlist[1]) && (_dqlist[0] > _dqlist[2]) && (_dqlist[1] > _dqlist[2])) // 2 3 1
      {
         _dqlist.push_front(_dqlist[2]);
         _dqlist.pop_back();
      }
      else if ((_dqlist[0] > _dqlist[1]) && (_dqlist[0] < _dqlist[2]) && (_dqlist[1] < _dqlist[2])) // 2 1 3
      {
         int tmp = _dqlist[0];
         _dqlist.pop_front();
         _dqlist.insert(_dqlist.begin() + 1, tmp);
      }
      else if ((_dqlist[0] < _dqlist[1]) && (_dqlist[0] < _dqlist[2]) && (_dqlist[1] > _dqlist[2])) // 1 3 2
      {
         int tmp = _dqlist[2];
         _dqlist.pop_back();
         _dqlist.insert(_dqlist.begin() + 1, tmp);
      }
   }
}

void    PmergeMe::dqlistSort(void)
{
   clock_t start = clock();
   if (_dqlist.size() <= 3)
   {
      dqSimpleSort();
      clock_t end = clock();
      double diff = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
      _dqTime = diff;
      return;    
   }
   std::deque<int> up;
   std::deque<int> down;
   int tmp = -1;
   if(_dqlist.size() % 2 == 1)
   {
      tmp = _dqlist[_dqlist.size() - 1];
      _dqlist.pop_back();
   }
   for(unsigned int i = 0; i < _dqlist.size() - 1; i += 2)
   {
      if (_dqlist[i] < _dqlist[i + 1])
      {
         int tmp2 = _dqlist[i];
         _dqlist[i] = _dqlist[i + 1];
         _dqlist[i + 1] = tmp2;
      }
   }
   while(1)
   {
      dqlistPairSort();
      if (dqlistPairSortCheck(_dqlist))
         break;
   }
   for (unsigned int i = 0; i < _dqlist.size(); i += 2)
      up.push_back(_dqlist[i]);
   for (unsigned int i = 1; i < _dqlist.size(); i += 2)
      down.push_back(_dqlist[i]);
   dqMerge(down[0], up);
   dqMerge(down[1], up);
   int a = 1, b = 1, jacobsthal = 0;
   for(unsigned int i = 4; i < down.size(); ++i)
   {
      jacobsthal = 2 * a + b;
      if ((unsigned int)jacobsthal > down.size())
      {
         jacobsthal = b;
         break;
      }
      for (int diff = jacobsthal; diff >= b + 1; --diff)
         dqMerge(down[diff], up);
      a = b;
      b = jacobsthal;
   }
   while ((unsigned int)jacobsthal < down.size())
      dqMerge(down[jacobsthal++], up);
   if (tmp >= 0)
      dqMerge(tmp, up);
   _dqlist.clear();
   down.clear();
   _dqlist = up;
   clock_t end = clock();
   double diff = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
   _dqTime = diff;
}

void    PmergeMe::printOutdq(const std::deque<int>& list)
{
   for(size_t i = 0; i < list.size(); ++i)
      std::cout << list[i] << " " << std::flush;
   std::cout << std::endl;
}

void    PmergeMe::printResult(void)
{
   std::cout << "Before: " << std::flush;
   printOutvc(_vclist);
   vclistSort3();
   dqlistSort();
   std::cout << "After:  ";
   printOutvc(_vclist);
   std::cout << "After:  ";
   printOutdq(_dqlist);

   std::cout << "Time to process a range of " << _vclist.size() << " elements with std::vector<int> : " << std::fixed << std::setprecision(2) << _vcTime << " microseconds.\n";
   std::cout << "Time to process a range of " << _dqlist.size() << " elements with std::deque<int> : " << std::fixed << std::setprecision(2) << _dqTime << " microseconds.\n";
}

bool  PmergeMe::repeatCheck(int a)
{
   for (unsigned int i = 0; i < _vclist.size(); ++i)
      if (a == _vclist[i])
         return false;
   for (unsigned int i = 0; i < _dqlist.size(); ++i)
      if (a == _dqlist[i])
         return false;
   return true;
}


void    PmergeMe::implementCentre(int argc, char **argv)
{
   if (!validInput(argc, argv))
      throw InvalidInput();
   for (int i = 1; i < argc ; ++i)
   {
      int a = atoi(argv[i]);
      if (!repeatCheck(a))
         throw InvalidInput();
      if (a < 0)
         throw InvalidInput();
      _vclist.push_back(a);
      _dqlist.push_back(a);
   }
   if (!_vclist.size() || !_dqlist.size())
      throw ParsingError();
   printResult();
}