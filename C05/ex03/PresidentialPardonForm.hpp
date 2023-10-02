/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:40 by yli               #+#    #+#             */
/*   Updated: 2023/10/02 21:51:51 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PresidentialPardonForm: Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.


#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
    PresidentialPardonForm(std::string name);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    AForm*   target(std::string const& target);
    void    execute(Bureaucrat const & executor) const;
};

#endif