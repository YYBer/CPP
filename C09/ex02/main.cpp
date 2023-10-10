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