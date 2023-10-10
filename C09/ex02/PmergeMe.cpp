#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) 
{
   implementCentre(argc, argv);
}

PmergeMe::~PmergeMe(void) 
{
   if (_vclist.size())
      _vclist.clear();
   if (_dqlist.size())
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
   for(unsigned int i = 0; i < _vclist.size() - 3; i += 4)
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
void    PmergeMe::vcMerge(int i, std::vector<int>& up)
{
   if (i < up[0])
   {
      up.insert(up.begin(), i);
      return;
   }
   for(size_t size = 1; size < up.size(); ++size)
   {
      if (i < up[i] && i > up[i - 1])
      {
         up.insert(up.begin() + i, i);
         break;
      }
   }
}

void    PmergeMe::vclistSort2(void)
{
   time_t start;
   time(&start);
   std::vector<int> up;
   std::vector<int> down;
   int tmp = -1;
   if (_vclist.size() % 2 == 1)
   {
      tmp = _vclist[_vclist.size() - 1];
      _vclist.pop_back();
   }
   vclistSort1();
   for(unsigned int i = 0; i < _vclist.size() ; i += 2)
      up.push_back(_vclist[i]);
   for(unsigned int j = 1; j < _vclist.size(); j += 2)
      down.push_back(_vclist[j]);
   up.insert(up.begin(), down[0]);
   vcMerge(down[1], up);
   // if (down[1] < up[0])
   //    up.insert(up.begin(), down[1]);
   // else if (down[1] < up[1] && down[1] > up[0])
   //    up.insert(up.begin() + 1, down[1]);
   // else
   //    up.insert(up.begin() + 2, down[1]);
   int a = 1, b = 1, jacobsthal = 0;
   // std::cout << "jacobsthal: " << jacobsthal << " ";
   for(unsigned int i = 4; i < down.size(); ++i)
   {
      jacobsthal = 2 * a + b;
      std::cout << "jacobsthal: " << jacobsthal << " ";
      for (int diff = jacobsthal; diff > b; --diff)
         vcMerge(down[diff], up);
      a = b;
      b = jacobsthal;
   }
   if (tmp >= 0)
      vcMerge(tmp, up);
   time_t end;
   time(&end);
   // time_t diff = end - start;
   // std::cout << "diff: " << diff << std::endl;
   // _vcTime = convertTime(diff);
}

// std::string convertTime(const time_t& diff)
// {

// }

void    PmergeMe::printOutvc(const std::vector<int>& list)
{
   for(size_t i = 0; i < list.size(); ++i)
      std::cout << list[i] << " " << std::flush;
   std::cout << std::endl;
}

void    PmergeMe::printResult(void)
{
   std::cout << "Before: " << std::flush;
   printOutvc(_vclist);

   vclistSort2();

   std::cout << "After: ";
   printOutvc(_vclist);

   std::cout << "Time to process a range of " << _vclist.size() << " elements with std::vector<int> : ";
   // std::cout << "Time to process a range of " << _dqlist.size() << " elements with std::deque<int> : ";
}


void    PmergeMe::implementCentre(int argc, char **argv)
{
   // if (!validInput(argc, argv))
   //    throw InvalidInput();
   for (int i = 1; i < argc ; ++i)
   {
      _vclist.push_back(atoi(argv[i]));
      _dqlist.push_back(atoi(argv[i]));
   }
   if (!_vclist.size() || !_dqlist.size())
      throw ParsingError();
   printResult();
}