#include "Serializer.hpp"

int main()
{
    Data *test = new Data();

    test->i = 42;

    std::cout << Serializer::deserialize(Serializer::serialize(test))->i << std::endl;
    std::cout << Serializer::serialize(Serializer::deserialize(test->i)) << std::endl;

    delete test;


    Data test1;

    test1.i = 42;

    std::cout << Serializer::deserialize(Serializer::serialize(&test1))->i << std::endl;
    std::cout << Serializer::serialize(Serializer::deserialize(test1.i)) << std::endl;

    std::cout << Serializer::deserialize(Serializer::serialize(&test1)) << std::endl;
    std::cout << &test1 << std::endl;
    return 0;

}