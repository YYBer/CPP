#include <iostream>

int main ()
{
    std::string s1 = "aaa";
    std::string s2 = "bbb";
    std::string s3 = "abc";
    //std::cout << s1+s2 << std::endl;
    std::cout << s1.substr(0, 1) << std::endl; //a
    //std::cout << s1.replace(0, 1, s2) << std::endl; //bbbaa
    //std::cout << s1.insert(2, s2) << std::endl; //aabbba
    std::cout << s3.find('c') << std::endl ;
    std::cout << s3.at(2) << std::endl;
    return 0;
}