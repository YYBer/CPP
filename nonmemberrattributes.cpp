#include <iostream>

class Test{
    public:
        Test(void);
        ~Test(void);

    static int getNumber(void);

    private:
        static int _nNumber;
};

Test::Test(void)
{
    Test::_nNumber += 1;
    std::cout << "start " << Test::_nNumber << std::endl;
    return ;
}

Test:: ~Test(void)
{
    Test::_nNumber -= 1;
    std::cout << Test::_nNumber << "end " << std::endl;
    return ;
}

int Test::getNumber()
{
    return Test::_nNumber;
}

int Test::_nNumber = 10;

void ft0(void)
{
    Test test;

    std::cout << test.getNumber() << std::endl;
    return ;
}

void    ft1(void)
{
    Test test;
    std::cout << test.getNumber() << std::endl;
    ft0();
    return ;
}


int main()
{
   Test test;

    std::cout << "start ft0" << std::endl;
    ft0();
    std::cout << "start ft1" << std::endl;
    ft1();
}