/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:51:05 by yli               #+#    #+#             */
/*   Updated: 2023/10/11 17:44:18 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    ARRAY_HPP
#define    ARRAY_HPP

#include <iostream>
#include <exception>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <deque>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <iomanip>

template<typename T>
class Array
{
    public:
        Array(void):_arr(new T()), _size(0) {};
        Array(unsigned int n):_arr(new T[n]), _size(n) {};
        ~Array(void) {if (_size != 0)
                        delete [] _arr;
                    else
                        delete _arr;};
        Array(const Array& other):_arr(new T[other.size()]), _size(other.size()){
            for (unsigned int i = 0; i < _size; ++i)
                _arr[i] = other._arr[i];};
        Array& operator=(const Array& other){
            if (this != &other)
                delete []_arr;
            _arr = new T[other.size()];
            _size = other.size();
            for (unsigned int i = 0; i < _size; ++i)
                _arr[i] = other._arr[i];
            return *this;};
        unsigned int    size(void) const {return this->_size;};

        class OutOfBondsException: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return ("out of bonds");
                };};
        T& operator[](unsigned int i) const{
            if (i >= _size)
                throw OutOfBondsException();
            return _arr[i];};

    private:
        T*  _arr;
        unsigned int _size;
};
#endif

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
{
    for (unsigned int i = 0; i < arr.size(); ++i)
        out << arr[i] << " ";
    std::cout << std::endl;
    return out;
}


/*
can not use Array.cpp:
--argument list for class template "Array" is missing--
typically occurs when you are trying to define a member function of a class template outside of the class template definition, but you forget to provide the template argument list for the class.

In your code, you have defined the constructor Array::Array(void) outside the class template definition, but you haven't provided the template argument for the Array class. */