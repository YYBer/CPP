#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 3001)
    {
        std::cerr << "wrong arguments\n";
        return 1;
    }
    PmergeMe pm(argc, argv);
}