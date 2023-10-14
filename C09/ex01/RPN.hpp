/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:22:01 by yli               #+#    #+#             */
/*   Updated: 2023/10/14 13:16:24 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    RPN_HPP
#define    RPN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <stack>

class RPN
{
    public:
        RPN(std::string argv);
        ~RPN(void);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        int caculator(void);
        bool  checkInput1(void);
        bool  checkInput2(void);
        class WrongArgument: public std::exception{
            public:
                virtual const char* what() const throw()
                {
                    return "wrong Argument.";};};
        class WrongNumberOrToken: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "don't have enough number/token.";};};

    private:
        std::string _argv;
        std::stack<int> _stack;
};

#endif
