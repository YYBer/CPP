#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void	init(void);
		void	view(int index) const;
		void	display(int index) const;
	
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