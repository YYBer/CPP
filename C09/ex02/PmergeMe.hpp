#ifndef    PMERGEME_HPP
#define    PMERGEME_HPP

#include <iostream>

class PmergeMe
{
    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

    private:
};

#endif
