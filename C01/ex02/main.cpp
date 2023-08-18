#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "memory address of the string variable " << &str << std::endl;
    std::cout << "memory address held by stringPTR: " << strPTR << std::endl;
    std::cout << "memory address held by stringREF: " << &strREF << std::endl;
    std::cout << "value of the string variable: " << str << std::endl;
    std::cout << "value pointed to by stringPTR: " << *strPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << strREF << std::endl;
}

//• stringPTR: A pointer to the string.
//• stringREF: A reference to the string.
