/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:51 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 21:51:59 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//RobotomyRequestForm: Required grades: sign 72, exec 45
//Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.

#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

class RobotmyRequestForm: public AForm
{
    public:
    RobotmyRequestForm(std::string name);
    ~RobotmyRequestForm(void);
    RobotmyRequestForm(const RobotmyRequestForm& other);
    RobotmyRequestForm& operator=(const RobotmyRequestForm& other);
    void    execute(Bureaucrat const & executor) const;
    AForm*   target(std::string const& target);
};
#endif