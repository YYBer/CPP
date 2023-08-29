/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:16:35 by yli               #+#    #+#             */
/*   Updated: 2023/08/29 19:47:32 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>

class Harl
{
    public:
        Harl(void);
        ~Harl(void);
        void    complain(std::string level);

    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};

#endif