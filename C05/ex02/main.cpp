/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:08:49 by yli               #+#    #+#             */
/*   Updated: 2023/09/23 16:26:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int    main()
{

    try{
            Bureaucrat bu1("A1", 1);
            std::cout << std::endl << bu1 << std::endl<< std::endl;
            ShrubberyCreationForm sc1("blueberry");
            sc1.signAForm(bu1);
            bu1.executeForm(sc1);
            std::cout << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::AFormAlreadySignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch(const AForm::SignException& e)
    {
        std::cerr << "Exception: Form not signed" << e.what() << std::endl; 
    }   catch (const AForm::RightException& e)
    {
        std::cerr << "Exception: Bureaucrat does not have right to execute." << e.what() << std::endl;
    } catch (const ShrubberyCreationForm::FileException& e)
    {
        std::cerr << "can not open the outfile" << e.what() << std::endl;
    }

    try{
            Bureaucrat bu1("A1", 1);
            std::cout << std::endl << bu1 << std::endl<< std::endl;
            RobotmyRequestForm rr1("Tim");
            rr1.signAForm(bu1);
            bu1.executeForm(rr1);
            std::cout << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::AFormAlreadySignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch(const AForm::SignException& e)
    {
        std::cerr << "Exception: Form not signed" << e.what() << std::endl; 
    }   catch (const AForm::RightException& e)
    {
        std::cerr << "Exception: Bureaucrat does not have right to execute." << e.what() << std::endl;
    }

    try{
            Bureaucrat bu1("A1", 1);
            std::cout << std::endl << bu1 << std::endl<< std::endl;
            PresidentialPardonForm pr1("Tim");
            pr1.signAForm(bu1);
            bu1.executeForm(pr1);
            std::cout << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::AFormAlreadySignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch(const AForm::SignException& e)
    {
        std::cerr << "Exception: Form not signed" << e.what() << std::endl; 
    }   catch (const AForm::RightException& e)
    {
        std::cerr << "Exception: Bureaucrat does not have right to execute." << e.what() << std::endl;
    }
}