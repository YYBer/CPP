/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:14 by yli               #+#    #+#             */
/*   Updated: 2023/08/24 19:02:59 by yli              ###   ########.fr       */
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
        float   toFloat(void) const;
        int     toInt(void) const;
    
    private:
        int              _fixed;
        static const int _fractionalBit = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.