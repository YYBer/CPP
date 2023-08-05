/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class Test{
    public:
        Test(void);
        ~Test(void);
        
    void    bar(void);
};

Test::Test(void)
{
    std::cout << "start" << std::endl;
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
    Test test;
    return (0);
}