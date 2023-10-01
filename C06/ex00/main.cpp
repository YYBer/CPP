#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter sc(argv[1]);
        return 0;
    }
    std:: cout << "wrong argument!" << std::endl;
}