/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:16:54 by yli               #+#    #+#             */
/*   Updated: 2023/10/04 16:49:04 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp;
    return 0;
}

// int main()
// {
//     try{
//         Span sp = Span(5);
//         sp.addNumber(3);
//         sp.shortestSpan();
//         std::cout << sp;
//     } catch (const Span::NoNumber &e){
//         std::cerr << "Exception: " << e.what() << std::endl;
//     } catch (const Span::Full &e){
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//     return 0;
// }

// int main()
// {
//     try{
//         Span sp = Span(1);
//         sp.addNumber(3);
//         sp.addNumber(3);
//         sp.addNumber(3);
//         sp.shortestSpan();
//         std::cout << sp;
//     } catch (const Span::NoNumber &e){
//         std::cerr << "Exception: " << e.what() << std::endl;
//     } catch (const Span::Full &e){
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//     return 0;
// }