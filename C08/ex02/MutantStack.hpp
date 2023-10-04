/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:26:16 by yli               #+#    #+#             */
/*   Updated: 2023/10/04 17:30:47 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    MUTANTSTACK_HPP
#define    MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        MutantStack(void) {};
        ~MutantStack(void) {};
        MutantStack(const MutantStack& other){ *this = other;};
        MutantStack& operator=(const MutantStack& other) { (void) other; return *this;};
    
        typedef typename Container::iterator iterator;
        iterator    begin(){return this->c.begin();}
        iterator    end(){return this->c.end();}
};

#endif

/*
template<class T, class Container = std::deque<T>> class stack;
The std::stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.
The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. 
The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.

Template parameters
T	-	The type of the stored elements. The behavior is undefined if T is not the same type as Container::value_type.
Container	-	The type of the underlying container to use to store the elements. The container must satisfy the requirements of SequenceContainer. Additionally, it must provide the following functions with the usual semantics:
back()
push_back()
pop_back()
The standard containers std::vector (including std::vector<bool>), std::deque and std::list satisfy these requirements. By default, if no container class is specified for a particular stack class instantiation, the standard container std::deque is used.

*/

/*
template<typename T, class Container = std::deque<T>>:
T: This represents the type of elements that will be stored in the stack.
Container: This is the type of container that will be used internally to store the elements. 
By default, it uses std::deque<T>.

this->c.begin():
this->c syntax is used to access the underlying container of the std::stack class,
and you can use it to manipulate the container's elements or perform operations that require direct access to the container.
*/
