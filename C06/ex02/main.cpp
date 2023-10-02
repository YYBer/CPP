/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:40:04 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 20:12:55 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
   if (std::rand() % 3 == 0)
      return (new A);
   else if (std::rand() % 3 == 1)
      return (new B);
   else
      return (new C);   
}

void identify(Base* p)
{
   if (dynamic_cast<A*> (p))
      std::cout << "A\n";
   else if (dynamic_cast<B*> (p))
      std::cout << "B\n";
   else if (dynamic_cast<C*> (p))
      std::cout << "C\n";
   else
      std::cout << "Unknown type\n";
}

// void identify(Base& p)
// {
//    if (dynamic_cast<A*> (&p))
//       std::cout << "A\n";
//    else if (dynamic_cast<B*> (&p))
//       std::cout << "B\n";
//    else if (dynamic_cast<C*> (&p))
//       std::cout << "B\n";
//    else
//       std::cout << "Unknown type\n";
// } Using a pointer inside this function is forbidden!!

void identify(Base& p)
{
   try{
        A&  a = (dynamic_cast<A&> (p));
        std::cout << "A\n";
        (void) a;
   } catch (const std::exception& e){}  
   try{
        B&  b = (dynamic_cast<B&> (p));
        std::cout << "B\n";
        (void) b;
   } catch (const std::exception& e){}
   try{
        C&  c = (dynamic_cast<C&> (p));
        std::cout << "C\n";
        (void)c;
   } catch (const std::exception& e){}
}

int main()
{
    Base*   test1 = generate();
    Base*   test2 = generate();
    Base*   test3 = generate();
    
    identify(test1);
    identify(test2);
    identify(test3);
    std::cout << "-----------------------" << std::endl;
    identify(*test1);
    identify(*test2);
    identify(*test3);

    delete test1;
    delete test2;
    delete test3;
}

/*
If expression is a pointer or reference to a polymorphic type Base, and target-type is a pointer or reference to the type Derived a runtime check is performed:
a) The most derived object pointed/identified by expression is examined. If, in that object, expression points/refers to a public base of Derived, and if only one object of Derived type is derived from the subobject pointed/identified by expression, then the result of the cast points/refers to that Derived object. (This is known as a "downcast".)
b) Otherwise, if expression points/refers to a public base of the most derived object, and, simultaneously, the most derived object has an unambiguous public base class of type Derived, the result of the cast points/refers to that Derived (This is known as a "sidecast".)
c) Otherwise, the runtime check fails. If the dynamic_cast is used on pointers, the null pointer value of type target-type is returned. If it was used on references, the exception std::bad_cast is thrown.*/