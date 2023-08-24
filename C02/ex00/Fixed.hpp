/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:14 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 21:11:40 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator = (const Fixed& other);
        ~Fixed(void);
        int getRawBits(void) const;
        void    setRawBits(int const raw);
    
    private:
        int _fixed;
        static const int _fixedBits = 8;
};

#endif