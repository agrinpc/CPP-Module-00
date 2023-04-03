#include "./Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string number, std::string dark) : f_name(f_name), l_name(l_name), n_name(n_name), number(number), dark(dark) {}

Contact::~Contact() {}

std::string Contact::get_fname()
{
	return this->f_name;
}

std::string Contact::get_lname()
{
	return this->l_name;
}

std::string Contact::get_number()
{
	return this->number;
}

std::string Contact::get_nname()
{
	return this->n_name;
}

std::string Contact::get_dark()
{
	return this->dark;
}