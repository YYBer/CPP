/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:49 by yli               #+#    #+#             */
/*   Updated: 2023/09/11 17:24:26 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int    main()
{
    // try{
    //   Bureaucrat bu1("A1", 150);
    //   std::cout << "1: " << bu1 << std::endl;
    //   bu1.decrement();
    //   std::cout << "2: "<< bu1 << std::endl;
    //   bu1.increment();
    //   std::cout << "3: "<< bu1 << std::endl;
    //   bu1.increment();
    //   std::cout << "4: "<< bu1 << std::endl;
    //   bu1.decrement();
    //   std::cout << "5: "<< bu1 << std::endl;
    // } catch (const Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // } catch (const Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // try{
    //   Bureaucrat bu3("A3", 1);
    //   std::cout << "1: " << bu3 << std::endl;
    //   bu3.increment();
    //   std::cout << "2: "<< bu3 << std::endl;
    //   bu3.decrement();
    //   std::cout << "3: "<< bu3 << std::endl;
    //   bu3.decrement();
    //   std::cout << "4: "<< bu3 << std::endl;
    // } catch (const Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // } catch (const Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    Bureaucrat bu1("A1", 3);
    std::cout << std::endl << bu1 << std::endl << std::endl;
    Form fo1("F1", 2, 2);
    std::cout << "F1: " << fo1 << std::endl << std::endl;
    fo1.signForm(bu1);
    std::cout << std::endl << "F1: " << fo1 << std::endl;
    std::cout << std::endl << "---------" << std::endl;
    Bureaucrat bu2("A2", 3);
    std::cout << std::endl << bu2 << std::endl << std::endl;
    Form fo2("F2", 3, 3);
    std::cout << "F1: " << fo2 << std::endl << std::endl;
    fo2.signForm(bu2);
    std::cout << std::endl << "F2: " << fo2 << std::endl;
}