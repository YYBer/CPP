/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:49 by yli               #+#    #+#             */
/*   Updated: 2023/09/23 11:52:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int    main()
{
    try{
            Bureaucrat bu1("A1", 3);
            std::cout << std::endl << bu1 << std::endl<< std::endl;
            Form fo1("F1", 2, 2);
            std::cout << "F1: " << fo1 << std::endl<< std::endl;
            fo1.signForm(bu1);
            std::cout << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Form::FormAlreadySignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "---------" << std::endl;
    

    try{
            Bureaucrat bu2("A2", 3);
            std::cout << std::endl << bu2 << std::endl << std::endl;
            Form fo2("F2", 3, 3);
            std::cout << "F2: " << fo2 << std::endl << std::endl;
            fo2.signForm(bu2);
            std::cout << std::endl << "F2: " << fo2 << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Form::FormAlreadySignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}