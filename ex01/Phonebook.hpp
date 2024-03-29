#ifndef PHONE_H
# define PHONE_H
#include <iostream>
#include "./Contact.hpp"

class Phonebook {
	private:
		Contact contacts[8];
		int		size;
		int		cur;

	public:
		Phonebook();

		~Phonebook();

		void	add(Contact cont);
		int		get_size();
		Contact *get_contacts();
		void	print_all();
		void	print_one(int idx);
};

std::string	format_text(std::string s);
#endif