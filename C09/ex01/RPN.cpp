/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:21:39 by yli               #+#    #+#             */
/*   Updated: 2023/10/06 13:57:12 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string argv): _sum(0), _argv(argv) {}

RPN::~RPN(void) 
{
   if (_number.size() != 0)
      for (unsigned int i = 0; i < _number.size(); ++i)
         _number.pop();
}

RPN::RPN(const RPN& other)
{
   *this = other;
}

RPN&    RPN::operator=(const RPN& other)
{
   if (this != &other)
      for (unsigned int i = 0; i < _number.size(); ++i)
         _number.pop();
   this->_number = other._number;
   this->_sum = other._sum;
   this->_argv = other._argv;
   return *this;
}

bool  RPN::checkInput(void)
{
   for (unsigned int i = 0; i < _argv.size(); ++i)
   {
      if (_argv[i] != '+' && _argv[i] != '-' && _argv[i] != '*' && _argv[i] != '/'  
         &&  _argv[i] != '0' &&  _argv[i] != '1' &&  _argv[i] != '2' &&  _argv[i] != '3'&&  _argv[i] != '4' &&  _argv[i] != '5' &&  _argv[i] != '6'
         &&  _argv[i] != '7' &&  _argv[i] != '8' &&  _argv[i] != '9' &&  _argv[i] != ' ')
         return false;
   }
   for (unsigned int i = 1; i < _argv.size(); i += 2)
      if (_argv[i] != ' ')
         return false;
   if (_argv[0] < '0' || _argv[0] > '9')
      return false;
   return true;
}

int RPN::caculator(void)
{
   if (!checkInput())
      throw WrongArgument();
   _sum = _argv[0] - 48;
   for (unsigned int i = 1; i < _argv.size(); ++i)
   {
      if (_argv[i] >= '0' && _argv[i] <= '9')
         this->_number.push(_argv[i]);
      if (_argv[i] == '+' || _argv[i] == '-' || _argv[i] == '*' || _argv[i] == '/')
      {
         if (_argv[i] == '+')
         {
            if (!_number.size())
               throw WrongNumberOrToken();
            _sum += (_number.top() - 48);
         }
         else if (_argv[i] == '-')
         {
            if (!_number.size())
               throw WrongNumberOrToken();            
            _sum -= (_number.top() - 48);
         }
         else if (_argv[i] == '*')
         {
            if (!_number.size())
               throw WrongNumberOrToken();            
            _sum *= (_number.top() - 48);
         }
         else if (_argv[i] == '/')
         {
            if (!_number.size())
               throw WrongNumberOrToken(); 
            else if (_number.top() == '0')
               throw WrongArgument();
            _sum /= (_number.top() - 48);
         }
         _number.pop();
      }
   }
   
   if (_number.size())
      throw WrongNumberOrToken();
   return _sum;
}