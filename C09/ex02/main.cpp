#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 3001)
    {
        std::cerr << "wrong arguments\n";
        return 1;
    }
    try {
        PmergeMe pm(argc, argv);
    } catch (const PmergeMe::InvalidInput &e){
        std::cerr << e.what() << std::endl;
    } catch (const PmergeMe::ParsingError &e){
        std::cerr << e.what() << std::endl;
    }
}

//4 14 8 7 3 19 6 5 22 45 78 11 36 

//3 1 2 4 6 44 12 32 11 67 90