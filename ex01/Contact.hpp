#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>

class Contact {
	private:
		std::string f_name;
		std::string l_name;
		std::string n_name;
		std::string number;
		std::string dark;

	public:
		Contact();
		Contact(std::string f_name, std::string l_name, std::string n_name, std::string number, std::string dark);

		~Contact();

		std::string get_fname();
		std::string get_lname();
		std::string get_nname();
		std::string get_number();
		std::string get_dark();
};
#endif