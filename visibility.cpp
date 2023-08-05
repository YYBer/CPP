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
    
        //Test(char p1, int p2, std::string p3);
        //Test(char a1, int a2, std::string a3);
        Test(void);
        ~Test(void);
        
        void    bar(void);
    private:
        int _privaten;

        void    _bar(void) const;
};

//Test::Test(char p1, int p2, std::string p3) : a1(p1), a2(p1), a3(p3)
//Test::Test(char a1, int a2, std::string a3)
Test::Test(void)
{
    this->a1 = 'd';
    this->a2 = 33;
    this->a3 = "hello";
    std::cout << "start" << std::endl;
    std::cout << "this->a1 = " << this->a1 << std::endl;
    std::cout << "this->a2 = " << this->a2 << std::endl;
    std::cout << "this->a3 = " << this->a3 << std::endl;
    std::cout << "this->_privaten = " << this->_privaten << std::endl;
    this->bar();
    this->_bar();
    return ;
}

Test::~Test(void)
{
    std::cout << "end" << std::endl;
    return ;
}

void    Test::bar(void)
{
    this->_privaten = 77;
   std::cout << "ohhhhh bar called" << std::endl;
   return ;
}

void    Test::_bar(void) const
{
    std::cout << "in private bar called" << std::endl;
    std::cout << "this->_privaten = " << this->_privaten << std:: endl;
}
int main()
{
    Test test;
    std::cout << "start solo" << std::endl;
    test.bar();
    return (0);
}