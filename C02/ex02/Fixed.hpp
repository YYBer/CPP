/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:01:37 by yli               #+#    #+#             */
/*   Updated: 2023/08/24 23:08:38 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const int i);
        Fixed(const float i);
        Fixed(const Fixed& other);
        Fixed& operator = (const Fixed& other);
        ~Fixed(void);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void)   const;
        int     toInt(void) const;
    
        bool    operator > (const Fixed& other) const;
        bool    operator < (const Fixed& other) const;
        bool    operator >= (const Fixed& other) const;
        bool    operator <= (const Fixed& other) const;
        bool    operator == (const Fixed& other) const;
        bool    operator != (const Fixed& other) const;

        Fixed   operator + (const Fixed& other) const;
        Fixed   operator - (const Fixed& other) const;
        Fixed   operator * (const Fixed& other) const;
        Fixed   operator / (const Fixed& other) const;

        Fixed&  operator ++(void); //++i prefix
        Fixed   operator ++(int);  //i++ postfix
        Fixed&  operator --(void);
        Fixed   operator --(int);
        
        static Fixed&   min(Fixed& a, Fixed& b);
        static const Fixed&   min(const Fixed& a, const Fixed& b);
        static Fixed&   max(Fixed& a, Fixed& b);
        static const Fixed&   max(const Fixed& a, const Fixed& b);

    private:
        int                 _fixed;
        static const int    _fractionalBits = 8;
};

std::ostream & operator << (std::ostream & o, Fixed const & other);

#endif

//An overload of the insertion («) operator that inserts a floating-point representation
//of the fixed-point number into the output stream object passed as parameter.