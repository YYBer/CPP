#include <iostream>

class Test{
    public:
    
        Test(void);
        ~Test(void);

        int getNumer(void) const;
        void    setNumber (int n);
    private:

        int _n;
};

Test::Test(void)
{

    this->setNumber(0);
    std::cout << "start" << std::endl;
    std::cout << "this->getNumer = " << this->getNumer() << std::endl;

    return ;
}

Test::~Test(void)
{
    std::cout << "end" << std::endl;
    return ;
}

int Test::getNumer(void) const{
    return this->_n;
}

void    Test::setNumber(int n)
{
    if ( n >= 0)
        this->_n = n;
    else
        this->_n = -100;
    return ;
}

int main ()
{
    Test test;

    test.setNumber(42);
    std::cout << "test.getNumer() = " << test.getNumer() << std::endl;
    test.setNumber(-5);
    std::cout << "test.getNumer() = " << test.getNumer() << std::endl;
    return 0;
}