/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:22:01 by yli               #+#    #+#             */
/*   Updated: 2023/10/12 20:21:44 by yli              ###   ########.fr       */
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
        int bunchcaculator(std::string& line);
        int caculator(void);
        bool  checkInput(void);
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
        int _sum;
        std::string _argv;
        std::stack<char> _number;
};

#endif
