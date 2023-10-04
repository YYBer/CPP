/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:16:57 by yli               #+#    #+#             */
/*   Updated: 2023/10/04 16:48:24 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _n(n) {}//std::cout << "_n: " << _n << std::endl;}

Span::~Span(void)
{
   container.clear();
}

Span::Span(const Span& other)
{
   this->container = other.container;
   *this = other;
}

Span&    Span::operator=(const Span& other)
{
   if (this != &other)
      this->container.clear();
   this->_n = other._n;
   this->container = other.container;
   return *this;
}

void  Span::addNumber(unsigned int i)
{
   if (container.size() == _n)
         throw Full();
   this->container.push_back(i);
}

unsigned int Span::shortestSpan(void)
{
   if (container.size() == 0 || container.size() == 1)
      throw NoNumber();
   unsigned int tmp = container[0];
   for(size_t i = 1; i < container.size(); ++i)
   {
      if (tmp > container[i])
         tmp = container[i];
   }
   return tmp;
}
unsigned int Span::longestSpan(void)
{
   if (container.size() == 0 || container.size() == 1)
      throw NoNumber();
   unsigned int tmp = container[0];
   for(size_t i = 1; i < container.size(); ++i)
   {
      if (tmp < container[i])
         tmp = container[i];
   }
   return tmp;   
}

const std::vector<unsigned int>& Span::getContainer(void) const
{
   return this->container;
}

std::ostream& operator<<(std::ostream& o, const Span& other)
{
   o << "whole array: \n";
   for (size_t i = 0; i < other.getContainer().size(); ++i)
      o << other.getContainer()[i] << " ";
   o << std::endl;
   return o;
}

//if give a negative number, _n will be set as 4294967291.
