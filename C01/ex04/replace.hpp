/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:06:53 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 16:56:03 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

class Replace
{
    public:
        Replace(std::string filename);
        ~Replace(void);
        void ft_replace(std::string s1, std::string s2);
    
    private:
        std::string _infile;
        std::string _outfile;
        // char *_infile;
        // char *_outfile;
        
};

#endif