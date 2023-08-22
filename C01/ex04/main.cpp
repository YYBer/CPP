/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:06:46 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 16:56:51 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "wrong arguments!" << std::endl;
        return (1);
    }
    else
    {        
        Replace re(argv[1]);
        re.ft_replace(argv[2], argv[3]);
    }
    return (0);
}