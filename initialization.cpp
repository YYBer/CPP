/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class Test{
    public:
        char a1;
        int a2;
        std::string a3;
    
        Test(char p1, int p2, std::string p3);
        ~Test(void);
        
    void    bar(void);
};

Test::Test(char p1, int p2, std::string p3) : a1(p1), a2(p2), a3(p3)
{
    std::cout << "start" << std::endl;
    std::cout << "a1 = " << a1 << std::endl;
    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "a3 = " << a3 << std::endl;
    this->bar();
    return ;
}

Test::~Test(void)
{
    std::cout << "end" << std::endl;
    return ;
}

void    Test::bar(void)
{
   std::cout << "bar called" << std::endl;
   return ;
}

int main()
{
    Test test('z', 55, "abc");
    return (0);
}