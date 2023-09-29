#include <iostream>
#include <iostream>
#include <cstring>
#include <string>

int main()
{
    std::string str = "-42.0f";
    int i = atoi(str.c_str());
    float a = atof(str.c_str());
    double b = std::stod(str.c_str()); 
    std::cout << i << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}