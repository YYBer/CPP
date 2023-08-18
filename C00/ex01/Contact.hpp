/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:53 by yli               #+#    #+#             */
/*   Updated: 2023/08/09 19:20:54 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
//#include <stdio.h>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void	init(void);
		void	view(int index) const;
		void	display(int index) const;
		void    setIndex(int i);
	
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _favmeal;
		int	_index;
	
		std::string	_printLen(std::string str) const;
		std::string _getInput(std::string str) const;
};
#endif