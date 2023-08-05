#include <iostream>

class Test{
    public:
        Test(void);
        ~Test(void);
};

Test::Test(void)
{
    std::cout << "start" << std::endl;
    return ;
}

Test::~Test(void)
{
    std::cout << "end" << std::endl;
    return ;
}

int main()
{
    Test test;
    return (0);
}