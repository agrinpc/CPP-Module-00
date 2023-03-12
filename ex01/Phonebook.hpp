#ifndef PHONE_H
# define PHONE_H
#include <iostream>
#include "./Contact.hpp"

class Phonebook {
	private:
		Contact contacts[8];
		int		size;

	public:
		Phonebook();

		~Phonebook();

		void	add(Contact cont);
		int	get_size();
		Contact *get_contacts();
};
#endif