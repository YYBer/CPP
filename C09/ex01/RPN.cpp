/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:21:39 by yli               #+#    #+#             */
/*   Updated: 2023/10/14 15:48:46 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string argv): _argv(argv) {}

RPN::~RPN(void) 
{
   for (unsigned int i = 0; i < _stack.size(); ++i)
      _stack.pop();
}

RPN::RPN(const RPN& other)
{
   *this = other;
}

RPN&    RPN::operator=(const RPN& other)
{
   if (this != &other)
      for (unsigned int i = 0; i < _stack.size(); ++i)
         _stack.pop();
   this->_stack = other._stack;
   this->_argv = other._argv;
   return *this;
}

bool  RPN::checkInput1(void)
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

bool  RPN::checkInput2(void)
{
   int count1(0), count2(0);
   for (unsigned int i = 0; i < _argv.size(); ++i)
   {
      if (_argv[i] <= '9' && _argv[i] >= '0')
         count1++;
      else if (_argv[i] == '+' || _argv[i] == '-' || _argv[i] == '*' || _argv[i] == '/')
         count2++;
   }
   if (count1 - count2 != 1)
      return false;
   return true;
}
int RPN::caculator(void)
{
   if (!checkInput1())
      throw WrongArgument();
   if (!checkInput2())
      throw WrongNumberOrToken();
   _stack.push(_argv[0] - 48);
   for (unsigned int i = 2; i < _argv.size(); ++i)
   {
      if (_argv[i] >= '0' && _argv[i] <= '9')
         this->_stack.push(_argv[i] - 48);
      if (_argv[i] == '+' || _argv[i] == '-' || _argv[i] == '*' || _argv[i] == '/')
      {
         int sum(0);
         int n2 = _stack.top();
         _stack.pop();
         int n1 = _stack.top();
         _stack.pop();
         if (_argv[i] == '+')
         {
            sum = n1 + n2;
            _stack.push(sum);
         }
         else if (_argv[i] == '-')
         {         
            sum = n1 - n2;
            _stack.push(sum);
         }
         else if (_argv[i] == '*')
         {
            sum = n1 * n2;
            _stack.push(sum);
         }
         else if (_argv[i] == '/')
         {
            if (n2 == 0)
               throw WrongArgument();
            sum = n1 / n2;
            _stack.push(sum);
         }
      }
   }
   return _stack.top();
}