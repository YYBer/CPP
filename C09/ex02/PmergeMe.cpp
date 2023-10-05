#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
   *this = other;
}

PmergeMe&    PmergeMe::operator=(const PmergeMe& other)
{
   (void)other;
   return *this;
}
