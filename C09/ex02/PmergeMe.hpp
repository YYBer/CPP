#ifndef    PMERGEME_HPP
#define    PMERGEME_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <deque>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <iomanip>


class PmergeMe
{
    public:
        PmergeMe(int argc ,char**argv);
        ~PmergeMe(void);
        void    printResult(void);
        void    printOutvc(const std::vector<int>& list);
        void    printOutdq(void);
        bool    validInput(int argc, char **argv);
        bool    repeatCheck(int a);
        void    vcSimpleSort(void);
        void    vclistSort1(void);
        void    vclistSort2(void);
        void    vcMerge(int i, std::vector<int>& up);
        bool    vclistSort2sorted(const std::vector<int>& list);
        void    vclistSort3(void);
        void    dqSimpleSort(void);
        void    dqlistPairSort(void);
        bool    dqlistPairSortCheck(const std::deque<int>& list);
        void    dqMerge(int i, std::deque<int>& up);
        void    dqlistSort(void);
        void    printOutdq(const std::deque<int>& list);
        void    implementCentre(int argc, char **argv);
        class InvalidInput: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Error: InvalidInput";
            };
        };
        class ParsingError: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Error: Parsing Error";
            };
        };

    private:
        double _vcTime;
        double _dqTime;
        std::vector<int> _vclist;
        std::deque<int> _dqlist;

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

};

#endif

/*
Data Structure:

std::vector: A dynamic array that stores elements in contiguous memory. This means that elements are adjacent in memory, which can lead to efficient caching and faster access times for sequential access.
std::deque (short for "double-ended queue"): Implemented as a collection of fixed-sized arrays (blocks) that can grow or shrink as needed. It provides fast insertion and removal at both ends but may not have contiguous memory.
Access Time:

std::vector: Provides fast access to elements by index (O(1)), thanks to contiguous memory. Random access is efficient.
std::deque: Also offers fast access by index (O(1)), but it may have slightly higher overhead compared to std::vector due to its block-based structure.
Insertion/Deletion Time:

std::vector: Insertions and deletions at the end of the container are efficient (amortized constant time). However, inserting or removing elements in the middle or at the beginning can be slow, especially for large vectors, as it may require moving many elements.
std::deque: Provides efficient insertions and deletions at both ends (beginning and end) in constant time. Insertions and deletions in the middle of the container can be slower than std::vector but still faster than many other data structures.
Memory Usage:

std::vector: Tends to be more memory-efficient than std::deque because it doesn't have the overhead of block management. However, it may waste some memory when resizing.
std::deque: Can be more memory-intensive than std::vector due to its block-based structure, which can result in memory fragmentation.
Use Cases:

Use std::vector when you need fast random access and most of the insertions/deletions are at the end of the container.
Use std::deque when you need efficient insertions and deletions at both ends of the container or when you need to insert/remove elements in the middle without the performance drawbacks of std::vector.

*/