/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:26:23 by yli               #+#    #+#             */
/*   Updated: 2023/10/04 17:29:29 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout <<"iterator value: " << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    while(!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}

/*
std::stack::pop
void pop();
Remove top element
Removes the element on top of the stack, effectively reducing its size by one.

The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.

This calls the removed element's destructor.

This member function effectively calls the member function pop_back of the underlying container object.
*/