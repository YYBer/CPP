/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:17:00 by yli               #+#    #+#             */
/*   Updated: 2023/10/04 16:11:36 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    SPAN_HPP
#define    SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

class Span
{
    public:
        Span(unsigned int n);
        ~Span(void);
        Span(const Span& other);
        Span& operator=(const Span& other);
        void    addNumber(unsigned int i);
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);
        const std::vector<unsigned int>& getContainer(void) const;
        class   Full: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "I'm full!";
                };};
        class   NoNumber: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "no number stored";
                };};
    private:
        std::vector<unsigned int> container;
        unsigned int _n;
};

std::ostream& operator<<(std::ostream& o, const Span& other);

#endif
