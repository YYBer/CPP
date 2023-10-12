#include "RPN.hpp"

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "invalid argument!" << std::endl;
        return (1);
    }
    try{
        RPN rpn(argv[1]);
        std::cout << rpn.caculator() << std::endl;
    } catch (const RPN::WrongArgument& e){
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const RPN::WrongNumberOrToken& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}


// ./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"