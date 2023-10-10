#ifndef    PMERGEME_HPP
#define    PMERGEME_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <deque>
#include <cstdlib>
#include <climits>


class PmergeMe
{
    public:
        PmergeMe(int argc ,char**argv);
        ~PmergeMe(void);
        void    printResult(void);
        void    printOutvc(const std::vector<int>& list);
        // void    printOutdq(void);
        bool    validInput(int argc, char **argv);
        void    vclistSort1(void);
        void    vclistSort2(void);
        void    vcMerge(int i, std::vector<int>& up);
        void    implementCentre(int argc, char **argv);
        // std::string convertTime(const time_t& diff);
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
        std::string _vcTime;
        std::string _dqTime;
        std::vector<int> _vclist;
        std::deque<int> _dqlist;

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

};

#endif

// The storage of a deque is automatically expanded and contracted as needed.
// Expansion of a deque is cheaper than the expansion of a std::vector because it does not involve copying of the existing elements to a new memory location. 
// On the other hand, deques typically have large minimal memory cost; 
// a deque holding just one element has to allocate its full internal array (e.g. 8 times the object size on 64-bit libstdc++; 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++).


// Split the collection in n/2
//  pairs of 2
//  elements and order these elements pairwise. If the number of elements is odd, the last element of the collection isn't paired with any element.

// Recursively sort the pairs of elements by their highest value. If the number of elements is odd, the last element is not considered a highest value and is left at the end of the collection. Consider that the highest values form a sorted list that we will call the main chain while the rest of the elements will be known as pend elements. Tag the elements of the main chain with the names a1,a2,a3,...,an/2
//  then tag the pend elements with the names b1,b2,b3,...,bn/2
// . For every k
// , we have the relation bk≤ak
// .

// Insert the pend elements into the main chain. We know that the first pend element b1
//  is lesser than a1
// ; we consider it to be part of the main chain which then becomes {b1,a1,a2,a3,...,an/2}
// . Now, we need to insert the other pend elements into the main chain in a way that ensures that the size of the insertion area is a power of 2
//  minus 1
//  as often as possible. Basically, we will insert b3
//  in {b1,a1,a2}
//  (we know that it is less than a3
// ), then we will insert b2
//  into {b1,a1,b3}
//  no matter where b3
//  was inserted. Note that during these insertions, the size of the insertion area is always at most 3.

// The value of the next pend element bk
//  to insert into the main chain while minimizing the number of comparisons actually corresponds to the next Jacobsthal number. We inserted the element 3
//  first, so the next will be 5
//  then 11
//  then 21
// , etc...

// To sum up, the insertion order of the first pend elements into the main chain is as follows: b1,b3,b2,b5,b4,b11,b10,b9,b8,b7,b6,...
// .