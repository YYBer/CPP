#include <iostream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

int main()
{
    std::string str = "-4F";
    int i = atoi(str.c_str());
    float a = atof(str.c_str());
    double b = std::stod(str.c_str()); 
    std::cout << std::fixed << std::setprecision(1);
    std::cout << i << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    if (isdigit(atoi(str.c_str())))
        std::cout << "true\n";
    std::cout << "false\n";
}